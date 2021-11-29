/******************************************************************************
	author:	Francesco Settembrini
	last update: 08/11/2021, 28/11/2021
	e-mail:	mailto:francesco.settembrini@poliba.it
******************************************************************************/


#ifndef TFormQuerySupplyAndDemandH
#define TFormQuerySupplyAndDemandH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>

#include <map>

#include "databanker.h"

//---------------------------------------------------------------------------
class TFormQuerySupplyAndDemand : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelBottom;
	TButton *ButtonClose;
	TPanel *PanelCustomers;
	TPanel *Panel10;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *PanelClient;
	TLabel *LabelCustomers;
	TLabel *LabelAssets;
	TPanel *Panel3;
	TLabel *LabelCustomersResults;
	TPanel *Panel4;
	TLabel *LabelAssetsResults;
	TStringGrid *GridCustomers;
	TStringGrid *GridAssets;
	TPanel *PanelAssets;
	TPanel *Panel6;
	TComboBox *ComboBoxTypology;
	TComboBox *ComboBoxAssetsSorting;
	TLabel *Label9;
	TLabel *Label4;
	TComboBox *ComboBoxAssetsRegion;
	TLabel *Label2;
	TLabel *Label3;
	TPanel *Panel5;
	TPanel *Panel7;
	TButton *ButtonUpdate;
	TLabel *Label10;
	TComboBox *ComboBoxCustomersSorting;
	TLabel *Label11;
	TComboBox *ComboBoxCustomersRegion;
	TLabel *Label5;
	TComboBox *ComboBoxBudget;
	TLabel *Label8;
	TComboBox *ComboBoxOwnership;
	TLabel *Label1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
	void __fastcall FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight, bool &Resize);
	void __fastcall ButtonUpdateClick(TObject *Sender);
	void __fastcall GridCustomersDblClick(TObject *Sender);
	void __fastcall GridCustomersClick(TObject *Sender);
	void __fastcall GridAssetsDblClick(TObject *Sender);


private:	// User declarations

public:		// User declarations
	__fastcall TFormQuerySupplyAndDemand(TComponent* Owner, TDataBanker* pDB, HWND hWndMsgs = 0);

protected:
HWND m_hWndMsgs;
	TDataBanker* m_pDB;
	TVecPtrAssets m_QueryAssets;
    TVecPtrCustomers m_QueryCustomers;
	std::map<AnsiString, AnsiString> m_MapCapRegions;

    void __fastcall Clear();
	bool __fastcall ValidateInput();

	void __fastcall Setup();
	void __fastcall SetupTheAssetsGrid();
    void __fastcall SetupTheCustomersGrid();
	void __fastcall ClearAssetsGrid();
    void __fastcall ClearCustomersGrid();

    void __fastcall Update();
	void __fastcall UpdateCustomers();
	void __fastcall UpdateAssets(TCustomer* pCustomer);

    void __fastcall PrintAssets(TVecPtrAssets& Assets);
    void __fastcall PrintCustomers(TVecPtrCustomers& Customers);
};

//---------------------------------------------------------------------------
//extern PACKAGE TFormQuerySalesHist *FormQuerySalesHist;
//---------------------------------------------------------------------------
#endif
