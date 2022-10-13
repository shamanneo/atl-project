#pragma once

class IObserver
{
    public :
        virtual ~IObserver() { } ; 
    public :
        virtual void Update() = 0 ; 
} ;

