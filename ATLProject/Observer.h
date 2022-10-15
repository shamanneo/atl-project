#pragma once

class CObserver
{
    public :
        virtual ~CObserver() { } ; 
    public :
        virtual void Update() = 0 ; 
} ;

