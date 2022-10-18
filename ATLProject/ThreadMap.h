#pragma once

class CThreadMap
{
    private :   
        CAtlMap<CString, HANDLE> m_Threads ; 
    public :
        CThreadMap() ; 
        ~CThreadMap() ; 
    public :
        CAtlMap<CString, HANDLE> &GetThreadMap() ; 
    public :
        void Add(const CString &strKey, HANDLE hThread) ; 
        void RemoveAll() ; 
        void WaitForAll() ; 
} ;

