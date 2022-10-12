#include "pch.h"
#include "Document.h"
#include "View.h"

CView::CView()
{

}

CView::~CView()
{

}

LRESULT CView::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    PAINTSTRUCT ps ;
    HDC hDC = BeginPaint(&ps) ; 
    Draw(hDC) ; 
    EndPaint(&ps) ; 
    return 0 ; 
}

void CView::Draw(HDC hDC) 
{

} 




