//---------------------------------------------------------------------------
#include <windows.h>
#pragma hdrstop

#include "TFormDebug.h"
#include "TFormAssets.h"
#include "TFormCustomers.h"
#include "TFormFindAssets.h"
#include "TFormFindCustomers.h"

#include "TFormQueries.h"
#include "TFormQuerySales.h"
#include "TFormQuerySalesHist.h"
#include "TFormQuerySupplyAndDemand.h"

#include "libgui.h"
#include "databanker.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)


/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_ShowHello()
{
	::MessageBeep(-1);
    ::MessageBox(0, L"Hello World!", L"Info:", MB_OK | MB_ICONINFORMATION | MB_TASKMODAL);
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_ShowMessage(LPCSTR pMessage)
{
	::MessageBox(0,
    	//strMessage.c_str(),
        //pMessage,
        L"message",
        L"Info:",
        MB_OK | MB_ICONINFORMATION | MB_TOPMOST | MB_TASKMODAL);
}

/*!****************************************************************************
* @brief
******************************************************************************/
HWND WINAPI __stdcall libgui_GetHandle(LPVOID pForm)
{
	assert(pForm);

    return (HWND) static_cast<TForm*>(pForm)->Handle;
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_Show(LPVOID pForm)
{
	assert(pForm);

    static_cast<TForm*>(pForm)->Show();
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_Hide(LPVOID pForm)
{
	assert(pForm);

    static_cast<TForm*>(pForm)->Hide();
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_Move(LPVOID pForm, int nLeft, int nTop,
	int nWidth, int nHeight)
{
	assert(pForm);

    static_cast<TForm*>(pForm)->Left = nLeft;
    static_cast<TForm*>(pForm)->Top = nTop;
    static_cast<TForm*>(pForm)->Width = nWidth;
    static_cast<TForm*>(pForm)->Height = nHeight;
}


/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_ShowModal(LPVOID pForm)
{
	assert(pForm);

    static_cast<TForm*>(pForm)->ShowModal();
}

/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_CreateFormDebug()
{
	TFormDebug *pFormDebug = new TFormDebug(NULL);
    assert(pFormDebug);
    pFormDebug->FormStyle = fsStayOnTop;
    pFormDebug->Width = 340;
    pFormDebug->Height = 480;

    return (LPVOID) pFormDebug;
}

/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_DebugPrint(LPVOID pForm, LPCSTR pString)
{
	assert(pForm);

    static_cast<TFormDebug*>(pForm)->Print(AnsiString(pString));
}

/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_CreateFormAssets(TDataBanker* pDB, HWND hWndMsgs)
{
	assert(pDB);

	TFormAssets *pFormAssets = new TFormAssets(NULL, pDB, hWndMsgs);
    assert(pFormAssets);
	//pFormAssets->Show();

    return (LPVOID) pFormAssets;
}

/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_CreateFormCustomers(TDataBanker* pDB, HWND hWndMsgs)
{
	assert(pDB);

	TFormCustomers *pFormCustomers = new TFormCustomers(NULL, pDB, hWndMsgs);
    assert(pFormCustomers);

    return (LPVOID) pFormCustomers;
}

/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_CreateFormFindAssets(TDataBanker* pDB, HWND hWndMsgs)
{
	assert(pDB);

	TFormFindAssets *pFormFindAssets = new TFormFindAssets(NULL, pDB, hWndMsgs);
    assert(pFormFindAssets);

    return (LPVOID) pFormFindAssets;
}

/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_CreateFormFindCustomers(TDataBanker* pDB, HWND hWndMsgs)
{
	assert(pDB);

	TFormFindCustomers *pFormFindCustomers = new TFormFindCustomers(NULL, pDB, hWndMsgs);
    assert(pFormFindCustomers);

    return (LPVOID) pFormFindCustomers;
}

/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_CreateFormQueries(TDataBanker* pDB, HWND hWndMsgs)
{
	assert(pDB);

	TFormQueries *pFormQueries = new TFormQueries(NULL, pDB, hWndMsgs);
    assert(pFormQueries);

    return (LPVOID) pFormQueries;
}

/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_CreateFormQuerySales(TDataBanker* pDB)
{
	assert(pDB);

	TFormQuerySales *pFormQuerySales = new TFormQuerySales(NULL, pDB);
    assert(pFormQuerySales);

    return (LPVOID) pFormQuerySales;
}

/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_CreateFormQuerySalesHist(TDataBanker* pDB)
{
	assert(pDB);

	TFormQuerySalesHist *pFormQuerySalesHist = new TFormQuerySalesHist(NULL, pDB);
    assert(pFormQuerySalesHist);

    return (LPVOID) pFormQuerySalesHist;
}

/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_CreateFormQuerySupplyAndDemand(TDataBanker* pDB, HWND hWndMsgs)
{
	assert(pDB);

	TFormQuerySupplyAndDemand *pFormQuerySupplyAndDemand =
    	new TFormQuerySupplyAndDemand(NULL, pDB, hWndMsgs);

    assert(pFormQuerySupplyAndDemand);

    return (LPVOID) pFormQuerySupplyAndDemand;
}

/*!****************************************************************************
* @brief
******************************************************************************/
LPVOID WINAPI __stdcall libgui_DBCreate()
{
	TDataBanker *pDB = new TDataBanker();
    assert(pDB);

    return (LPVOID) pDB;
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DBCitiesLoadFromFile(LPVOID pDB, LPCSTR pFileName)
{
	assert(pDB);

    static_cast<TDataBanker*>(pDB)->CitiesLoadFromFile(pFileName);
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DBAssetsLoadFromFile(LPVOID pDB, LPCSTR pFileName)
{
	assert(pDB);

    static_cast<TDataBanker*>(pDB)->AssetsLoadFromFile(pFileName);
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DBCustomersLoadFromFile(LPVOID pDB, LPCSTR pFileName)
{
	assert(pDB);

    static_cast<TDataBanker*>(pDB)->CustomersLoadFromFile(pFileName);
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DBAssetsSaveToFile(LPVOID pDB, LPCSTR pFileName)
{
	assert(pDB);

    static_cast<TDataBanker*>(pDB)->AssetsSaveToFile(pFileName);

}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DBCustomersSaveToFile(LPVOID pDB, LPCSTR pFileName)
{
	assert(pDB);

    static_cast<TDataBanker*>(pDB)->CustomersSaveToFile(pFileName);
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DBAssetsCreateArchive(LPVOID pDB)
{
	assert(pDB);

    static_cast<TDataBanker*>(pDB)->AssetsCreateArchive();
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DBCustomersCreateArchive(LPVOID pDB)
{
	assert(pDB);

    static_cast<TDataBanker*>(pDB)->CustomersCreateArchive();
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DestroyFormDebug(LPVOID pForm)
{
	assert(pForm);

    delete static_cast<TFormDebug*>(pForm);
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DestroyFormAssets(LPVOID pForm)
{
	assert(pForm);

    delete static_cast<TFormAssets*>(pForm);
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DestroyFormCustomers(LPVOID pForm)
{
	assert(pForm);

    delete static_cast<TFormCustomers*>(pForm);
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DestroyFormFindAssets(LPVOID pForm)
{
	assert(pForm);

    delete static_cast<TFormFindAssets*>(pForm);
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DestroyFormFindCustomers(LPVOID pForm)
{
	assert(pForm);

    delete static_cast<TFormFindCustomers*>(pForm);
}

/*!****************************************************************************
* @brief
******************************************************************************/
VOID WINAPI __stdcall libgui_DestroyFormQueries(LPVOID pForm)
{
	assert(pForm);

    delete static_cast<TFormQueries*>(pForm);
}

BOOL WINAPI __stdcall libgui_DBHaveAssets(LPVOID pDB)
{
	assert(pDB);

    return BOOL(static_cast<TDataBanker*>(pDB)->HaveAssets());
}

BOOL WINAPI __stdcall libgui_DBHaveCustomers(LPVOID pDB)
{
	assert(pDB);

    return BOOL(static_cast<TDataBanker*>(pDB)->HaveCustomers());

}

