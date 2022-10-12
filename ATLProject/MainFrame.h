#pragma once

class CMainFrame : public CWindowImpl<CMainFrame> 
{
    public :
        CMainFrame() ; 
        ~CMainFrame() ; 
    public :
        DECLARE_WND_CLASS(_T("Main"))

        BEGIN_MSG_MAP(CMainFrame)
            MESSAGE_HANDLER(WM_COMMAND, OnCommand) 
            MESSAGE_HANDLER(WM_PAINT, OnPaint) 
            MESSAGE_HANDLER(WM_DESTROY, OnDestroy) 
        END_MSG_MAP() 
    public :
        LRESULT OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
} ;

