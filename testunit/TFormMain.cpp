/*!****************************************************************************

	@file	TFormMain.h
	@file	TFormMain.cpp

	@brief	Main form for the "Immobiliare" project Test Unit

	@noop	author:	Francesco Settembrini
	@noop	last update: 8/11/2021
	@noop	e-mail:	mailto:francesco.settembrini@poliba.it

******************************************************************************/

#include <vcl.h>
#pragma hdrstop

#include "TFormMain.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;

//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner) : TForm(Owner)
{
}

//---------------------------------------------------------------------------
