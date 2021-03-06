/*!****************************************************************************

	@file	TFormDebug.h
	@file	TFormDebug.cpp

	@brief	Debug form

	@noop	author:	Francesco Settembrini
	@noop	last update: 8/11/2021, 28/11/2021
	@noop	e-mail:	mailto:francesco.settembrini@poliba.it

******************************************************************************/

#include <vcl.h>
#pragma hdrstop

#include "TFormDebug.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDebug *FormDebug;


TStringList* g_pDebugList;

/*!****************************************************************************
* @brief	Constructor
******************************************************************************/
__fastcall TFormDebug::TFormDebug(TComponent* Owner) : TForm(Owner)
{
	g_pDebugList = new TStringList;
	assert(g_pDebugList);
}

/*!****************************************************************************
* @brief 	Event fired by UI when creating the form
******************************************************************************/
void __fastcall TFormDebug::FormCreate(TObject *Sender)
{
	RichEdit->ReadOnly = true;
}

/*!****************************************************************************
* @brief	Clears the Edit control
******************************************************************************/
void __fastcall TFormDebug::Clear()
{
	RichEdit->Lines->Clear();
}

/*!****************************************************************************
* @brief	Print a string message in the Edit control
* @param	strMsg The string to be printed
******************************************************************************/
void __fastcall TFormDebug::Print(std::string strMsg)
{
	Print(AnsiString(strMsg.c_str()));
}

/*!****************************************************************************
* @brief	Print a string message in the Edit control
* @param	strMsg The string to be printed
******************************************************************************/
void __fastcall TFormDebug::Print(AnsiString strMsg)
{
	RichEdit->Lines->Add(strMsg);
}

/*!****************************************************************************
* @brief	Print a list of string messages in the Edit control
* @param	pList Pointer to a list of strings to be printed
* @param	nLimits Limiting the number of string to be printed
******************************************************************************/
void __fastcall TFormDebug::Print(TStringList* pList, int nLimits)
{
	int nCount = pList->Count;

	if( (nLimits > 0) && (nLimits < pList->Count) ) nCount = nLimits;

    for(int i=0; i<nCount; i++)
    {
        RichEdit->Lines->Add(pList->Strings[i]);
    }
}

/*!****************************************************************************
* @brief
******************************************************************************/
void __fastcall TFormDebug::ActionsClearClick(TObject *Sender)
{
	Clear();
}

/*!****************************************************************************
* @brief	Saves to file the Edit contents
* @param	Sender Pointer to a UI sender object
******************************************************************************/
void __fastcall TFormDebug::FileSaveAsClick(TObject *Sender)
{
	TFormStyle FS = this->FormStyle;
    this->FormStyle = fsNormal;

	if( SaveDialog->Execute(this->Handle) == mrOk )
	{
		RichEdit->Lines->SaveToFile( SaveDialog->FileName );
	}

	this->FormStyle = FS;
}

//---------------------------------------------------------------------------

