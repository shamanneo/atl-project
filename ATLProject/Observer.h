#pragma once

class CObserver
{
    public :
        CObserver() = delete ; 
        virtual ~CObserver() { } ; 
    public :
        virtual void Update() = 0 ; 
} ;

