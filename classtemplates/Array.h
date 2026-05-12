#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Array
{
    T* data;
    int size;
    int upperBound;
    int grow;

public:
    Array(int size = 0, int grow = 1);
    Array(const Array<T>& other);
    ~Array();

    int GetSize() const;
    void SetSize(int size, int grow = 1);
    int GetUpperBound() const;
    bool IsEmpty() const;
    void FreeExtra();
    void RemoveAll();

    T GetAt(int index) const;
    void SetAt(int index, T value);
    T& operator[](int index);
    const T& operator[](int index) const;

    void Add(T value);
    void Append(const Array<T>& other);
    Array<T>& operator=(const Array<T>& other);

    T* GetData() const;

    void InsertAt(int index, T value);
    void RemoveAt(int index);

    void Print() const;
};

//1
template <typename T>
Array<T>::Array(int size, int grow)
{
    this->grow = grow;
    this->size = size;
    this->upperBound = -1;
    if (size > 0)
        data = new T[size];
    else
        data = nullptr;
}

//2
template <typename T>
Array<T>::Array(const Array<T>& other)
{
    size = other.size;
    upperBound = other.upperBound;
    grow = other.grow;
    if (size > 0)
    {
        data = new T[size];
        for (int i = 0; i <= upperBound; i++)
            data[i] = other.data[i];
    }
    else
        data = nullptr;
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

//3
template <typename T>
int Array<T>::GetSize() const
{
    return size;
}

//4
template <typename T>
void Array<T>::SetSize(int size, int grow)
{
    this->grow = grow;
    if (size == this->size) return;

    T* newData = nullptr;
    if (size > 0)
    {
        newData = new T[size];
        int copyCount = (upperBound + 1 < size) ? upperBound + 1 : size;
        for (int i = 0; i < copyCount; i++)
            newData[i] = data[i];
        if (upperBound >= size)
            upperBound = size - 1;
    }
    else
        upperBound = -1;

    delete[] data;
    data = newData;
    this->size = size;
}

//5
template <typename T>
int Array<T>::GetUpperBound() const
{
    return upperBound;
}

//6
template <typename T>
bool Array<T>::IsEmpty() const
{
    return upperBound == -1;
}

//7
template <typename T>
void Array<T>::FreeExtra()
{
    if (upperBound + 1 == size) return;
    int newSize = upperBound + 1;
    T* newData = nullptr;
    if (newSize > 0)
    {
        newData = new T[newSize];
        for (int i = 0; i <= upperBound; i++)
            newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size = newSize;
}

//8
template <typename T>
void Array<T>::RemoveAll()
{
    delete[] data;
    data = nullptr;
    size = 0;
    upperBound = -1;
}

//9
template <typename T>
T Array<T>::GetAt(int index) const
{
    return data[index];
}

//10
template <typename T>
void Array<T>::SetAt(int index, T value)
{
    if (index < size)
        data[index] = value;
}

//11
template <typename T>
T& Array<T>::operator[](int index)
{
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
    return data[index];
}

//12
template <typename T>
void Array<T>::Add(T value)
{
    if (upperBound + 1 >= size)
        SetSize(size + grow, grow);
    data[++upperBound] = value;
}

//13
template <typename T>
void Array<T>::Append(const Array<T>& other)
{
    for (int i = 0; i <= other.upperBound; i++)
        Add(other.data[i]);
}

//14
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    upperBound = other.upperBound;
    grow = other.grow;
    if (size > 0)
    {
        data = new T[size];
        for (int i = 0; i <= upperBound; i++)
            data[i] = other.data[i];
    }
    else
        data = nullptr;
    return *this;
}

//15
template <typename T>
T* Array<T>::GetData() const
{
    return data;
}

//16
template <typename T>
void Array<T>::InsertAt(int index, T value)
{
    Add(data[upperBound]);
    for (int i = upperBound - 1; i > index; i--)
        data[i] = data[i - 1];
    data[index] = value;
}

//17
template <typename T>
void Array<T>::RemoveAt(int index)
{
    for (int i = index; i < upperBound; i++)
        data[i] = data[i + 1];
    --upperBound;
}

//18
template <typename T>
void Array<T>::Print() const
{
    cout << "Size :: " << size << ", UpperBound :: " << upperBound << endl;
    cout << "Elements :: ";
    for (int i = 0; i <= upperBound; i++)
        cout << data[i] << " ";
    cout << endl;
}