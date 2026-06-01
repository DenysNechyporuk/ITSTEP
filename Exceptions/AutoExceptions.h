#pragma once
#include <iostream>
using std::string;

class MyException
{
    string message;
    double badValue;
public:
    MyException(const string& message = "Unknown error", const double& badValue = 0)
        : message{ message }, badValue{ badValue }
    {
    }
    virtual const string& what() const { return message; }
    virtual const double& getBadValue() const { return badValue; }
};

class WrongSpeedException : public MyException
{
public:
    WrongSpeedException(const string& message = "Speed exceeds maximum", const double& badValue = 0)
        : MyException(message, badValue)
    {
    }
};

class WrongMaxSpeedException : public MyException
{
public:
    WrongMaxSpeedException(const string& message = "Max speed exceeds 360", const double& badValue = 0)
        : MyException(message, badValue)
    {
    }
};

class InvalidNumberException : public MyException
{
public:
    InvalidNumberException(const string& message = "Invalid car number", const double& badValue = 0)
        : MyException(message, badValue)
    {
    }
};