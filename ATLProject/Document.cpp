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

void CDocument::RegisterView(CView *pView) 
{
    CAutoPtr<CView> apView { pView } ; 
    m_views.AddTail(apView) ; 
}

void CDocument::UnregisterView(CView *pView) 
{
    CAutoPtr<CView> apView { pView } ; 
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
        HWND hWnd = m_views.GetNext(pos)->m_hWnd ; 
        ::InvalidateRect(hWnd, nullptr, TRUE) ; 
        ::UpdateWindow(hWnd) ; 
    }
}

void CDocument::LoadFileContent()
{
    constexpr DWORD nBufSize = 30 ; 
    DWORD nBytesRead = 10 ; 
    CAtlFile file ; 
    char szBuffer[nBufSize] { } ; 
    HRESULT hResult = file.Create(_T("contents"), GENERIC_READ, NULL, OPEN_EXISTING) ;
    if(hResult == S_OK)
    {
        hResult = file.Read(szBuffer, nBufSize, nBytesRead) ; 
        if(hResult == S_OK)
        {
            CString strText { szBuffer } ;
            m_Content.SetText(strText) ;
            UpdateView() ; 
        }
    }
    else 
    {
        ATLASSERT(0) ; 
    }
}
