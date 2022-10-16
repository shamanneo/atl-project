#pragma once
#include "View.h"
#include "Content.h"

class CClassView : public CView
{
    private :
        CContent &m_Content ; 
    public :
        CClassView(CContent &Content) ;
        virtual ~CClassView() override ; 
    public :
        virtual void Draw(HDC hDC) override ;
        virtual void OnFinalMessage(HWND hWnd) override ; 
} ;

