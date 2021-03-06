//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <string>

#include "TFormMain.h"

#include "utils.h"
#include "commdefs.h"
#include "errormsgs.h"
#include "databanker.h"

#include "libgui.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;


//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner) : TForm(Owner)
{
	m_pDB = NULL;

    m_pFormDebug = NULL;
	m_pFormAssets = NULL;
    m_pFormCustomers = NULL;
    m_pFormFindAssets = NULL;
    m_pFormFindCustomers = NULL;
    m_pFormQueries = NULL;

	m_bAssetsDBModify = m_bCustomersDBModify = false;
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
{
	Setup();
}

void __fastcall TFormMain::Setup()
{
	this->Caption = APPNAME;

#ifndef _DEBUG
	this->Width = APPWIDTH;
    this->Height = APPHEIGHT;
    this->Position = poScreenCenter;
#else
	this->Left = 400;
    this->Top = 200;
    this->Width = APPWIDTH;
    this->Height = APPHEIGHT;
    this->Position = poDefaultPosOnly;

	m_pFormDebug = libgui_CreateFormDebug();
    assert(m_pFormDebug);
	HWND hWndDebug = libgui_GetHandle(m_pFormDebug);
    ::SetWindowPos(hWndDebug, 0, this->Left + this->Width, this->Top, 400, this->Height, 0);
    libgui_Show(m_pFormDebug);
#endif
											// build the DataBanker
    m_pDB = new TDataBanker();
    assert(m_pDB);
											// load cities archive
    std::string strFileName = utils::GetDataPath() + CITIES;
    if( !m_pDB->CitiesLoadFromFile(strFileName) )
    {
		ShowErrorMsg(ERR_DBNOCITIESFILE);
        exit(-1);
    }

    //m_pDB->AssetsCreateArchive();
    //m_pDB->CustomersCreateArchive();

    m_pFormAssets = libgui_CreateFormAssets(m_pDB, this->Handle);
    assert(m_pFormAssets);

    m_pFormCustomers = libgui_CreateFormCustomers(m_pDB, this->Handle);
    assert(m_pFormCustomers);

    m_pFormFindAssets = libgui_CreateFormFindAssets(m_pDB, this->Handle);
    assert(m_pFormFindAssets);

    m_pFormFindCustomers = libgui_CreateFormFindCustomers(m_pDB, this->Handle);
    assert(m_pFormFindCustomers);

    m_pFormQueries = libgui_CreateFormQueries(m_pDB, this->Handle);
    assert(m_pFormQueries);
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::Cleanup()
{
	assert(m_pDB);

    delete m_pDB;
}

/*!****************************************************************************
* @brief
******************************************************************************/
bool __fastcall TFormMain::IsDirty()
{
	return m_bAssetsDBModify || m_bCustomersDBModify;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	if( IsDirty() )
    {
    	AnsiString strMsg, strCaption;

		strCaption = AnsiString("Exit from ") + APPNAME;

		if( m_bAssetsDBModify && m_bCustomersDBModify )
        {
        	strMsg = "Databases \"Asset\" and \"Customer\" have been modified without saving :"
				"\n\nConfirm Exit ?";
        }
        else if( m_bAssetsDBModify )
        {
        	strMsg = "Database \"Asset\" has been modified without saving :"
				"\n\nConfirm Exit ?";
        }
        else
        {
        	strMsg = "Database \"Customers\" has been modified without saving :"
				"\n\nConfirm Exit ?";
        }

		::MessageBeep(-1);

        if( ::MessageBox(0, WideString(strMsg).c_bstr(),
        	WideString(strCaption).c_bstr(),
        	MB_YESNO | MB_ICONQUESTION | MB_TASKMODAL | MB_TOPMOST) == IDNO )
        {
			Action = caNone;
		}
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::NewAssetsArchive()
{
	assert(m_pDB);

	m_pDB->AssetsCreateArchive();

    if( bool(m_pDB->GetAssets()) )
    {
		::MessageBox(0,
        	L"\"Assets\" archive successfully created",
            WideString(AnsiString(AnsiString(APPNAME) + AnsiString(" Info:"))).c_bstr(),
            MB_OK | MB_ICONINFORMATION | MB_TASKMODAL | MB_TOPMOST );
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::NewCustomersArchive()
{
	assert(m_pDB);

    m_pDB->CustomersCreateArchive();

    if( bool(m_pDB->GetCustomers()) )
    {
		::MessageBox(0,
        	L"\"Customers\" archive successfully created",
            WideString(AnsiString(AnsiString(APPNAME) + AnsiString(" Info:"))).c_bstr(),
            MB_OK | MB_ICONINFORMATION | MB_TASKMODAL | MB_TOPMOST );
    }
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::FileNewAssetsArchiveClick(TObject *Sender)
{
    NewAssetsArchive();
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::FileNewCustomersArchiveClick(TObject *Sender)
{
	NewCustomersArchive();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::LoadAssetsArchive()
{
	assert(m_pDB);

	OpenDialog->Filter = "Immobiliare Assets Archive|*.ast";
    OpenDialog->DefaultExt = "*.ast";

#ifdef _DEBUG
    OpenDialog->InitialDir = utils::GetDataPath().c_str();
#endif

	if( OpenDialog->Execute() == mrOk )
    {
        if( !m_pDB->AssetsLoadFromFile(AnsiString(OpenDialog->FileName).c_str()) )
        {
			ShowErrorMsg(ERR_OPENASSETS);
        }
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::LoadCustomersArchive()
{
	assert(m_pDB);

	OpenDialog->Filter = "Immobiliare Customers Archive|*.cst";
    OpenDialog->DefaultExt = "*.cst";

#ifdef _DEBUG
    OpenDialog->InitialDir = utils::GetDataPath().c_str();
#endif

	if( OpenDialog->Execute() == mrOk )
    {
		if( !m_pDB->CustomersLoadFromFile(AnsiString(OpenDialog->FileName).c_str()) )
        {
			ShowErrorMsg(ERR_OPENCUSTOMERS);
        }
    }
}



//---------------------------------------------------------------------------



void __fastcall TFormMain::FileOpenAssetsArchiveClick(TObject *Sender)
{
	LoadAssetsArchive();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FileOpenCustomersArchiveClick(TObject *Sender)
{
	LoadCustomersArchive();
}
//---------------------------------------------------------------------------

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::SaveAssets()
{
	assert(m_pDB);

    if( bool(m_pDB->GetAssets()) )
    {
        SaveDialog->Filter = "Immobiliare Assets Archive|*.ast";
        SaveDialog->DefaultExt = "*.ast";

#ifdef _DEBUG
    SaveDialog->InitialDir = utils::GetDataPath().c_str();
#endif

        if( SaveDialog->Execute() == mrOk )
        {
            if( !m_pDB->AssetsSaveToFile(AnsiString(SaveDialog->FileName).c_str()) )
            {
                ShowErrorMsg(ERR_DBSAVEASSETS);
            }
            else
            {
                m_bAssetsDBModify = false;
            }
        }
    }
    else
    {
        ShowErrorMsg(ERR_DBNOASSETS);
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::SaveCustomers()
{
	assert(m_pDB);

    if( bool(m_pDB->GetCustomers()) )
    {
        SaveDialog->Filter = "Immobiliare Customers Archive|*.cst";
        SaveDialog->DefaultExt = "*.cst";

#ifdef _DEBUG
    SaveDialog->InitialDir = utils::GetDataPath().c_str();
#endif

        if( SaveDialog->Execute() == mrOk )
        {
            if( !m_pDB->CustomersSaveToFile(AnsiString(SaveDialog->FileName).c_str()) )
            {
                ShowErrorMsg(ERR_DBSAVECUSTOMERS);
            }
            else
            {
                m_bCustomersDBModify = false;
            }
        }
    }
    else
    {
        ShowErrorMsg(ERR_DBNOCUSTOMERS);
    }
}

void __fastcall TFormMain::FileSaveAssetsArchiveClick(TObject *Sender)
{
	SaveAssets();
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::FileSaveCustomersArchiveClick(TObject *Sender)
{
	SaveCustomers();
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::FileQuitClick(TObject *Sender)
{
	PostQuitMessage(0);
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::HelpAboutClick(TObject *Sender)
{
	AnsiString strTitle;
    strTitle.printf("About '%s'", APPNAME);

    AnsiString strCaption;
    strCaption.printf("%s"
        "\n\n(C) 2021 Francesco Settembrini"
        "\n\nfrancesco.settembrini@poliba.it"
        "\nf.settembrini1@studenti.uniba.it",
        APPNAME);

	::MessageBox(0, WideString(strCaption).c_bstr(),
    	WideString(strTitle).c_bstr(),
        MB_OK | MB_ICONINFORMATION | MB_TASKMODAL | MB_TOPMOST );

}

//---------------------------------------------------------------------------
void __fastcall TFormMain::FormDestroy(TObject *Sender)
{
	Cleanup();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::ShowFormAssets()
{
	assert(m_pDB);
	assert(m_pFormAssets);

	if( bool(m_pDB->GetAssets()) )
    {
	    //m_pFormAssets->ShowModal();
        libgui_ShowModal(m_pFormAssets);
    }
    else
    {
		ShowErrorMsg(ERR_DBNOASSETS);
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::ShowFormCustomers()
{
	assert(m_pDB);
	assert(m_pFormCustomers);

	if( bool(m_pDB->GetCustomers()) )
    {
		//m_pFormCustomers->ShowModal();
        libgui_ShowModal(m_pFormCustomers);
    }
    else
    {
		ShowErrorMsg(ERR_DBNOCUSTOMERS);
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::ShowFormQueries()
{
	assert(m_pDB);
    assert(m_pFormQueries);

	//m_pFormQueries->Visible = true;
    libgui_Show(m_pFormQueries);
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::ShowFormFindAssets()
{
	assert(m_pDB);
    assert(m_pFormFindAssets);

	if( bool(m_pDB->GetAssets()) )
    {
	    //m_pFormFindAssets->ShowModal();
        libgui_ShowModal(m_pFormFindAssets);
    }
    else
    {
		ShowErrorMsg(ERR_DBNOASSETS);
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::ShowFormFindCustomers()
{
	assert(m_pDB);
    assert(m_pFormFindCustomers);

	if( bool(m_pDB->GetCustomers()) )
    {
		//m_pFormFindCustomers->ShowModal();
        libgui_ShowModal(m_pFormFindCustomers);
    }
    else
    {
		ShowErrorMsg(ERR_DBNOCUSTOMERS);
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::OnAssetsDBModify(TMessage& Message)
{
	m_bAssetsDBModify = true;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::OnCustomersDBModify(TMessage& Message)
{
	m_bCustomersDBModify = true;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::OnGetFormAssets(TMessage& Message)
{
    //TFormAssets **pFormAssets = (TFormAssets**) Message.WParam;
    //*pFormAssets = GetFormAssets();

    void **pFormAssets = (void**) Message.WParam;

    *pFormAssets = m_pFormAssets;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormMain::OnGetFormCustomers(TMessage& Message)
{
    //TFormCustomers **pFormCustomers = (TFormCustomers**) Message.WParam;
    //*pFormCustomers = GetFormCustomers();


    void **pFormCustomers = (void**) Message.WParam;

    *pFormCustomers = m_pFormCustomers;
}


//---------------------------------------------------------------------------

void __fastcall TFormMain::SpeedButtonAssetsClick(TObject *Sender)
{
	ShowFormAssets();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::SpeedButtonCustomersClick(TObject *Sender)
{
	ShowFormCustomers();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::SpeedButtonFindAssetsClick(TObject *Sender)
{
	ShowFormFindAssets();

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::SpeedButtonFindCustomersClick(TObject *Sender)
{
	ShowFormFindCustomers();

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::SpeedButtonQueriesClick(TObject *Sender)
{
	ShowFormQueries();
}

//---------------------------------------------------------------------------


void __fastcall TFormMain::FormsAssetsClick(TObject *Sender)
{
	ShowFormAssets();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormCustomersClick(TObject *Sender)
{
	ShowFormCustomers();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::QueriesFindAssetsClick(TObject *Sender)
{
	ShowFormFindAssets();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::QueriesFindCustomersClick(TObject *Sender)
{
	ShowFormFindCustomers();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::QueriesMoreQueriesClick(TObject *Sender)
{
	ShowFormQueries();
}
//---------------------------------------------------------------------------

