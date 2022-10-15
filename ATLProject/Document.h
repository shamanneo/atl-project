#pragma once
#include "View.h"
#include "Subject.h"
#include "Content.h"

class CDocument : public CSubject
{
    private :
        CAutoPtrList<CView> m_views ; 
        CContent m_Content ; 
    public :
        CDocument() ; 
        ~CDocument() ; 
    public :
        virtual void RegisterView(CView *pView) override ; 
        virtual void UnregisterView(CView *pView) override ; 
        virtual void UpdateView() override ; 
    public :
        void LoadFileContent() ; 
        CContent &GetContent() { return m_Content ; }
} ;

