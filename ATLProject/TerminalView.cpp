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

}

void CTerminalView::OnFinalMessage(HWND hWnd)
{
    delete this ; 
}