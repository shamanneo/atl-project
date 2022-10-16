#pragma once
#include "Document.h" 
#include "MainFrame.h"

class CMainApp
{
    private :
        CMainFrame m_MainFrame ; 
        CDocument m_MainDoc ; 
        HMENU m_hMainMenu ; 
    public :
        CMainApp() ; 
        ~CMainApp() ; 
    public :
        int Run(HINSTANCE hInstance, int nCmdShow) ; 
    public :
        CDocument &GetMainDocument() ;
    public :    
        static CMainApp &GetInstance() ; 
        static void Release() ; 
} ;

