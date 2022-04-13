#include <iostream>

using namespace std;

template <typename T>
class DynamicArray {
    private:
        int length;
        T *pointer;
    public:
        //T *pointer;
        DynamicArray(T *items, int count);
        DynamicArray(int size);
        //DynamicArray(DynamicArray<T> & dynamicArray const);

        T Get(int index);
        int GetSize();

        void Set(int index, T value);
        void Resize(int newSize);
};

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

////////////////////////////////////////////////////////////////////////

template <typename T>
class LinkedList {
    private:        
        class Element {
            public:
                T data;
                Element *next;
        };

        int length;
        Element *head;
        Element *tail;
    public:
        LinkedList(T *items, int count);
        LinkedList();
        //LinkedList(LinkedList <T> & list const);

        T GetFirst();
        T GetLast();
        T Get(int index);
        //LinkedList<T> *GetSubList(int startindex, int endindex);
        int GetLength();

        void Append(T item);
        void Prepend(T item);
        void InsertAt(T item, int index);
        //LinkedList<T> *Concat(LinkedList<T> *list);
        
        void ClearList();
};

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

int main() {
    int *ptr = new int[6];
    for (int i = 0; i < 6; i++) {
        cin >> ptr[i];
    }
    LinkedList a(ptr, 6);
    delete[] ptr;
    cout << "first " << a.GetFirst() << endl;
    //cout << "last" << a.GetLast() << endl;
    //cout << "length" << a.GetLength() << endl;
    a.InsertAt(111111, 0);
    cout << "first " << a.Get(0) << endl;
    //a.Prepend(111);
    //cout << "first " << a.GetFirst() << endl;
    cout << "length " << a.GetLength() << endl;
    a.ClearList();
}
