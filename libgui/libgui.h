//---------------------------------------------------------------------------
#ifndef libguiH
#define libguiH

#include <windows.h>
//#include <string>
#pragma hdrstop


#ifdef _LIBGUI_BUILD_DLL
	#define LIBGUI __declspec(dllexport)
#else
	#define LIBGUI __declspec(dllimport)
#endif


class TDataBanker;

extern "C"
{
	LIBGUI VOID WINAPI __stdcall libgui_ShowHello();
	LIBGUI VOID WINAPI __stdcall libgui_ShowMessage(LPCSTR pMessage);
	//LIBGUI void __stdcall libgui_ShowMessage(std::string strMessage);

	LIBGUI VOID WINAPI __stdcall libgui_Show(LPVOID pForm);
    LIBGUI VOID WINAPI __stdcall libgui_Hide(LPVOID pForm);
    LIBGUI VOID WINAPI __stdcall libgui_Move(LPVOID pForm,
    	int nLeft, int nTop, int nWidth, int nHeight);
	LIBGUI LPVOID WINAPI __stdcall libgui_ShowModal(LPVOID pForm);
	LIBGUI HWND WINAPI __stdcall libgui_GetHandle(LPVOID pForm);

	LIBGUI LPVOID WINAPI __stdcall libgui_CreateFormDebug();
	LIBGUI LPVOID WINAPI __stdcall libgui_DebugPrint(LPVOID pForm, LPCSTR pString);

	LIBGUI LPVOID WINAPI __stdcall libgui_DBCreate();
	LIBGUI VOID WINAPI __stdcall libgui_DBAssetsCreateArchive(LPVOID pDB);
    LIBGUI VOID WINAPI __stdcall libgui_DBCustomersCreateArchive(LPVOID pDB);
    LIBGUI VOID WINAPI __stdcall libgui_DBCitiesLoadFromFile(LPVOID pDB, LPCSTR pFileName);
    LIBGUI VOID WINAPI __stdcall libgui_DBAssetsLoadFromFile(LPVOID pDB, LPCSTR pFileName);
    LIBGUI VOID WINAPI __stdcall libgui_DBCustomersLoadFromFile(LPVOID pDB, LPCSTR pFileName);
    LIBGUI VOID WINAPI __stdcall libgui_DBAssetsSaveToFile(LPVOID pDB, LPCSTR pFileName);
    LIBGUI VOID WINAPI __stdcall libgui_DBCustomersSaveToFile(LPVOID pDB, LPCSTR pFileName);
    LIBGUI BOOL WINAPI __stdcall libgui_DBHaveAssets(LPVOID pDB);
    LIBGUI BOOL WINAPI __stdcall libgui_DBHaveCustomers(LPVOID pDB);

	LIBGUI LPVOID WINAPI __stdcall libgui_CreateFormAssets(TDataBanker* pDB, HWND hWndMsgs);
	LIBGUI LPVOID WINAPI __stdcall libgui_CreateFormCustomers(TDataBanker* pDB, HWND hWndMsgs);

	LIBGUI LPVOID WINAPI __stdcall libgui_CreateFormFindAssets(TDataBanker* pDB, HWND hWndMsgs);
	LIBGUI LPVOID WINAPI __stdcall libgui_CreateFormFindCustomers(TDataBanker* pDB, HWND hWndMsgs);

	LIBGUI LPVOID WINAPI __stdcall libgui_CreateFormQueries(TDataBanker* pDB, HWND hWndMsgs);
	LIBGUI LPVOID WINAPI __stdcall libgui_CreateFormQuerySales(TDataBanker* pDB);
	LIBGUI LPVOID WINAPI __stdcall libgui_CreateFormQuerySalesHist(TDataBanker* pDB);
    LIBGUI LPVOID WINAPI __stdcall libgui_CreateFormQuerySupplyAndDemand(TDataBanker* pDB, HWND hWndMsgs);

    LIBGUI VOID WINAPI __stdcall libgui_DestroyFormDebug(LPVOID pForm);
    LIBGUI VOID WINAPI __stdcall libgui_DestroyFormAssets(LPVOID pForm);
    LIBGUI VOID WINAPI __stdcall libgui_DestroyFormCustomers(LPVOID lpForm);
    LIBGUI VOID WINAPI __stdcall libgui_DestroyFormFindAssets(LPVOID lpForm);
    LIBGUI VOID WINAPI __stdcall libgui_DestroyFormFindCustomers(LPVOID lpForm);
    LIBGUI VOID WINAPI __stdcall libgui_DestroyFormQueries(LPVOID pForm);
}

//---------------------------------------------------------------------------
#endif


