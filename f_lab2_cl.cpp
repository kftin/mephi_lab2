#include <iostream>

#include "f_lab2_cl.h"

using namespace std;

template <typename T>
DynamicArray<T>::DynamicArray(T *items, int count) {
    pointer = new T[count];
    for (int i = 0; i < count; i++) {
        pointer[i] = items[i];
    }
    length = count;
}

template <typename T>
DynamicArray<T>::DynamicArray(int size) {
    pointer = new T[size];
    length = size;
}

template <typename T>
T DynamicArray<T>::Get(int index) {
    if (index > length || index < 0) {
        throw out_of_range("index out of range");
    }
    return pointer[index];
}

template <typename T>
int DynamicArray<T>::GetSize() {
    return length;
}

template <typename T>
void DynamicArray<T>::Set(int index, T value) {
    if (index < 0 || index > length) {
        throw out_of_range("index out of range");
    }
    pointer[index] = value;
}

template <typename T>
void DynamicArray<T>::Resize(int newSize) {
    T *ptr = new T[newSize];
    int copySize = min(newSize, length);
    for (int i = 0; i < copySize; i++) {
        ptr[i] = pointer[i];
    }
    delete[] pointer;
    pointer = ptr;
    length = newSize;
}

template <typename T>
LinkedList<T>::LinkedList(T *items, int count) {
    head = NULL;
    tail = NULL;
    for (int i = 0; i < count; i++) {
        this->Append(items[i]);
    }
}

template <typename T>
LinkedList<T>::LinkedList() {
    length = 0;
    head = NULL;
    tail = NULL;
}

template <typename T>
T LinkedList<T>::GetFirst() {
    return head->data;
}

template <typename T>
T LinkedList<T>::GetLast() {
    return tail->data;
}

template <typename T>
int LinkedList<T>::GetLength() {
    return length;
}

template <typename T>
T LinkedList<T>::Get(int index) {
    Element *ptr = head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    return ptr->data;
}

template <typename T>
void LinkedList<T>::Append(T item) {
    if (!head) {
        Element *ptr = new Element;
        ptr->data = item;
        ptr->next = NULL;
        head = ptr;
        tail = ptr;
        length = 1;
    } else {
        Element *ptr = new Element;
        ptr->data = item;
        ptr->next = NULL;
        tail->next = ptr;
        tail = ptr;
        length++;
    }
}

template <typename T>
void LinkedList<T>::Prepend(T item) {
    if (!head) {
        Element *ptr = new Element;
        ptr->data = item;
        ptr->next = NULL;
        head = NULL;
        tail = NULL;
        length = 1;
    } else {
        Element *ptr = new Element;
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        length++;
    }
}

template <typename T>
void LinkedList<T>::InsertAt(T item, int index) {
    if (index < 0 || index > length) {
        throw out_of_range("index out of range");
    }
    if (index == 0) {
        this->Prepend(item);
    } else if (index == length) {
        this->Append(item);
    } else {
        Element *ptr = head;
        Element *ptr_prev = ptr->next;
        Element *tmp = new Element;
        tmp->data = item;
        for (int i = 0; i < index - 1; i++) {
            ptr = ptr_prev;
            ptr_prev = ptr_prev->next;
        }
        ptr->next = tmp;
        tmp->next = ptr_prev;
        length++;
    }

}

template <typename T>
void LinkedList<T>::ClearList() {
    Element *ptr = head;
    Element *ptr_prev = head->next;
    for (int i = 0; i < length; i++) {
        cout << ptr->data << endl;
        delete ptr;
        ptr = ptr_prev;
        if (ptr_prev) {
            ptr_prev = ptr_prev->next;
        }
    }
}
