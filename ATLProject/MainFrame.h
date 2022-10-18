#pragma once
#include "Document.h"
#include "View.h"

class CMainFrame : public CWindowImpl<CMainFrame> 
{
    private :
        CView *m_pCurrentView ; 
        HMENU m_hMainMemu ; 
    public :
        CMainFrame() ; 
        ~CMainFrame() ; 
    public :
        DECLARE_WND_CLASS(_T("MainFrame"))

        BEGIN_MSG_MAP(CMainFrame)
            MESSAGE_HANDLER(WM_CREATE, OnCreate)
            COMMAND_ID_HANDLER(ID_VIEW_CLASSVIEW, OnViewClassView)
            COMMAND_ID_HANDLER(ID_VIEW_TERMINALVIEW, OnViewTerminalView)
            COMMAND_ID_HANDLER(ID_VIEW_ERRORVIEW, OnErrorView)
            MESSAGE_HANDLER(WM_PAINT, OnPaint) 
            MESSAGE_HANDLER(WM_SIZE, OnSize) 
            MESSAGE_HANDLER(WM_DESTROY, OnDestroy) 
        END_MSG_MAP() 
    public : // Main Message Handler
        LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
    public : // Main Menu Handler
        LRESULT OnViewClassView(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL &bHandled) ; 
        LRESULT OnViewTerminalView(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL &bHandled) ; 
        LRESULT OnErrorView(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL &bHandled) ; 
    public :
        void ShowCurrentView(const CString &strViewKey) ; 
} ;

