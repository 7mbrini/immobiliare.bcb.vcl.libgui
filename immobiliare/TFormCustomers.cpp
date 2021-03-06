/*!****************************************************************************

	@file	TFormCustomers.h
	@file	TFormCustomers.cpp

	@brief	Customers form

	@noop	author:	Francesco Settembrini
	@noop	last update: 8/11/2021, 28/11/2021
	@noop	e-mail:	mailto:francesco.settembrini@poliba.it

******************************************************************************/

#include <vcl.h>
#pragma hdrstop

#include "cities.h"
#include "utils.h"
#include "commdefs.h"

//#include "TFormMain.h"
#include "TFormDebug.h"
#include "TFormCustomers.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


struct TCustomerOwnershipChoice
{
	AnsiString strName;
	enCustomerOwnershipType nType;
} g_CustomerOwnershipChoices[] =
{
	{" ", cotNone},
	{"for rent", cotForRent},
    {"for purchase", cotForPurchase}
};


/*!****************************************************************************
* @brief	Constructor
******************************************************************************/
__fastcall TFormCustomers::TFormCustomers(TComponent* Owner,
	TDataBanker* pDB, HWND hWndMsgs) : TForm(Owner)
{
	assert(pDB);

    m_pDB = pDB;
    m_nCurRecord = 0;

	m_hWndMsgs = hWndMsgs;

    Setup();
}

/*!****************************************************************************
* @brief	Setup
******************************************************************************/
void __fastcall TFormCustomers::Setup()
{
	assert(m_pDB);

    this->BorderStyle = bsSingle;
    this->FormStyle = fsStayOnTop;
	this->Position = poScreenCenter;
	this->BorderIcons >> biMinimize >> biMaximize;
	this->Caption = AnsiString(APPNAME) + " - Customers";

	ScrollBar->Min = 0;
    ScrollBar->Max = 0;
										// build the "cities" combobox
	m_pDB->GetCities(m_Cities);
    assert(m_Cities.size());

    for(int i=0; i<m_Cities.size(); i++)
    {
		ComboBoxCity->Items->Add(m_Cities[i].m_strName.c_str());
    }
	ComboBoxCity->Text = "";

    for(int i=0; i<sizeof(g_CustomerOwnershipChoices)/sizeof(g_CustomerOwnershipChoices[0]); i++)
    {
		ComboBoxOwnership->Items->Add(g_CustomerOwnershipChoices[i].strName.c_str());
    }
	ComboBoxOwnership->ItemIndex = 0;
}

/*!****************************************************************************
* @brief	Clears the GUI controls
******************************************************************************/
void __fastcall TFormCustomers::Clear()
{
    EditFirstName->Text = "";
    EditLastName->Text = "";
    EditAddress->Text = "";
	ComboBoxCity->Text = "";
    EditCap->Text = "";
    EditPhone->Text = "";
    EditEmail->Text = "";
    EditBudget->Text = "";

    LabelInfo->Caption = 0;
}

/*!****************************************************************************
* @brief	Validates the input
******************************************************************************/
bool __fastcall TFormCustomers::ValidateInput()
{
	bool bValid = true;

	unsigned nBudget = EditBudget->Text.ToInt();
    if( nBudget < CUSTOMER_MINBUDGET )
    {
    	AnsiString strTemp;
        strTemp.printf(
        	"Error: Minimum value for budget is %d!",
            CUSTOMER_MINBUDGET );

		::MessageBox(0, WideString(strTemp).c_bstr(), L"Error:",
        	MB_OK | MB_ICONERROR | MB_TOPMOST | MB_TASKMODAL);

		bValid = false;
    }

	if( bValid )
    {
		if( EditFirstName->Text.Length() > CUSTOMER_NAMESMAXLEN )
        {
            AnsiString strTemp;
            strTemp.printf(
            	"Error: Maximum length for \"First Name\" is %d characters!",
                CUSTOMER_NAMESMAXLEN );

            ::MessageBox(0, WideString(strTemp).c_bstr(), L"Error:",
                MB_OK | MB_ICONERROR | MB_TOPMOST | MB_TASKMODAL);

            bValid = false;
        }
		else if( EditFirstName->Text.Length() < CUSTOMER_NAMESMINLEN )
        {
            AnsiString strTemp;
            strTemp.printf(
            	"Error: Minimum length for \"First Name\" is %s characters !",
                CUSTOMER_NAMESMINLEN );

            ::MessageBox(0, WideString(strTemp).c_bstr(), L"Error:",
                MB_OK | MB_ICONERROR | MB_TOPMOST | MB_TASKMODAL);

            bValid = false;
        }
    }

	if( bValid )
    {
		if( EditLastName->Text.Length() > CUSTOMER_NAMESMAXLEN )
        {
            AnsiString strTemp;
            strTemp.printf(
            	"Error: Maximum length for \"Last Name\" is %d characters!",
                CUSTOMER_NAMESMAXLEN );

            ::MessageBox(0, WideString(strTemp).c_bstr(), L"Error:",
                MB_OK | MB_ICONERROR | MB_TOPMOST | MB_TASKMODAL);

            bValid = false;
        }
		else if( EditLastName->Text.Length() < CUSTOMER_NAMESMINLEN )
        {
            AnsiString strTemp;
            strTemp.printf(
            	"Error: Minimum length for \"Last Name\" is %s characters !",
                CUSTOMER_NAMESMINLEN);

            ::MessageBox(0, WideString(strTemp).c_bstr(), L"Error:",
                MB_OK | MB_ICONERROR | MB_TOPMOST | MB_TASKMODAL);

            bValid = false;
        }
    }

	if( bValid )
    {
		if( EditAddress->Text.Length() > CUSTOMER_NAMESMAXLEN )
        {
            AnsiString strTemp;
            strTemp.printf(
            	"Error: Maximum length for \"Address\" is %d characters!",
                CUSTOMER_NAMESMAXLEN );

            ::MessageBox(0, WideString(strTemp).c_bstr(), L"Error:",
                MB_OK | MB_ICONERROR | MB_TOPMOST | MB_TASKMODAL);

            bValid = false;
        }
		else if( EditAddress->Text.Length() < CUSTOMER_NAMESMINLEN )
        {
            AnsiString strTemp;
            strTemp.printf(
            	"Error: Minimum length for \"Address\" is %s characters !",
                CUSTOMER_NAMESMINLEN);

            ::MessageBox(0, WideString(strTemp).c_bstr(), L"Error:",
                MB_OK | MB_ICONERROR | MB_TOPMOST | MB_TASKMODAL);

            bValid = false;
        }
    }

    return bValid;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormCustomers::ButtonCloseClick(TObject *Sender)
{
	this->ModalResult = mrOk;
	Close();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormCustomers::FormShow(TObject *Sender)
{
	assert(m_pDB);

	Clear();

    if( m_pDB->HaveCustomers() )
    {
        SetCurRecord(m_nCurRecord);

        Update();
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormCustomers::ComboBoxCityChange(TObject *Sender)
{
    int nItem = ComboBoxCity->ItemIndex;

	if( m_Cities.size() && nItem < m_Cities.size() )
    {
	    EditCap->Text = m_Cities[nItem].m_strCap.c_str();
    }
}

/*!****************************************************************************
* @brief	Updates the UI controls with Customer object specified by nId
******************************************************************************/
void __fastcall TFormCustomers::SetCurRecord(int nId)
{
	assert(m_pDB);

	TCustomersArchive* pCustomers = m_pDB->GetCustomers();
    assert(pCustomers);

    Clear();

	if( pCustomers->GetCount() )
    {
        TCustomer *pCustomer = NULL;

        if( pCustomer = pCustomers->GetRecord(nId) )
        {
            m_nCurRecord = nId;

            EditFirstName->Text = pCustomer->m_strFirstName;
            EditLastName->Text = pCustomer->m_strLastName;
            EditAddress->Text = pCustomer->m_strAddress;
            ComboBoxCity->Text = pCustomer->m_strCity;

            AnsiString strTemp;
            strTemp.sprintf("%d", pCustomer->m_nCap);
            EditCap->Text = strTemp;

            EditPhone->Text = pCustomer->m_strPhone;
            EditEmail->Text = pCustomer->m_strEmail;

            strTemp.sprintf("%d", pCustomer->m_nBudget);
            EditBudget->Text = strTemp;

            ComboBoxOwnership->ItemIndex = pCustomer->m_nOwnership;
        }
	}
}

/*!****************************************************************************
* @brief	Update the Customer object with the UI controls values
******************************************************************************/
void __fastcall TFormCustomers::GetRecord(TCustomer& Customer)
{
    strncpy(Customer.m_strFirstName, AnsiString(EditFirstName->Text).c_str(), CUSTOMER_NAMESMAXLEN-1);
    strncpy(Customer.m_strLastName, AnsiString(EditLastName->Text).c_str(), CUSTOMER_NAMESMAXLEN-1);
    strncpy(Customer.m_strAddress, AnsiString(EditAddress->Text).c_str(), CUSTOMER_NAMESMAXLEN-1);
    strncpy(Customer.m_strCity, AnsiString(ComboBoxCity->Text).c_str(), CUSTOMER_NAMESMAXLEN-1);
    strncpy(Customer.m_strEmail, AnsiString(EditEmail->Text).c_str(), CUSTOMER_NAMESMAXLEN-1);
    strncpy(Customer.m_strPhone, AnsiString(EditPhone->Text).c_str(), CUSTOMER_NAMESMAXLEN-1);

    Customer.m_nCap = EditCap->Text.ToInt();
    Customer.m_nBudget = EditBudget->Text.ToInt();
    Customer.m_nOwnership = g_CustomerOwnershipChoices[ComboBoxOwnership->ItemIndex].nType;
}

/*!****************************************************************************
* @brief	Adds a record
******************************************************************************/
void __fastcall TFormCustomers::AddRecord()
{
	assert(m_pDB);

	TCustomersArchive* pCustomers = m_pDB->GetCustomers();
    assert(pCustomers);

	if( ValidateInput() )
    {
		TCustomer *pCustomer = new TCustomer;
        assert(pCustomer);

        GetRecord(*pCustomer);

        pCustomers->Add(pCustomer);

#ifdef _DEBUG
//FormDebug->Print(pCustomer->AsString());
#endif

        Update();

                                    // sends a message to a recipient
                                    // to notify that the archive has
                                    // been modified
		if( m_hWndMsgs )
        {
			::SendMessage(m_hWndMsgs, UM_CUSTOMERSDBMODIFY, 0, 0);
        }
	}
}

/*!****************************************************************************
* @brief	Deletes a record
******************************************************************************/
void __fastcall TFormCustomers::DeleteRecord()
{
	assert(m_pDB);

	TCustomersArchive* pCustomers = m_pDB->GetCustomers();
    assert(pCustomers);

	if( (m_nCurRecord >= 0) && (m_nCurRecord < pCustomers->GetCount()) )
    {
		pCustomers->Delete(m_nCurRecord);

        SetCurRecord(m_nCurRecord--);

        Update();

                                    // sends a message to a recipient
                                    // to notify that the archive has
                                    // been modified
		if( m_hWndMsgs )
        {
            ::SendMessage(m_hWndMsgs, UM_CUSTOMERSDBMODIFY, 0, 0);
        }
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormCustomers::UpdateRecord()
{
	assert(m_pDB);

	TCustomersArchive* pCustomers = m_pDB->GetCustomers();
    assert(pCustomers);

	if( ValidateInput() && (m_nCurRecord >= 0) && (m_nCurRecord < pCustomers->GetCount()) )
    {
		TCustomer Customer;
        GetRecord(Customer);

#ifdef _DEBUG
//FormDebug->Print(Customer.AsString());
#endif
		pCustomers->Update(m_nCurRecord, Customer);

        Update();

                                    // sends a message to a recipient
                                    // to notify that the archive has
                                    // been modified
        if( m_hWndMsgs )
        {
            ::SendMessage(m_hWndMsgs, UM_CUSTOMERSDBMODIFY, 0, 0);
        }
    }
}

/*!****************************************************************************
* @brief	Sets the current record according to the scrollbar position
******************************************************************************/
void __fastcall TFormCustomers::ScrollBarScroll(TObject *Sender,
	TScrollCode ScrollCode, int &ScrollPos)
{
	assert(m_pDB);

	if( m_pDB->HaveCustomers() )
    {
        SetCurRecord(ScrollPos);

        Update();
	}
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormCustomers::SpeedButtonAddClick(TObject *Sender)
{
	AddRecord();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormCustomers::SpeedButtonDeleteClick(TObject *Sender)
{
	DeleteRecord();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormCustomers::SpeedButtonUpdateClick(TObject *Sender)
{
	UpdateRecord();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormCustomers::SpeedButtonClearClick(TObject *Sender)
{
	Clear();
}

/*!****************************************************************************
* @brief	Updates the GUI controls according to the archive properties
******************************************************************************/
void __fastcall TFormCustomers::Update()
{
	assert(m_pDB);

	TCustomersArchive* pCustomers = m_pDB->GetCustomers();
    assert(pCustomers);

	if( pCustomers->GetCount() )
    {
        int nCount = pCustomers->GetCount();

		ScrollBar->Enabled = true;
        ScrollBar->Max = nCount - 1;
		LabelInfo->Visible = true;
		SpeedButtonDelete->Enabled = true;
        SpeedButtonUpdate->Enabled = true;

        AnsiString strTemp;
        strTemp.printf("%d/%d", m_nCurRecord + 1, nCount);
        LabelInfo->Caption = strTemp;
	}
	else
    {
        ScrollBar->Enabled = false;
		LabelInfo->Visible = false;
		SpeedButtonDelete->Enabled = false;
		SpeedButtonUpdate->Enabled = false;
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormCustomers::FormCanResize(TObject *Sender,
	int &NewWidth, int &NewHeight, bool &Resize)
{
	this->ButtonClose->Left = (this->Width - this->ButtonClose->Width)/2;
}


