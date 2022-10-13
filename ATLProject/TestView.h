#pragma once
#include "Document.h"
#include "View.h"

class CTestView : public CView 
{
    public :
        CTestView() ; 
        virtual ~CTestView() override ;
    public :
        virtual void Draw(HDC hDC) override ; 
} ;


