/******************************************************************************
	author:	Francesco Settembrini
	last update: 08/11/2021, 28/11/2021
	e-mail:	mailto:francesco.settembrini@poliba.it
******************************************************************************/

#ifndef TFormFindCustomersH
#define TFormFindCustomersH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>

#include "customers.h"
#include "databanker.h"

//---------------------------------------------------------------------------
class TFormFindCustomers : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelBottom;
	TButton *ButtonClose;
	TPanel *PanelRight;
	TStringGrid *Grid;
	TPanel *PanelInfo;
	TLabel *LabelInfo;
	TPanel *PanelLeft;
	TEdit *EditLastName;
	TEdit *EditBudget;
	TLabel *Label6;
	TComboBox *ComboBoxCity;
	TLabel *Label7;
	TLabel *Label2;
	TEdit *EditFirstName;
	TLabel *Label1;
	TSpeedButton *SpeedButtonFind;
	TLabel *Label3;
	TComboBox *ComboBoxSorting;
	TComboBox *ComboBoxOwnership;
	TLabel *Label4;
	TSpeedButton *SpeedButtonClear;
	TComboBox *ComboBoxBudgetIneq;
	TCheckBox *CheckBoxFirstNameFullMatch;
	TCheckBox *CheckBoxLastNameFullMatch;
	TCheckBox *CheckBoxCityNameFullMatch;
	void __fastcall SpeedButtonFindClick(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SpeedButtonClearClick(TObject *Sender);
	void __fastcall GridDblClick(TObject *Sender);
	void __fastcall FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight, bool &Resize);

private:	// User declarations
public:		// User declarations
	__fastcall TFormFindCustomers(TComponent* Owner, TDataBanker* const pDB, HWND hWndMsgs = 0);

protected:
	TDataBanker *m_pDB;
HWND m_hWndMsgs;
	TVecPtrCustomers m_QueryCustomers;

	void __fastcall Setup();
	void __fastcall DoQuery();

	void __fastcall Clear();
	void __fastcall ClearTheGrid();

    void __fastcall SetupTheGrid();

    void __fastcall PrintResults(TVecPtrCustomers& Customers);
	void __fastcall EditRecord(TVecPtrCustomers& Customers, int nGridSelRow);
};

//---------------------------------------------------------------------------
#endif


