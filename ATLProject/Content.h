#pragma once

class CContent
{
    private :
        CString m_strText ;
    public :
        inline const CString &GetText() const ; 
        inline void SetText(const CString &strText) ; 
} ;

inline const CString &CContent::GetText() const 
{
    return m_strText ; 
}

inline void CContent::SetText(const CString &strText) 
{
    m_strText = strText ; 
}
