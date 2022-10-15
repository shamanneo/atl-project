#include "pch.h"
#include "TestView.h"

CTestView::CTestView(CContent &Content) 
    : m_Content(Content)
{

} 

CTestView::~CTestView()
{

} 

void CTestView::Draw(HDC hDC) 
{
    CString strContent = _T("Hello, World") ;  
    TextOut(hDC, 30, 30, strContent, strContent.GetLength()) ; 
} 
