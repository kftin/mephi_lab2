#ifndef F_LAB2_STACK
#define F_LAB2_STACK

//using namespace std;

//#include "f_lab2_arraysequance.h"
#include "f_lab2_sequance.h"

template <typename T>
class Stack {
    protected:
        Sequance<T> *value;
        int size;

    public:
        T GetFirst() const { return value->Get(0); }
        void SetFirst(T item) { value->Prepend(item); }
        void RemoveFirst() {
            Sequance<T> *tmp = value->GetSubSequance(1, size - 1);
            delete value;
            value = tmp;
            size--;
        }

};

template <typename T>
class ArrayStack: public Stack<T> {
    public:
        ArrayStack(T *array, int count) {
            ArraySequance<T> *sequance = new ArraySequance<T>(array, count);
            this->value = sequance;
            this->size = this->value->GetLength();
        }
        ~ArrayStack() { delete this->value; }
};

template <typename T>
class LinkedListStack: public Stack<T> {
    public:
        LinkedListStack(T *array, int count) {
            LinkedListSequance<T> *sequance = new LinkedListSequance<T>(array, count);
            this->value = sequance;
            this->size = this->value->GetLength();
    }
    ~LinkedListStack() { delete this->value; }
};

#endif
