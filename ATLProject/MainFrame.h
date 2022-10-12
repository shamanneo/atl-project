#pragma once
#include "View.h"

class CMainFrame : public CWindowImpl<CMainFrame> 
{
    private :
        CAutoPtr<CView> m_apView ; 
    public :
        CMainFrame() ; 
        ~CMainFrame() ; 
    public :
        DECLARE_WND_CLASS(_T("MainFrame"))

        BEGIN_MSG_MAP(CMainFrame)
            MESSAGE_HANDLER(WM_CREATE, OnCreate)  
            MESSAGE_HANDLER(WM_COMMAND, OnCommand) 
            MESSAGE_HANDLER(WM_PAINT, OnPaint) 
            MESSAGE_HANDLER(WM_DESTROY, OnDestroy) 
        END_MSG_MAP() 
    public :
        LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
} ;

