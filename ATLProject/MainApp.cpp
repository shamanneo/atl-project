#include "pch.h"
#include "Resource.h"
#include "MainApp.h"

static CMainApp *g_pMainApp = nullptr ; 

CMainApp::CMainApp()
{

}

CMainApp::~CMainApp()
{

}

int CMainApp::Run(HINSTANCE hInstance, int nCmdShow)
{
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ATLPROJECT)) ;
    MSG msg ;
    m_MainFrame.Create(NULL, NULL, _T("ATLProject"), WS_OVERLAPPEDWINDOW, 0) ; 
    m_MainFrame.ShowWindow(nCmdShow) ; 
    m_MainFrame.CenterWindow() ; 
    m_MainFrame.UpdateWindow() ; 
    while(::GetMessage(&msg, nullptr, 0, 0)) // main message loop.
    {
        if(!::TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            ::TranslateMessage(&msg) ;
            ::DispatchMessage(&msg) ;
        }
    }
    return static_cast<int>(msg.wParam) ; 
}

//      static 

CMainApp &CMainApp::GetInstance() 
{
    if(g_pMainApp == nullptr)
    {
        g_pMainApp = new CMainApp ; 
    }
    return *g_pMainApp ; 
}

void CMainApp::Release()
{
    if(g_pMainApp != nullptr)
    {
        delete g_pMainApp ; 
        g_pMainApp = nullptr ; 
    }
}
