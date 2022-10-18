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
    MainDoc.RegisterView(_T("ClassView"), pClassView) ; 
    CView *pTerminalView = new CTerminalView { MainDoc.GetContent() } ; 
    pTerminalView->Create(
        m_hWnd,
        rcView,
        _T("TerminalView"),
        DXL_WS_CHILDWINDOW,
        WS_EX_CLIENTEDGE
    ) ; 
    MainDoc.RegisterView(_T("TerminalView"), pTerminalView) ; 
    CView *pErrorView = new CErrorView { MainDoc.GetContent() } ; 
    pErrorView->Create(
        m_hWnd,
        rcView,
        _T("ErrorView"),
        DXL_WS_CHILDWINDOW,
        WS_EX_CLIENTEDGE
    ) ; 
    MainDoc.RegisterView(_T("ErrorView"), pErrorView) ;
    return 0 ; 
}

LRESULT CMainFrame::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    PAINTSTRUCT ps ; 
    HDC hDC = BeginPaint(&ps) ; 

    EndPaint(&ps) ; 
    return 0 ; 
}

LRESULT CMainFrame::OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    if(m_pCurrentView != nullptr)
    {
        UINT nWidth = LOWORD(lParam) ; 
        UINT nHeight = HIWORD(lParam) ; 
        m_pCurrentView->SetWindowPos(NULL, 0, 0, nWidth / 5, nHeight, 
            SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE) ; 
    }
    return 0 ; 
}

LRESULT CMainFrame::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/)
{
    PostQuitMessage(0) ; 
    return 0 ; 
}

LRESULT CMainFrame::OnViewClassView(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL &bHandled) 
{
    SetCurrentView(_T("ClassView")) ; 
    return 0 ;
}

LRESULT CMainFrame::OnViewTerminalView(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL &bHandled) 
{
    SetCurrentView(_T("TerminalView")) ; 
    return 0 ; 
}

LRESULT CMainFrame::OnErrorView(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL &bHandled) 
{
    SetCurrentView(_T("ErrorView")) ; 
    return 0 ; 
}

void CMainFrame::SetCurrentView(const CString &strViewKey) 
{
    CDocument &MainDoc = CMainApp::GetInstance().GetMainDocument() ; 
    CView *pPrevView = m_pCurrentView ; 
    m_pCurrentView = MainDoc.GetView(strViewKey) ; 
    if(pPrevView == m_pCurrentView)
    {
        return ; 
    }
    m_pCurrentView->ShowWindow(SW_SHOW) ; 
    if(pPrevView != nullptr)
    {
        pPrevView->ShowWindow(SW_HIDE) ; 
    }
}
