#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    T* p;
    int count;
public:
    Queue();
    Queue(const Queue<T>& other);
    ~Queue();
    Queue<T>& operator=(const Queue<T>& other);
    void push(const T& value);
    T pop();
    T getItem() const;
    void clear();
    bool isEmpty() const;
    int getN() const;
    void print() const;
};

template <typename T>
Queue<T>::Queue()
{
    p = nullptr;
    count = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other)
{
    count = other.count;
    p = new T[count];
    for (int i = 0; i < count; i++)
        p[i] = other.p[i];
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] p;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if (this == &other) return *this;
    delete[] p;
    count = other.count;
    p = new T[count];
    for (int i = 0; i < count; i++)
        p[i] = other.p[i];
    return *this;
}

template <typename T>
void Queue<T>::push(const T& value)
{
    T* newP = new T[count + 1];
    for (int i = 0; i < count; i++)
        newP[i] = p[i];
    newP[count] = value;
    delete[] p;
    p = newP;
    count++;
}

template <typename T>
T Queue<T>::pop()
{
    T value = p[0];
    T* newP = new T[count - 1];
    for (int i = 1; i < count; i++)
        newP[i - 1] = p[i];
    delete[] p;
    p = newP;
    count--;
    return value;
}

template <typename T>
T Queue<T>::getItem() const
{
    return p[0];
}

template <typename T>
void Queue<T>::clear()
{
    delete[] p;
    p = nullptr;
    count = 0;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return count == 0;
}

template <typename T>
int Queue<T>::getN() const
{
    return count;
}

template <typename T>
void Queue<T>::print() const
{
    cout << "Queue :: ";
    for (int i = 0; i < count; i++)
        cout << p[i] << " ";
    cout << endl;
}