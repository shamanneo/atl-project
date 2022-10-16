#pragma once
#include "View.h"

class CSubject
{
    public :
        virtual ~CSubject() { } ; 
    public :
        virtual void RegisterView(const CString &strKey, CView *pView) = 0 ;
        virtual void UnregisterView(const CString &strKey) = 0 ; 
        virtual void UpdateView() = 0 ;
} ;

