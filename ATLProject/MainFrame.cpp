#include "pch.h"
#include "TestView.h"
#include "MainApp.h"
#include "MainFrame.h"

CMainFrame::CMainFrame()
{

}

CMainFrame::~CMainFrame()
{

}

LRESULT CMainFrame::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    CRect rc ;
    GetClientRect(&rc) ;
    CRect rcView { 0, 0, rc.right / 4, rc.bottom } ; 
    constexpr DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS ; 
    CDocument &mainDocument = CMainApp::GetInstance().GetMainDocument() ; 
    CView *pTestView = new CTestView { mainDocument.GetContent() } ; 
    pTestView->Create(
        m_hWnd,
        rcView,
        NULL,
        dwStyle,
        WS_EX_CLIENTEDGE
    ) ; 
    mainDocument.RegisterView(pTestView) ; // First main program example view.
    mainDocument.LoadFileContent() ; 
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

void CMainFrame::OnFinalMessage(HWND hWnd) 
{

}