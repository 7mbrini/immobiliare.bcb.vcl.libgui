/*!****************************************************************************

	@file	TFormQuerySales.h
	@file	TFormQuerySales.cpp

	@brief	Form for the "Analysis of mean values for sales"

	@noop	author:	Francesco Settembrini
	@noop	last update: 8/11/2021, 28/11/2021
	@noop	e-mail:	mailto:francesco.settembrini@poliba.it

******************************************************************************/

#include <vcl.h>
#pragma hdrstop

//#include "TFormDebug.h"
#include "TFormQuerySales.h"

#include "commdefs.h"
#include "statistics.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//TFormQuerySalesHist *FormQuerySalesHist;


#define WIDTH		800
#define HEIGHT		540
#define MINWIDTH	780
#define MINHEIGHT	480


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


/*!****************************************************************************
* @brief	Constructor
******************************************************************************/
__fastcall TFormQuerySales::TFormQuerySales(TComponent* Owner, TDataBanker* pDB)
	: TForm(Owner)
{
	assert(pDB);

    m_pDB = pDB;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormQuerySales::FormCreate(TObject *Sender)
{
	Setup();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormQuerySales::Setup()
{
	this->Caption = AnsiString(APPNAME)
    	+ " - Valore medio di mercato degli immobili (in Euro/mq)";

    this->Width = WIDTH;
    this->Height = HEIGHT;
    this->Constraints->MinWidth = MINWIDTH;
    this->Constraints->MinHeight = MINHEIGHT;

	this->Position = poScreenCenter;


										// build the "typology" combobox
    for(int i=0; i<sizeof(g_AssetTypologyChoices)/sizeof(g_AssetTypologyChoices[0]); i++)
    {
		ComboBoxTypology->Items->Add(g_AssetTypologyChoices[i].strName);
    }
	ComboBoxTypology->ItemIndex = atNone;

										// date combobox
	{
		TDate Date(TDate::CurrentDate());

		unsigned short nYear=0, nMonth=0, nDay=0;
        Date.DecodeDate(&nYear, &nMonth, &nDay);

		for(unsigned i=1900; i<=nYear; i++)
        {
        	ComboBoxStartDate->Items->Add(i);
            ComboBoxEndDate->Items->Add(i);
        }

        ComboBoxStartDate->ItemIndex = ComboBoxStartDate->Items->Count - 1 - 10;
        ComboBoxEndDate->ItemIndex = ComboBoxEndDate->Items->Count - 1;
    }

										// regions combobox
	{
		assert(m_pDB);

        TCitiesArchive *pCities = m_pDB->GetCities();
        assert(pCities);

        TVecCities Cities;
        pCities->GetCities(Cities);

        for(int i=0; i<Cities.size(); i++)
        {
			m_MapCapRegions[Cities[i].m_strCap.c_str()] = Cities[i].m_strRegion.c_str();
        }

    	TVecStrings Regions;
        pCities->GetRegions(Regions);

        ComboBoxRegion->Sorted = true;
		ComboBoxRegion->Items->Add("");

        for(int i=0; i<Regions.size(); i++)
        {
        	ComboBoxRegion->Items->Add(Regions[i].c_str());
        }
        ComboBoxRegion->ItemIndex = 0;
    }

    SettingUpTheChart();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormQuerySales::SettingUpTheChart()
{
	Chart->Visible = false;
	Chart->View3D = false;
	Chart->Zoom->Allow = false;
    Chart->Chart3DPercent = 5;
	Chart->Title->Font->Name = "verdana bold";
	Chart->Title->Font->Size = 12;
    Chart->Title->Font->Color = clRed;
	Chart->Title[0].Text->Text = "Valore medio di mercato degli immobili (in Euro/mq)";

	Chart->AutoSize = true;
	Chart->Legend->Visible = true;
	//Chart->BottomAxis->LabelStyle = talText;
	Chart->BottomAxis->LabelStyle = talAuto;
	Chart->BottomAxis->Labels = true;
	Chart->BottomAxis->Visible = true;

	m_pBarSeries = new TBarSeries(Chart);
	assert(m_pBarSeries);
	m_pBarSeries->ParentChart = Chart;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormQuerySales::ButtonCloseClick(TObject *Sender)
{
	ModalResult = mrOk;
    Close();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormQuerySales::FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize)
{
	ButtonClose->Left = (this->Width - ButtonClose->Width)/2;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormQuerySales::ButtonUpdateClick(TObject *Sender)
{
	ClearTheChart();

	if( ValidateInput() )
    {
		Chart->Visible = true;

		Update();
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormQuerySales::SpeedButtonClearClick(TObject *Sender)
{
	Clear();
	ClearTheChart();
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormQuerySales::Clear()
{
	ComboBoxTypology->ItemIndex = 0;
    ComboBoxRegion->ItemIndex = 0;
	ComboBoxStartDate->ItemIndex = ComboBoxStartDate->Items->Count - 1 - 10;
    ComboBoxEndDate->ItemIndex = ComboBoxEndDate->Items->Count - 1;
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormQuerySales::ClearTheChart()
{
	assert(m_pBarSeries);

    m_pBarSeries->Clear();
}

/*!****************************************************************************
* @brief
******************************************************************************/
bool __fastcall TFormQuerySales::ValidateInput()
{
	bool bResult = true;

	unsigned nStartYear = ComboBoxStartDate->Text.ToInt();
    unsigned nEndYear = ComboBoxEndDate->Text.ToInt();

	if( nEndYear < nStartYear )
    {
		::MessageBox(0, L"Error: End Date less than Start Date", L"Error:",
            MB_OK | MB_ICONERROR | MB_TOPMOST | MB_TASKMODAL);

		bResult = false;
    }

	return bResult;
}

/*!****************************************************************************
* @brief
******************************************************************************/
double __fastcall TFormQuerySales::GetMeanPrice(TVecPtrAssets& Assets, int nYear)
{
	TVecDoubles Mean;

	double StartDate = TDate(nYear, 1, 1).Val;
    double EndDate = TDate(nYear, 12, 31).Val;

	for(int i=0; i<Assets.size(); i++)
    {
		if( (Assets[i]->m_SoldDate >= StartDate)
        	&& (Assets[i]->m_SoldDate <= EndDate)
    	)
        {
			Mean.push_back(Assets[i]->m_nArea > 0 ?
            	Assets[i]->m_nPrice/double(Assets[i]->m_nArea) : 0);
        }
    }

	return double( Mean.size() ? stats::Mean(Mean) : 0 );
}

/*!****************************************************************************
* @brief	Updates the results based on UI controls values
******************************************************************************/
void __fastcall TFormQuerySales::Update()
{
	assert(m_pDB);

    TAssetsArchive* pAssets = m_pDB->GetAssets();
    assert(pAssets);

    TVecPtrAssets QueryResults = pAssets->GetAssets();

    if( QueryResults.size() )
    {
											// first of all select
                                            // the sold out assets
        {
            TVecPtrAssets TempQuery = QueryResults;

            QueryResults.clear();

            for(int i=0; i<TempQuery.size(); i++)
            {
                if( TempQuery[i]->m_nStatus == asSoldOut )
                {
                    QueryResults.push_back(TempQuery[i]);
                }
            }
        }
											// filter by typology
		enAssetTypology nTypology =
        	g_AssetTypologyChoices[ ComboBoxTypology->ItemIndex ].nTypology;

        if( nTypology != atNone )
        {
            TVecPtrAssets TempQuery = QueryResults;

            QueryResults.clear();

            for(int i=0; i<TempQuery.size(); i++)
            {
                if( TempQuery[i]->m_nTypology == nTypology )
                {
                    QueryResults.push_back(TempQuery[i]);
                }
            }
        }
											// filter by date
		{
			double StartDate = TDate(ComboBoxStartDate->Text.ToInt(), 1, 1).Val;
            double EndDate = TDate(ComboBoxEndDate->Text.ToInt(), 12, 31).Val;

            TVecPtrAssets TempQuery = QueryResults;

            QueryResults.clear();

            for(int i=0; i<TempQuery.size(); i++)
            {
                if( (TempQuery[i]->m_SoldDate >= StartDate)
                	&& (TempQuery[i]->m_SoldDate <= EndDate)
                )
                {
                    QueryResults.push_back(TempQuery[i]);
                }
            }
        }
											// filter by region
		if( ComboBoxRegion->Text.Length() )
        {
            TVecPtrAssets TempQuery = QueryResults;

            QueryResults.clear();

            for(int i=0; i<TempQuery.size(); i++)
            {
				if( m_MapCapRegions[ TempQuery[i]->m_nCap ].LowerCase() ==
					ComboBoxRegion->Text.LowerCase() )
                {
					QueryResults.push_back(TempQuery[i]);
                }
            }
        }
                                            // update the chart
		if( QueryResults.size() )
		{
			UpdateTheChart(QueryResults);

/*
#ifdef _DEBUG
AnsiString strTemp;
strTemp.sprintf("total: %d record", QueryResults.size());
FormDebug->Print(strTemp);
#endif
*/
        }
		else
        {
			::MessageBox(0, L"No records found!", L"Info:",
            	MB_OK | MB_ICONINFORMATION | MB_TOPMOST | MB_TASKMODAL);
        }
	}
}

/*!****************************************************************************
* @brief	Updates the Chart
******************************************************************************/
void __fastcall TFormQuerySales::UpdateTheChart(TVecPtrAssets& Assets)
{
    assert(m_pBarSeries);

    int nStartYear = ComboBoxStartDate->Text.ToInt();
    int nEndYear = ComboBoxEndDate->Text.ToInt();

    assert(nEndYear >= nStartYear);

    TVecDoubles MeanValues;

    for(int i=nStartYear; i<=nEndYear; i++)
    {
        MeanValues.push_back( GetMeanPrice(Assets, i) );
    }

    if( MeanValues.size() )
    {
        double Min = stats::Min(MeanValues);
        double Max = stats::Max(MeanValues);

        Chart->BottomAxis->SetMinMax(nStartYear - 0.5, nEndYear + 0.5);
        Chart->BottomAxis->Visible = true;
        Chart->LeftAxis->SetMinMax(0, Max*1.15);

        m_pBarSeries->ShowInLegend = false;
        m_pBarSeries->Marks->Visible = MeanValues.size() <= 100 ? true : false;
        Chart->BottomAxis->LabelsAngle = 45;

        AnsiString strLabel;
        m_pBarSeries->Clear();

        for(int i=0; i<MeanValues.size(); i++)
        {
            m_pBarSeries->AddXY(nStartYear + i, MeanValues[i], strLabel.c_str(), clRed );
        }
	}
}



