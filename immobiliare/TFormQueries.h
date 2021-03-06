/******************************************************************************
	author:	Francesco Settembrini
	last update: 08/11/2021, 28/11/2021
	e-mail:	mailto:francesco.settembrini@poliba.it
******************************************************************************/

#ifndef TFormQueriesH
#define TFormQueriesH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>


#include "databanker.h"
#include <Vcl.ExtCtrls.hpp>


//---------------------------------------------------------------------------
class TFormQueries : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelBottom;
	TPanel *PanelTop;
	TButton *ButtonClose;
	TListBox *ListBox;
	TLabel *LabelInfo;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
	void __fastcall FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight, bool &Resize);
	void __fastcall ListBoxDblClick(TObject *Sender);


private:	// User declarations

public:		// User declarations
	__fastcall TFormQueries(TComponent* Owner, TDataBanker* pDB, HWND hWndMsgs = 0);

protected:
	HWND m_hWndMsgs;
	TDataBanker *m_pDB;

	void __fastcall Setup();
};

//---------------------------------------------------------------------------
#endif


