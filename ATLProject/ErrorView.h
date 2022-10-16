#pragma once
#include "View.h"
#include "Content.h"

class CErrorView : public CView
{
    private :
        CContent &m_Content ; 
    public :
        CErrorView(CContent &Content) ;
        virtual ~CErrorView() override ; 
    public :
        virtual void Draw(HDC hDC) override ;
        virtual void OnFinalMessage(HWND hWnd) override ; 
} ;