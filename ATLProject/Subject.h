#pragma once
#include "View.h"

class ISubject
{
    public :
        ISubject() { }  ;
        virtual ~ISubject() { } ; 
    public :
        virtual void RegisterView(CAutoPtr<CView> apView) = 0 ;
        virtual void UnregisterView(CAutoPtr<CView> apView) = 0 ; 
        virtual void UpdateView() = 0 ;
} ;

