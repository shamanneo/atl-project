#pragma once
#include "View.h"
#include "Subject.h"

class CDocument : public ISubject
{
    private :
        CAtlList<CAutoPtr<CView>> m_views ; 
    public :
        CDocument() ; 
        ~CDocument() ; 
    public :
        virtual void RegisterView(CAutoPtr<CView> apView) override ; 
        virtual void UnregisterView(CAutoPtr<CView> apView) override ; 
        virtual void UpdateView() override ; 
} ;

