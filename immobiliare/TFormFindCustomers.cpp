/*!****************************************************************************

	@file	TFormFindCustomers.h
	@file	TFormFindCustomers.cpp

	@brief	Find Customers form

	@noop	author:	Francesco Settembrini
	@noop	last update: 8/11/2021, 28/11/2021
	@noop	e-mail:	mailto:francesco.settembrini@poliba.it

******************************************************************************/

#include <vcl.h>
#pragma hdrstop

#include <algorithm>

//#include "TFormMain.h"
#include "TFormDebug.h"
#include "TFormCustomers.h"
#include "TFormFindCustomers.h"

#include "utils.h"
#include "assets.h"
#include "errormsgs.h"
#include "commdefs.h"

#include "sorting.h"

using namespace sort;


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


//---------------------------------------------------------------------------

#define MINWIDTH 	720
#define MINHEIGHT	440
#define DEFWIDTH	900

#define DEFCOLS		9
#define DEFROWS		2
#define DEFCOLW		48
#define DEFCOLH     16

#define _USECUSTOMSORT


struct TOwnershipChoice
{
	AnsiString strName;
    enCustomerOwnershipType nType;
} static g_OwnershipChoices[] =
{
	{"", cotNone},
    {" for rent", cotForRent},
    {" for purchase", cotForPurchase}
};


enum enSortingMode { smNone = 0,
	smFirstNameAsc, smFirstNameDesc,
    smLastNameAsc, smLastNameDesc,
    smCityAsc, smCityDesc,
    smBudgetAsc, smBudgetDesc };

struct TSortingChoice
{
	AnsiString strName;
    enSortingMode nMode;
} static g_SortingChoices[] =
{
	{"", smNone},
    {" first name, ascending", smFirstNameAsc},
    {" first name, descending", smFirstNameDesc},
    {" last name, ascending", smLastNameAsc},
    {" last name, descending", smLastNameDesc},
	{" city, ascending", smCityAsc},
	{" city, decending", smCityDesc},
    {" budget, ascending", smBudgetAsc},
    {" budget, descending", smBudgetDesc}
};


/*!****************************************************************************
* @brief	Constructor
******************************************************************************/
__fastcall TFormFindCustomers::TFormFindCustomers(TComponent* Owner,
	TDataBanker* const pDB, HWND hWndMsgs) : TForm(Owner)
{
	assert(pDB);

	m_pDB = pDB;
	m_hWndMsgs = hWndMsgs;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindCustomers::FormCreate(TObject *Sender)
{
	Setup();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindCustomers::Setup()
{
	assert(m_pDB);

	Caption = AnsiString(APPNAME) + " - Find Customers";
    Position = poScreenCenter;

	Width = DEFWIDTH;
    Constraints->MinWidth = MINWIDTH;
	Constraints->MinHeight = MINHEIGHT;
    //Constraints->MaxHeight = MINHEIGHT;

										// build the grid (spreadsheet)
    SetupTheGrid();
										// build the "cities" combobox
	TVecCities Cities;
	m_pDB->GetCities(Cities);
    assert(Cities.size());

    for(int i=0; i<Cities.size(); i++)
    {
		ComboBoxCity->Items->Add(Cities[i].m_strName.c_str());
    }
	ComboBoxCity->Text = "";

										// build the ownership choice combobox
	for(int i=0; i<sizeof(g_OwnershipChoices)/sizeof(g_OwnershipChoices[0]); i++)
    {
		ComboBoxOwnership->Items->Add( g_OwnershipChoices[i].strName );
    }
	ComboBoxOwnership->ItemIndex = 0;

										// build the sorting choice combobox
	for(int i=0; i<sizeof(g_SortingChoices)/sizeof(g_SortingChoices[0]); i++)
    {
		ComboBoxSorting->Items->Add( g_SortingChoices[i].strName);
    }
	ComboBoxSorting->ItemIndex = smNone;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindCustomers::SpeedButtonFindClick(TObject *Sender)
{
	ClearTheGrid();
    DoQuery();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindCustomers::ButtonCloseClick(TObject *Sender)
{
	ModalResult = mrOk;
    Close();
}

/*!****************************************************************************
* @brief 	Setup of the grid UI control
******************************************************************************/
void __fastcall TFormFindCustomers::SetupTheGrid()
{
	int nRows = DEFROWS;
	int nCols = DEFCOLS;

	Grid->ScrollBars = ssBoth;
	Grid->DrawingStyle = gdsClassic;	// vip, altrimenti non imposta i colori

	Grid->DoubleBuffered = true;

	Grid->RowCount = nRows;
    Grid->ColCount = nCols;
	Grid->FixedRows = 1;
    Grid->FixedCols = 1;

	Grid->DefaultColWidth = DEFCOLW;
    Grid->DefaultRowHeight = DEFCOLH;

    Grid->Options << goColSizing << goRowSizing
    	<< goDrawFocusSelected << goRangeSelect
        << goRowMoving << goColMoving << goRowSelect;

	Grid->Options >> goEditing;


	Grid->Font->Name = "tahoma";
    Grid->Font->Size = 10;

    Grid->FixedColor = clActiveCaption;
    Grid->Color = clMoneyGreen;

	Grid->Cells[0][0] = "";
	Grid->Cells[1][0] = "first name";
	Grid->Cells[2][0] = "last name";
    Grid->Cells[3][0] = "city";
    Grid->Cells[4][0] = "address";
    Grid->Cells[5][0] = "ownership";
	Grid->Cells[6][0] = "budget";
    Grid->Cells[7][0] = "phone";
	Grid->Cells[8][0] = "email";

    Grid->ColWidths[1] = 128;
	Grid->ColWidths[2] = 128;
    Grid->ColWidths[3] = 150;
    Grid->ColWidths[4] = 200;
	Grid->ColWidths[5] = 96;
	Grid->ColWidths[6] = 96;
	Grid->ColWidths[7] = 96;
    Grid->ColWidths[8] = 256;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindCustomers::SpeedButtonClearClick(TObject *Sender)
{
	Clear();
}

/*!****************************************************************************
* @brief	Clears the UI controls
******************************************************************************/
void __fastcall TFormFindCustomers::Clear()
{
	EditFirstName->Text = "";
    EditLastName->Text = "";
	EditBudget->Text = "";

    ComboBoxCity->Text = "";
    ComboBoxOwnership->ItemIndex = 0;
    ComboBoxSorting->ItemIndex = 0;

    ClearTheGrid();

    LabelInfo->Caption = "";
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindCustomers::ClearTheGrid()
{
	Grid->RowCount = DEFROWS;

    for(int i=0; i<=Grid->ColCount; i++)
    {
		Grid->Cells[i][1] = "";
    }
}

/*!****************************************************************************
* @brief	Executes the query according to the values of UI controls
******************************************************************************/
void __fastcall TFormFindCustomers::DoQuery()
{
	assert(m_pDB);

    TCustomersArchive* pCustomers = m_pDB->GetCustomers();
    assert(pCustomers);

    m_QueryCustomers = pCustomers->GetCustomers();


    if( m_QueryCustomers.size() )
    {
											// filter by first name
		std::string strFirstName = AnsiString(EditFirstName->Text).c_str();
		if( strFirstName.length() )
        {
			FilterByFirstName(m_QueryCustomers,
            	strFirstName, CheckBoxFirstNameFullMatch->Checked);
        }
											// filter by last name
		std::string strLastName = AnsiString(EditLastName->Text).c_str();
		if( strLastName.length() )
        {
			FilterByLastName(m_QueryCustomers,
            	strLastName, CheckBoxLastNameFullMatch->Checked);
        }
											// filter by city
        std::string strCity = AnsiString(ComboBoxCity->Text).c_str();
		if( strCity.length() )
        {
			FilterByCity(m_QueryCustomers,
            	strCity, CheckBoxCityNameFullMatch->Checked);
        }
        									// filter by ownership
        enCustomerOwnershipType nOwnership = g_OwnershipChoices[ ComboBoxOwnership->ItemIndex ].nType;

        if( nOwnership != cotNone )
        {
			FilterByOwnership(m_QueryCustomers, nOwnership);
        }
											// filter by budget
		std::string strBudget = AnsiString(EditBudget->Text).c_str();
        if( strBudget.length() )
        {
			int nBudget = EditBudget->Text.ToInt();
            FilterByBudget(m_QueryCustomers,
            	nBudget, AnsiString(ComboBoxBudgetIneq->Text).c_str());
        }

											// if query results contains records
        if( m_QueryCustomers.size() )
        {
                                            // sorts (eventually) result records
            switch( g_SortingChoices[ComboBoxSorting->ItemIndex].nMode )
            {
				case smFirstNameAsc: SortByFirstName(m_QueryCustomers, true); break;
                case smFirstNameDesc: SortByFirstName(m_QueryCustomers, false); break;
                case smLastNameAsc: SortByLastName(m_QueryCustomers, true); break;
                case smLastNameDesc: SortByLastName(m_QueryCustomers, false); break;
				case smCityAsc: SortByCity(m_QueryCustomers, true); break;
				case smCityDesc: SortByCity(m_QueryCustomers, false); break;
                case smBudgetAsc: SortByBudget(m_QueryCustomers, true); break;
                case smBudgetDesc: SortByBudget(m_QueryCustomers, false); break;
            }

			PrintResults(m_QueryCustomers);
        }

        AnsiString strTemp;
        strTemp.sprintf(
            "  Result: %d record(s) found.  Double click to edit the record. ",
            m_QueryCustomers.size());
        LabelInfo->Caption = strTemp;
	}
	else
    {
		ShowErrorMsg(ERR_DBEMPTYCUSTOMERS, emtWarning);
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindCustomers::PrintResults(TVecPtrCustomers& Customers)
{
	int nCols = 5;
	int nRows = Customers.size();

	AnsiString strTemp;
    Grid->RowCount = nRows + 1;

    for(int i=0; i<nRows; i++)
    {
		TCustomer* pCustomer = Customers[i];
        assert(pCustomer);

											// row number
		Grid->Cells[0][i+1] = i+1;

											// first name
		Grid->Cells[1][i+1] = pCustomer->m_strFirstName;

											// last name
		Grid->Cells[2][i+1] = pCustomer->m_strLastName;

											// city
		Grid->Cells[3][i+1] = pCustomer->m_strCity;

											// address
		Grid->Cells[4][i+1] = pCustomer->m_strAddress;

											// ownership
		Grid->Cells[5][i+1] = g_OwnershipChoices[pCustomer->m_nOwnership].strName;

        									// budget
		Grid->Cells[6][i+1] = pCustomer->m_nBudget;

                                            // phone number
		Grid->Cells[7][i+1] = pCustomer->m_strPhone;

                                            // email
		Grid->Cells[8][i+1] = pCustomer->m_strEmail;
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindCustomers::GridDblClick(TObject *Sender)
{
/*
	if( m_QueryAssets.size() )
    {
        EditRecord(m_QueryAssets, Grid->Row - 1);
	}
*/
	if( m_QueryCustomers.size() )
    {
		EditRecord(m_QueryCustomers, Grid->Row - 1);
    }
}

void __fastcall TFormFindCustomers::EditRecord(TVecPtrCustomers& Customers, int nGridSelRow)
{
    assert(m_pDB);
	//assert(FormMain);

    //unsigned nRow = Grid->Row - 1, nRecId = -1;

    TCustomersArchive* pCustomers = m_pDB->GetCustomers();
    assert(pCustomers);
                                        // poiche' m_QueryResult puo' essere
                                        // stato filtrato il numero di riga
                                        // della grid (tabella) puo' NON
                                        // corrispondere piu' alla posizione
                                        // del Tasset nel vettore m_QueryResult
                                        // per cui bisogna recuperarlo per il
                                        // tramite del suo puntatore (TAsset*)

	unsigned nRecId = 0;

    if( pCustomers->GetRecordId( m_QueryCustomers[nGridSelRow], nRecId) )
    {
        //TFormCustomers *pFormCustomers = FormMain->GetFormCustomers();
        //assert(pFormCustomers);
        //pFormCustomers->SetCurRecord(nRecId);
        //pFormCustomers->ShowModal();

		if( m_hWndMsgs )
        {
            TFormCustomers* pFormCustomers = NULL;

            ::SendMessage(m_hWndMsgs, UM_GETFORMCUSTOMERS, (WPARAM)(LPVOID) &pFormCustomers, 0);

            if( pFormCustomers )
            {
                pFormCustomers->SetCurRecord(nRecId);
                pFormCustomers->ShowModal();
                								// update the grid
				DoQuery();
                Grid->Row = nGridSelRow + 1;
            }
        }

    }
    else
    {
        ShowErrorMsg(ERR_DBRECORDNOTFOUND);
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindCustomers::FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize)
{
	ButtonClose->Left = (this->Width - ButtonClose->Width)/2;
}


