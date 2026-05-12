#pragma once

class TV;

class Remote
{
    TV* tv;

public:
    Remote(TV* tv = nullptr);
    void chooseTV(TV* tv);

    void power();
    Remote& operator++();       
    Remote  operator++(int);    
    Remote& operator--();      
    Remote  operator--(int);   
    void operator+() const;   
    void operator-() const;    
    void goChannel(size_t ch);
};