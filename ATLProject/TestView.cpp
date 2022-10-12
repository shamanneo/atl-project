#include "pch.h"
#include "TestView.h"

CTestView::CTestView() 
{

} 

CTestView::~CTestView()
{

} 

void CTestView::Draw(HDC hDC) 
{
    CString str ; 
    TextOut(hDC, 100, 100, str, str.GetLength()) ; 
} 
