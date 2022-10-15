#pragma once
#include "Document.h"
#include "Content.h"
#include "View.h"

class CTestView : public CView 
{
    private :
        CContent &m_Content ;
    public :
        CTestView(CContent &Content) ; 
        virtual ~CTestView() override ;
    public :
        virtual void Draw(HDC hDC) override ; 
} ;


