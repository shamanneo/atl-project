#include "pch.h"
#include "MainApp.h"
#include "ClassView.h"
#include "TerminalView.h"
#include "ErrorView.h"
#include "MainFrame.h"

CMainFrame::CMainFrame()
{
    m_pCurrentView = nullptr ; 
    m_hMainMemu = NULL ; 
}

CMainFrame::~CMainFrame()
{

}

LRESULT CMainFrame::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    CRect rc ;
    GetClientRect(&rc) ;
    CRect rcView { 0, 0, rc.right / 5, rc.bottom } ; 
    CDocument &MainDoc = CMainApp::GetInstance().GetMainDocument() ; 
    CView *pClassView = new CClassView { MainDoc.GetContent() } ; 
    pClassView->Create(
        m_hWnd,
        rcView,
        _T("ClassView"),
        DXL_WS_CHILDWINDOW,
        WS_EX_CLIENTEDGE
    ) ; 
    MainDoc.RegisterView(pClassView) ; 
    CView *pTerminalView = new CTerminalView { MainDoc.GetContent() } ; 
    pTerminalView->Create(
        m_hWnd,
        rcView,
        _T("TerminalView"),
        DXL_WS_CHILDWINDOW | ~WS_VISIBLE,
        WS_EX_CLIENTEDGE
    ) ; 
    MainDoc.RegisterView(pTerminalView) ; 
    CView *pErrorView = new CErrorView { MainDoc.GetContent() } ; 
    pErrorView->Create(
        m_hWnd,
        rcView,
        _T("ErrorView"),
        DXL_WS_CHILDWINDOW | ~WS_VISIBLE,
        WS_EX_CLIENTEDGE
    ) ; 
    MainDoc.RegisterView(pErrorView) ; 
    return 0 ; 
}

LRESULT CMainFrame::OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    switch(HIWORD(wParam)) 
    {
        case DXL_ON_MENU :
        {
            OnMenu(uMsg, wParam, lParam) ; 
            break ; 
        }
        case DXL_ON_ACCELERATOR :
        {
            OnAccelerator(uMsg, wParam, lParam) ; 
            break ; 
        }
        default :
        {
            OnControl(uMsg, wParam, lParam) ; 
            break ; 
        }
    }
    return 0 ; 
}

LRESULT CMainFrame::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    PAINTSTRUCT ps ; 
    HDC hDC = BeginPaint(&ps) ; 

    EndPaint(&ps) ; 
    return 0 ; 
}

LRESULT CMainFrame::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/)
{
    PostQuitMessage(0) ; 
    return 0 ; 
}

void CMainFrame::OnMenu(UINT uMSg, WPARAM wParam, LPARAM lParam) 
{
    switch(LOWORD(wParam))
    {
        case ID_VIEW_CLASSVIEW :
        {
            break ; 
        }
        case ID_VIEW_TERMINALVIEW :
        {
            break ; 
        }
        case ID_VIEW_ERRORVIEW :
        {
            break ; 
        }
        default :
        {
            break ; 
        } 
    }
}

void CMainFrame::OnAccelerator(UINT uMSg, WPARAM wParam, LPARAM lParam) 
{

}

void CMainFrame::OnControl(UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
    
}

