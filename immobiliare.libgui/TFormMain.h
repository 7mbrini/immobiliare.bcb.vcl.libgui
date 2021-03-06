//---------------------------------------------------------------------------

#ifndef TFormMainH
#define TFormMainH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Menus.hpp>

#include "commdefs.h"

class TDataBanker;

//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TImage *Image;
	TMainMenu *MainMenu;
	TMenuItem *File;
	TMenuItem *FileNew;
	TMenuItem *FileNewAssetsArchive;
	TMenuItem *FileNewCustomersArchive;
	TMenuItem *FileOpen;
	TMenuItem *FileOpenAssetsArchive;
	TMenuItem *FileOpenCustomersArchive;
	TMenuItem *FileSave;
	TMenuItem *FileSaveAssetsArchive;
	TMenuItem *FileSaveCustomersArchive;
	TMenuItem *N1;
	TMenuItem *FileQuit;
	TMenuItem *Forms;
	TMenuItem *FormsAssets;
	TMenuItem *FormCustomers;
	TMenuItem *Queries;
	TMenuItem *QueriesFindAssets;
	TMenuItem *QueriesFindCustomers;
	TMenuItem *QueriesMoreQueries;
	TMenuItem *Help;
	TMenuItem *HelpAbout;
	TOpenDialog *OpenDialog;
	TPanel *PanelStatus;
	TPanel *PanelTop;
	TSpeedButton *SpeedButtonQueries;
	TSpeedButton *SpeedButtonAssets;
	TSpeedButton *SpeedButtonCustomers;
	TSpeedButton *SpeedButtonFindCustomers;
	TSpeedButton *SpeedButtonFindAssets;
	TSaveDialog *SaveDialog;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FileNewAssetsArchiveClick(TObject *Sender);
	void __fastcall FileNewCustomersArchiveClick(TObject *Sender);
	void __fastcall FileOpenAssetsArchiveClick(TObject *Sender);
	void __fastcall FileOpenCustomersArchiveClick(TObject *Sender);
	void __fastcall FileSaveAssetsArchiveClick(TObject *Sender);
	void __fastcall FileSaveCustomersArchiveClick(TObject *Sender);
	void __fastcall FileQuitClick(TObject *Sender);
	void __fastcall HelpAboutClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall SpeedButtonAssetsClick(TObject *Sender);
	void __fastcall SpeedButtonCustomersClick(TObject *Sender);
	void __fastcall SpeedButtonFindAssetsClick(TObject *Sender);
	void __fastcall SpeedButtonFindCustomersClick(TObject *Sender);
	void __fastcall SpeedButtonQueriesClick(TObject *Sender);
	void __fastcall FormsAssetsClick(TObject *Sender);
	void __fastcall FormCustomersClick(TObject *Sender);
	void __fastcall QueriesFindAssetsClick(TObject *Sender);
	void __fastcall QueriesFindCustomersClick(TObject *Sender);
	void __fastcall QueriesMoreQueriesClick(TObject *Sender);

private:	// User declarations

public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);

protected:
	void __fastcall Setup();
	void __fastcall Cleanup();

protected:
	TDataBanker *m_pDB;
    void *m_pFormDebug, *m_pFormAssets, *m_pFormCustomers,
    	*m_pFormFindAssets, *m_pFormFindCustomers, *m_pFormQueries;
	bool m_bAssetsDBModify, m_bCustomersDBModify;

    bool __fastcall IsDirty();

	void __fastcall NewAssetsArchive();
	void __fastcall NewCustomersArchive();

    void __fastcall LoadAssetsArchive();
    void __fastcall LoadCustomersArchive();

    void __fastcall SaveAssets();
    void __fastcall SaveCustomers();

	void __fastcall ShowFormAssets();
	void __fastcall ShowFormCustomers();

    void __fastcall ShowFormQueries();
	void __fastcall ShowFormFindAssets();
    void __fastcall ShowFormFindCustomers();


	void __fastcall OnAssetsDBModify(TMessage& Message);
    void __fastcall OnCustomersDBModify(TMessage& Message);
    void __fastcall OnGetFormAssets(TMessage& Message);
	void __fastcall OnGetFormCustomers(TMessage& Message);

	BEGIN_MESSAGE_MAP
		MESSAGE_HANDLER(UM_ASSETSDBMODIFY, TMessage, OnAssetsDBModify);
        MESSAGE_HANDLER(UM_CUSTOMERSDBMODIFY, TMessage, OnCustomersDBModify);
        MESSAGE_HANDLER(UM_GETFORMASSETS, TMessage, OnGetFormAssets);
        MESSAGE_HANDLER(UM_GETFORMCUSTOMERS, TMessage, OnGetFormCustomers);
	END_MESSAGE_MAP(TForm)

};

//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
