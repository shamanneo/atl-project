#pragma once
#include "View.h"

class CDocument
{
    private :
        CAutoPtr<CView> m_apView ; 
    public :
        CDocument() ; 
        ~CDocument() ; 
    public :
        void Do(CString &str) ; 
} ;

