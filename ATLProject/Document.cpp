#include "pch.h"
#include "Document.h"

CDocument::CDocument() 
{

} 

CDocument::~CDocument()
{
    if(!m_Views.IsEmpty())
    {
        m_Views.RemoveAll() ; 
    }
}

void CDocument::RegisterView(CView *pView) 
{
    m_Views.AddTail(pView) ; 
}

void CDocument::UnregisterView(CView *pView) 
{
    if(!m_Views.IsEmpty())
    {
        POSITION pos = m_Views.Find(pView) ; 
        if(pos != NULL)
        {
            m_Views.RemoveAt(pos) ; 
        }
    }
}

void CDocument::UpdateView() 
{
    POSITION pos = m_Views.GetHeadPosition() ; 
    while(pos != NULL)
    {
        HWND hWnd = m_Views.GetNext(pos)->m_hWnd ; 
        ::InvalidateRect(hWnd, nullptr, TRUE) ; 
        ::UpdateWindow(hWnd) ; 
    }
}

void CDocument::LoadFileContent()
{
    constexpr DWORD nBufSize = 30 ; 
    DWORD nBytesRead = 0 ;
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
