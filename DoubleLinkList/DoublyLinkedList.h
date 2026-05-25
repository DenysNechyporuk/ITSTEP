#pragma once
#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList
{
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
        Node(T data) : data{ data }, next{ nullptr }, prev{ nullptr } {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head{ nullptr }, tail{ nullptr } {}

    ~DoublyLinkedList()
    {
        DeleteAll();
    }

    void AddToHead(T value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void AddToTail(T value)
    {
        Node* newNode = new Node(value);
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFromHead()
    {
        if (head == nullptr)
            return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
    }

    void DeleteFromTail()
    {
        if (tail == nullptr)
            return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
    }

    void DeleteAll()
    {
        while (head != nullptr)
            DeleteFromHead();
    }

    void Show() const
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data;
            if (current->next != nullptr)
                cout << " <-> ";
            current = current->next;
        }
        cout << endl;
    }

    // Завдання 2

    void InsertAt(int position, T value)
    {
        if (position <= 0)
        {
            AddToHead(value);
            return;
        }
        Node* current = head;
        int index = 0;
        while (current != nullptr && index < position)
        {
            current = current->next;
            index++;
        }
        if (current == nullptr)
        {
            AddToTail(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* prevNode = current->prev;
        newNode->next = current;
        newNode->prev = prevNode;
        if (prevNode != nullptr)
            prevNode->next = newNode;
        current->prev = newNode;
    }

    void DeleteAt(int position)
    {
        if (head == nullptr)
            return;
        if (position <= 0)
        {
            DeleteFromHead();
            return;
        }
        Node* current = head;
        int index = 0;
        while (current != nullptr && index < position)
        {
            current = current->next;
            index++;
        }
        if (current == nullptr)
            return;
        if (current == tail)
        {
            DeleteFromTail();
            return;
        }
        Node* prevNode = current->prev;
        Node* nextNode = current->next;
        if (prevNode != nullptr)
            prevNode->next = nextNode;
        if (nextNode != nullptr)
            nextNode->prev = prevNode;
        delete current;
    }

    Node* Find(T value) const
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == value)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    int FindAndReplace(T oldValue, T newValue)
    {
        if (Find(oldValue) == nullptr)
            return -1;
        int count = 0;
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == oldValue)
            {
                current->data = newValue;
                count++;
            }
            current = current->next;
        }
        return count;
    }

    void Reverse()
    {
        if (head == nullptr)
            return;
        Node* current = head;
        while (current != nullptr)
        {
            Node* temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }
        Node* temp = head;
        head = tail;
        tail = temp;
    }
};