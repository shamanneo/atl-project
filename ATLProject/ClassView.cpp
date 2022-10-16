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

}

void CClassView::OnFinalMessage(HWND hWnd)
{
    delete this ; 
}