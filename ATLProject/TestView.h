#pragma once
#include "View.h"

class CTestView : public CView 
{
    private :

    public :
        CTestView() ; 
        virtual ~CTestView() override ;
    public :
        virtual void Draw(HDC hDC) override ; 
} ;

