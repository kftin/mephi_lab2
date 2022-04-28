#ifndef F_LAB2_QUEUE
#define F_LAB2_QUEUE

//using namespace std;

//#include "f_lab2_arraysequance.h"
#include "f_lab2_sequance.h"

template <typename T>
class Queue {
    protected:
        Sequance<T> *value;
        int size;

    public:
        void SetFirst(T item) { value->Prepend(item); }
        T GetLast() const { return value->GetLast(); }
        void RemoveLast() {
            Sequance<T> *tmp = value->GetSubSequance(0, size - 1);
            delete value;
            value = tmp;
            size--;
        }

        virtual ~Queue() {}
};

template <typename T>
class ArrayQueue: public Queue<T> {
    public:
        ArrayQueue(T *array, int count) {
            ArraySequance<T> *sequance = new ArraySequance<T>(array, count);
            this->value = sequance;
            this->size = this->value->GetLength();
        }
        ~ArrayQueue() { delete this->value; }
};

template <typename T>
class LinkedListQueue: public Queue<T> {
    public:
        LinkedListQueue(T *array, int count) {
            LinkedListSequance<T> *sequance = new LinkedListSequance<T>(array, count);
            this->value = sequance;
            this->size = this->value->GetLength();
    }
    ~LinkedListQueue() { delete this->value; }
};

#endif
