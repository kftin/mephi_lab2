#include <iostream>

using namespace std;

template <typename T>
class DynamicArray {
    private:
        int length;
        //T *pointer;
    public:
        T *pointer;
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

int main() {
    int *ptr = new int[5];
    for (int i = 0; i < 5; i++) {
        cin >> ptr[i];
    }
    DynamicArray a(ptr, 5);
    for (int i = 0; i < 5; i++) {
        cout << a.pointer[i] << endl;;
    }
    cout << "the second element: " << a.Get(2) << endl;
    cout << "size of array: " << a.GetSize() << endl;
    delete[] ptr;
    a.Resize(0);
}
