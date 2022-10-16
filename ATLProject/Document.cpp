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

void CDocument::RegisterView(const CString &strKey, CView *pView) 
{
    m_Views.SetAt(strKey, pView) ; 
}

void CDocument::UnregisterView(const CString &strKey) 
{
    m_Views.RemoveKey(strKey) ; 
}

void CDocument::UpdateView() 
{
    POSITION pos = m_Views.GetStartPosition() ; 
    while(pos != NULL)
    {
        HWND hWnd = m_Views.GetNextValue(pos)->m_hWnd ; 
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
