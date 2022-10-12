#include "pch.h"
#include "TestView.h"
#include "MainFrame.h"

CMainFrame::CMainFrame()
{

}

CMainFrame::~CMainFrame()
{

}

LRESULT CMainFrame::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    constexpr DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS ; 
    CRect rc ;
    GetClientRect(&rc) ; 
    CRect rcView { 0, 0, rc.right / 4, rc.bottom } ; 
    m_apView.Attach(new CTestView) ; 
    m_apView->Create(
        m_hWnd, 
        rcView, 
        NULL, 
        dwStyle, 
        WS_EX_CLIENTEDGE) ; 
    return 0 ; 
}

LRESULT CMainFrame::OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
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