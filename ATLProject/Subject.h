#pragma once

class ISubject
{
    public :
        ISubject() ;
        virtual ~ISubject() ; 
    public :
        virtual void RegisterObserver() = 0 ;
        virtual void UnregisterObserver() = 0 ; 
        virtual void UpdateObserver() = 0 ;
} ;

