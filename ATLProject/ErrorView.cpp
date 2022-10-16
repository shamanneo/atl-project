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

}

void CErrorView::OnFinalMessage(HWND hWnd)
{
    delete this ; 
}