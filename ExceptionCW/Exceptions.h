#pragma once
#include <iostream>
using std::string;

class MyException
{
    string message;
    double badSide;
public:
    MyException(const string& message = "Unknown error", const double& badSide = 0)
        : message{ message }, badSide{ badSide }
    {
    }
    virtual const string& what() const { return message; }
    virtual const double& getBadSide() const { return badSide; }
};

class NegativeWidthException : public MyException
{
public:
    NegativeWidthException(const string& message = "Width is negative", const double& badSide = 0)
        : MyException(message, badSide)
    {
    }
};

class NegativeLengthException : public MyException
{
public:
    NegativeLengthException(const string& message = "Length is negative", const double& badSide = 0)
        : MyException(message, badSide)
    {
    }
};

class ZeroWidthException : public MyException
{
public:
    ZeroWidthException(const string& message = "Width is zero", const double& badSide = 0)
        : MyException(message, badSide)
    {
    }
};

class ZeroLengthException : public MyException
{
public:
    ZeroLengthException(const string& message = "Length is zero", const double& badSide = 0)
        : MyException(message, badSide)
    {
    }
};