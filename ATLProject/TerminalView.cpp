#include "pch.h"
#include "TerminalView.h"

CTerminalView::CTerminalView(CContent &Content)
    : m_Content(Content) 
{

}

CTerminalView::~CTerminalView()
{

}

void CTerminalView::Draw(HDC hDC) 
{
    CString strText = _T("TerminalView") ; 
    ::TextOut(hDC, 30, 30, strText, strText.GetLength()) ;
}

void CTerminalView::OnFinalMessage(HWND hWnd)
{
    delete this ; 
}