#include "pch.h"
#include "ClassView.h"

CClassView::CClassView(CContent &Content)
    : m_Content(Content) 
{

}

CClassView::~CClassView()
{

}

void CClassView::Draw(HDC hDC) 
{
    CString strText = _T("ClassView") ; 
    ::TextOut(hDC, 30, 30, strText, strText.GetLength()) ;
}

void CClassView::OnFinalMessage(HWND hWnd)
{
    delete this ; 
}