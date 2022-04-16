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
int DynamicArray<T>::GetLength() {
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

///////////////////////////////////////////////////////////////////////

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
LinkedList<T>::LinkedList(LinkedList<T> *list) {
   int size = list->length;
   head = NULL;
   tail = NULL;
   Element *ptr = list->head;
   for (int i = 0; i < list->length; i++) {
       if (i == list->length - 1) {
            tail = ptr;
       }
        this->Append(ptr->data);
        ptr = ptr->next;
   }
   length = list->length;
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
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex) {
    if (startIndex > endIndex) {
        throw invalid_argument("startIndex should be not bigger than endIndex");
    }
    if (startIndex < 0 || endIndex >= length) {
        throw out_of_range("Indexes out of range");
    }
    LinkedList<T> *subList  = new LinkedList<T>();
    int curIndex = 0;
    Element *ptr  = head->next;
    while (curIndex <= endIndex) {
        if (curIndex >= startIndex) {
            subList->Append(ptr->data);
        }
        ptr = ptr->next;
        curIndex++;
    }
    return subList;
}

template <typename T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T> *list) {
    Element *cur = head;
    while (cur->next != end) {
        cur = cur->next;
    }
    cur->next = list->head->next;
    length += list->length;
    end = list->end;
    return this;

}
