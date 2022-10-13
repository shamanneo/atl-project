#include "pch.h"
#include "Document.h"

CDocument::CDocument() 
{

} 

CDocument::~CDocument()
{
    if(!m_views.IsEmpty())
    {
        m_views.RemoveAll() ; 
    }
}

void CDocument::RegisterView(CAutoPtr<CView> apView) 
{
    m_views.AddTail(apView) ; 
}

void CDocument::UnregisterView(CAutoPtr<CView> apView) 
{
    if(!m_views.IsEmpty())
    {
        POSITION pos = m_views.Find(apView) ; 
        if(pos != NULL)
        {
            m_views.RemoveAt(pos) ; 
        }
    }
}

void CDocument::UpdateView() 
{
    POSITION pos = m_views.GetHeadPosition() ; 
    while(pos != NULL)
    {
        m_views.GetNext(pos)->Draw(NULL) ; 
    }
}
