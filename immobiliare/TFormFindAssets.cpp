/*!****************************************************************************

	@file	TFormFindAssets.h
	@file	TFormFindAssets.cpp

	@brief	Find Assets form

	@noop	author:	Francesco Settembrini
	@noop	last update: 8/11/2021, 28/11/2021
	@noop	e-mail:	mailto:francesco.settembrini@poliba.it

******************************************************************************/

#include <vcl.h>
#pragma hdrstop

#include <algorithm>

//#include "TFormMain.h"
#include "TFormDebug.h"
#include "TFormAssets.h"
#include "TFormFindAssets.h"

#include "utils.h"
#include "assets.h"
#include "errormsgs.h"
#include "commdefs.h"
#include "databanker.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


//---------------------------------------------------------------------------

#define MINWIDTH 	720
#define MINHEIGHT	500
#define DEFWIDTH	900

#define DEFCOLS		14
#define DEFROWS		2
#define DEFCOLW		48
#define DEFCOLH     16



//---------------------------------------------------------------------------

struct TAssetTypeChoice
{
	AnsiString strName;
    enAssetTypology nTypology;
} static g_AssetTypologyChoices[] =
{
	{"", atNone},
    {"terreno", atTerrain},
    {"garage", atGarage},
    {"villa", atVilla},
    {"appartamento", atApartment},
    {"ufficio", atOffice},
    {"negozio", atCommercial},
    {"capannone", atIndustrial}
};

struct TAssetStatusChoice
{
	AnsiString strName;
	enAssetStatus nStatus;
} static g_AssetStatusChoices[] =
{
	{" ", asNone},
	{"for rent", asForRent},
    {"rented", asRented},
    {"for sale", asForSale},
    {"sold out", asSoldOut}
};

struct TEpglChoice
{
	AnsiString strName;
    enAssetEpgl nEpgl;
} static g_AssetEpglChoices[] =
{
	{" ", aeNone},
    {"G", aeG},
    {"F", aeF},
    {"E", aeE},
    {"D", aeD},
    {"C", aeC},
    {"B", aeB},
    {"A4", aeA4},
    {"A3", aeA3},
    {"A2", aeA2},
    {"A1", aeA1}
};

enum enSortingMode { smNone = 0,
	smCityAsc, smCityDesc, smValueAsc, smValueDesc, smAreaAsc, smAreaDesc };

struct TSortingChoice
{
	AnsiString strName;
    enSortingMode nMode;
} g_SortingChoices[] =
{
	{"", smNone},
	{" city, ascending", smCityAsc},
	{" city, decending", smCityDesc},
    {" price, ascending", smValueAsc},
    {" price, descending", smValueDesc},
    {" area, ascending", smAreaAsc},
    {" area, descending", smAreaDesc}
};


/*!****************************************************************************
* @brief	Constructor
******************************************************************************/
__fastcall TFormFindAssets::TFormFindAssets(TComponent* Owner,
	TDataBanker* const pDB, HWND hWndMsgs) : TForm(Owner)
{
	assert(pDB);

	m_pDB = pDB;
	m_hWndMsgs = hWndMsgs;
}

/*!****************************************************************************
* @brief	Event fired by UI when creating the form
* @param	Sender Pointer to a UI sender object
******************************************************************************/
void __fastcall TFormFindAssets::FormCreate(TObject *Sender)
{
	Setup();
}

/*!****************************************************************************
* @brief	Setup
******************************************************************************/
void __fastcall TFormFindAssets::Setup()
{
	assert(m_pDB);

	Caption = AnsiString(APPNAME) + " - Find Assets";
    Position = poScreenCenter;

	Width = DEFWIDTH;
    Constraints->MinWidth = MINWIDTH;
	Constraints->MinHeight = MINHEIGHT;

										// build the grid (spreadsheet)
    SetupTheGrid();

										// build the "typology" combobox
    for(int i=0; i<sizeof(g_AssetTypologyChoices)/sizeof(g_AssetTypologyChoices[0]); i++)
    {
		ComboBoxTypology->Items->Add(g_AssetTypologyChoices[i].strName);
    }
	ComboBoxTypology->ItemIndex = atNone;

										// build the "cities" combobox
	TVecCities Cities;
	m_pDB->GetCities(Cities);
    assert(Cities.size());

    for(int i=0; i<Cities.size(); i++)
    {
		ComboBoxCity->Items->Add(Cities[i].m_strName.c_str());
    }
	ComboBoxCity->Text = "";

										// build the "ownership" combobox
	for(int i=0; i<sizeof(g_AssetStatusChoices)/sizeof(g_AssetStatusChoices[0]); i++)
    {
		ComboBoxStatus->Items->Add(g_AssetStatusChoices[i].strName);
    }
	ComboBoxStatus->ItemIndex = asNone;

										// cnergetic class (EPGL) combobox
	for(int i=0; i<sizeof(g_AssetEpglChoices)/sizeof(g_AssetEpglChoices[0]); i++)
    {
		ComboBoxEpgl->Items->Add( g_AssetEpglChoices[i].strName);
    }
	ComboBoxEpgl->ItemIndex = aeNone;

										// ordering choice combobox
	for(int i=0; i<sizeof(g_SortingChoices)/sizeof(g_SortingChoices[0]); i++)
    {
		ComboBoxSorting->Items->Add( g_SortingChoices[i].strName);
    }
	ComboBoxSorting->ItemIndex = smNone;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindAssets::ButtonCloseClick(TObject *Sender)
{
	ModalResult = mrOk;
    Close();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindAssets::SpeedButtonFindClick(TObject *Sender)
{
	ClearTheGrid();
    DoQuery();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindAssets::FormCanResize(TObject *Sender,
	int &NewWidth, int &NewHeight, bool &Resize)
{
	ButtonClose->Left = (Width - ButtonClose->Width)/2;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindAssets::SpeedButtonClearClick(TObject *Sender)
{
	Clear();
}

/*!****************************************************************************
* @brief	Clears the UI controls
******************************************************************************/
void __fastcall TFormFindAssets::Clear()
{
    ComboBoxEpgl->ItemIndex = 0;
    ComboBoxTypology->ItemIndex = 0;
    ComboBoxStatus->ItemIndex = 0;
    ComboBoxSorting->ItemIndex = 0;

    EditPrice->Clear();
    ComboBoxCity->Text = "";
	MaskEditBuildDate->Text = "";
	EditRooms->Clear();
	EditBaths->Clear();
	EditArea->Clear();

    ClearTheGrid();

    LabelInfo->Caption = "";
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindAssets::ClearTheGrid()
{
	Grid->RowCount = DEFROWS;

    for(int i=0; i<=Grid->ColCount; i++)
    {
		Grid->Cells[i][1] = "";
    }
}

/*!****************************************************************************
* @brief	Setup for the grid control
******************************************************************************/
void __fastcall TFormFindAssets::SetupTheGrid()
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
	Grid->Cells[1][0] = "typology";
	Grid->Cells[2][0] = "status";
    Grid->Cells[3][0] = "value";
	Grid->Cells[4][0] = "price";
    Grid->Cells[5][0] = "city";
	Grid->Cells[6][0] = "address";
    Grid->Cells[7][0] = "epgl";
    Grid->Cells[8][0] = "rooms";
    Grid->Cells[9][0] = "baths";
    Grid->Cells[10][0] = "area";
	Grid->Cells[11][0] = "build date";
    Grid->Cells[12][0] = "sold date";
	Grid->Cells[13][0] = "descr";

    Grid->ColWidths[1] = 96;
	Grid->ColWidths[2] = 80;
    Grid->ColWidths[3] = 80;
	Grid->ColWidths[4] = 80;
    Grid->ColWidths[5] = 128;
	Grid->ColWidths[6] = 150;
	Grid->ColWidths[10] = 64;
	Grid->ColWidths[11] = 80;
    Grid->ColWidths[12] = 80;
    Grid->ColWidths[13] = 256;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindAssets::PrintResults(TVecPtrAssets& Assets)
{
	int nCols = 5;
	int nRows = Assets.size();

	AnsiString strTemp;
    Grid->RowCount = nRows + 1;

    for(int i=0; i<nRows; i++)
    {
		TAsset* pAsset = Assets[i];
        assert(pAsset);

											// row number
		Grid->Cells[0][i+1] = i+1;

											// typology
		Grid->Cells[1][i+1] = g_AssetTypologyChoices[pAsset->m_nTypology].strName;

											// status
		Grid->Cells[2][i+1] = g_AssetStatusChoices[pAsset->m_nStatus].strName;

											// value
        Grid->Cells[3][i+1] = pAsset->m_nValue;

											// price
        Grid->Cells[4][i+1] = pAsset->m_nPrice;

											// city
		Grid->Cells[5][i+1] = pAsset->m_strCity;

											// address
		Grid->Cells[6][i+1] = pAsset->m_strAddress;

    	if( pAsset->m_nTypology > atTerrain )
        {
	    									// epgl
			Grid->Cells[7][i+1] = g_AssetEpglChoices[pAsset->m_nEpgl].strName;

											// rooms
			Grid->Cells[8][i+1] = pAsset->m_nRooms;

        									// bathrooms
			Grid->Cells[9][i+1] = pAsset->m_nBathrooms;
        }
        else
        {
        	Grid->Cells[7][i+1] = "";
	    	Grid->Cells[8][i+1] = "";
	    	Grid->Cells[9][i+1] = "";
        }
        									// area
		Grid->Cells[10][i+1] = pAsset->m_nArea;

											// building date
        if( pAsset->m_nTypology > atTerrain )
		{
			TDate Date(double(pAsset->m_BuildDate));
            unsigned short nYear = 0, nMonth = 0, nDay = 0;
            Date.DecodeDate(&nYear, &nMonth, &nDay);

            AnsiString strTemp;
            strTemp.sprintf("%02d/%02d/%04d", nDay, nMonth, nYear);

            Grid->Cells[11][i+1] = strTemp;
		}
		else
        {
			Grid->Cells[11][i+1] = "";
        }
        									// sold out date
		if( pAsset->m_nStatus == asSoldOut )
        {
			TDate Date(double(pAsset->m_SoldDate));
            unsigned short nYear = 0, nMonth = 0, nDay = 0;
            Date.DecodeDate(&nYear, &nMonth, &nDay);

            AnsiString strTemp;
            strTemp.sprintf("%02d/%02d/%04d", nDay, nMonth, nYear);

            Grid->Cells[12][i+1] = strTemp;
        }
        else
        {
			Grid->Cells[12][i+1] = "";
        }

											// description
        Grid->Cells[13][i+1] = pAsset->m_strDescription;
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindAssets::GridDblClick(TObject *Sender)
{
	if( m_QueryAssets.size() )
    {
        EditRecord(m_QueryAssets, Grid->Row - 1);
	}
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormFindAssets::EditRecord(TVecPtrAssets& Assets, int nGridSelRow)
{
    assert(m_pDB);

    TAssetsArchive* pAssets = m_pDB->GetAssets();
    assert(pAssets);
                                        // poiche' Assets puo' essere
                                        // stato filtrato il numero di riga
                                        // della grid (tabella) puo' NON
                                        // corrispondere piu' alla posizione
                                        // del TAsset nel vettore Assets
                                        // per cui bisogna recuperarlo per il
                                        // tramite del suo puntatore (TAsset*)
    unsigned nRecId = 0;

    if( pAssets->GetRecordId( Assets[nGridSelRow], nRecId) )
    {
		if( m_hWndMsgs )
        {
            TFormAssets* pFormAssets = NULL;

            ::SendMessage(m_hWndMsgs, UM_GETFORMASSETS, (WPARAM)(LPVOID) &pFormAssets, 0);

            if( pFormAssets )
            {
                pFormAssets->SetCurRecord(nRecId);
                pFormAssets->ShowModal();

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
void __fastcall TFormFindAssets::FormShow(TObject *Sender)
{
	Clear();
}

/*!****************************************************************************
* @brief	Executes the query according to the values of UI controls
******************************************************************************/
void __fastcall TFormFindAssets::DoQuery()
{
	assert(m_pDB);

    TAssetsArchive* pAssets = m_pDB->GetAssets();
    assert(pAssets);

    m_QueryAssets = pAssets->GetAssets();

    if( m_QueryAssets.size() )
    {
											// filter by typology
		enAssetTypology nTypology = g_AssetTypologyChoices[ ComboBoxTypology->ItemIndex ].nTypology;
        if( nTypology != atNone )
        {
			FilterByTypology(m_QueryAssets, nTypology);
        }
											// filter by city
        std::string strCityName = AnsiString(ComboBoxCity->Text).c_str();
		if( strCityName.length() )
        {
			FilterByCity(m_QueryAssets, strCityName, CheckBoxCityNameFullMatch->Checked);
        }
											// filter by address
		std::string strAddress = AnsiString(EditAddress->Text).c_str();
		if( strAddress.length() )
        {
			FilterByAddress(m_QueryAssets, strAddress, false);
        }
											// filter by status (rent, sale, etc...)
		enAssetStatus nStatus = g_AssetStatusChoices[ComboBoxStatus->ItemIndex].nStatus;
        if( nStatus != asNone )
        {
			FilterByStatus(m_QueryAssets, nStatus);
        }
											// filter by epgl energetic class
        enAssetEpgl nEpgl = g_AssetEpglChoices[ComboBoxEpgl->ItemIndex].nEpgl;
		if( nEpgl != aeNone )
        {
			FilterByEpgl(m_QueryAssets, nEpgl, AnsiString(ComboBoxEpglIneq->Text).c_str() );
        }
											// filter by price
        if( EditPrice->Text.Length() )
        {
			unsigned nPrice = EditPrice->Text.ToInt();
            FilterByPrice(m_QueryAssets, nPrice, AnsiString(ComboBoxPriceIneq->Text).c_str());
        }
                                            // filter by date
        unsigned short nYear, nMonth, nDay;
        std::string strDate = AnsiString(MaskEditBuildDate->Text).c_str();
        if( utils::ParseDate(strDate, nYear, nMonth, nDay) )
        {
            try
            {
                TDate Date(nYear, nMonth, nDay);
                FilterByBuildDate(m_QueryAssets, Date.Val, AnsiString(ComboBoxBuildDateIneq->Text).c_str());
			}
            catch(...)
            {
                ;
            }
        }
											// filter by rooms
        if( EditRooms->Text.Length() )
        {
			int nRooms = EditRooms->Text.ToInt();
			FilterByRooms(m_QueryAssets, nRooms, ">=");
        }
											// filter by bathrooms
        if( EditBaths->Text.Length() )
        {
			int nBaths = EditBaths->Text.ToInt();
			FilterByBathrooms(m_QueryAssets, nBaths, ">=");
        }
											// filter by area
        if( EditArea->Text.Length() )
        {
			int nArea = EditArea->Text.ToInt();
			FilterByArea(m_QueryAssets, nArea, ">=");
        }

											// if query results contains records
        if( m_QueryAssets.size() )
        {
                                            // makes a sorting (eventually)

            switch( g_SortingChoices[ComboBoxSorting->ItemIndex].nMode )
            {
				case smCityAsc: SortByCity(m_QueryAssets, true); break;
				case smCityDesc: SortByCity(m_QueryAssets, false); break;
                case smValueAsc: SortByValue(m_QueryAssets, true); break;
                case smValueDesc: SortByValue(m_QueryAssets, false); break;
				case smAreaAsc: SortByArea(m_QueryAssets, true); break;
				case smAreaDesc: SortByArea(m_QueryAssets, false); break;
            }

			PrintResults(m_QueryAssets);
        }

        AnsiString strTemp;
        strTemp.sprintf(
            "  Result: %d record(s) found.  Double click to edit the record. ",
            m_QueryAssets.size());
        LabelInfo->Caption = strTemp;

	}
	else
    {
		ShowErrorMsg(ERR_DBEMPTYASSETS, emtWarning);
    }
}


