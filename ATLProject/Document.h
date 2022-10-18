#pragma once
#include "View.h"
#include "Subject.h"
#include "Content.h"

class CDocument : public CSubject
{
    private :
        CAtlMap<CString, CView *> m_Views ; 
        CContent m_Content ; 
    public :
        CDocument() ; 
        ~CDocument() ; 
    public :
        virtual void RegisterView(const CString &strKey, CView *pView) override ; 
        virtual void UnregisterView(const CString &strKey) override ; 
        virtual void UpdateView(UINT nWidth, UINT nHeight) override ; 
    public :
        void LoadFileContent() ; 
        inline CContent &GetContent() ;
        inline CView *GetView(const CString &strKey) ; 
} ;

inline CContent &CDocument::GetContent() 
{
    return m_Content ; 
}

inline CView *CDocument::GetView(const CString &strKey)
{
    return m_Views[strKey] ; 
}


