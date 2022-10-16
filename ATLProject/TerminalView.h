#pragma once
#include "View.h"
#include "Content.h"

class CTerminalView : public CView
{
    private :
        CContent &m_Content ; 
    public :
        CTerminalView(CContent &Content) ;
        virtual ~CTerminalView() override ; 
    public :
        virtual void Draw(HDC hDC) override ;
        virtual void OnFinalMessage(HWND hWnd) override ; 
} ;