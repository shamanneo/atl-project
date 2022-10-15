#pragma once
#include "View.h"

class CSubject
{
    public :
        CSubject() { }  ;
        virtual ~CSubject() { } ; 
    public :
        virtual void RegisterView(CView *pView) = 0 ;
        virtual void UnregisterView(CView *pView) = 0 ; 
        virtual void UpdateView() = 0 ;
} ;

