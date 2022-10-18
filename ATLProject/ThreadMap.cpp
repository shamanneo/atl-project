#include "pch.h"
#include "ThreadMap.h"

CThreadMap::CThreadMap()
{

}

CThreadMap::~CThreadMap()
{

}

CAtlMap<CString, HANDLE> &CThreadMap::GetThreadMap() 
{
    return m_Threads ; 
}

void CThreadMap::Add(const CString &strKey, HANDLE hThread) 
{
    m_Threads.SetAt(strKey, hThread) ; 
}

void CThreadMap::RemoveAll()
{
    HANDLE hTempThread = nullptr ; 
    POSITION pos = m_Threads.GetStartPosition() ; 
    while(pos != NULL)
    {
        hTempThread = m_Threads.GetNext(pos) ; 
        ::CloseHandle(hTempThread) ; 
    }
    m_Threads.RemoveAll() ; 
}

void CThreadMap::WaitForAll() 
{

}