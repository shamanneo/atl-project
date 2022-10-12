#include "pch.h"
#include "MainFrame.h"

CMainFrame::CMainFrame()
{

}

CMainFrame::~CMainFrame()
{

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