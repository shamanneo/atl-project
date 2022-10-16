#include "pch.h"
#include "ErrorView.h"

CErrorView::CErrorView(CContent &Content) 
    : m_Content(Content) 
{

}

CErrorView::~CErrorView()
{

}

void CErrorView::Draw(HDC hDC) 
{
    CString strText = _T("ErrorView") ; 
    ::TextOut(hDC, 30, 30, strText, strText.GetLength()) ;
}

void CErrorView::OnFinalMessage(HWND hWnd)
{
    delete this ; 
}