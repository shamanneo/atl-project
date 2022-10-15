#pragma once

class CContent
{
    private :
        CString m_strText ;
    public :
        const CString &GetText() { return m_strText ; }
        void SetText(const CString &strText) { m_strText = strText ; }
} ;

