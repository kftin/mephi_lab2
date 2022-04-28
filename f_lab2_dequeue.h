#ifndef F_LAB2_DEQUEUE
#define F_LAB2_DEQUEUE

//using namespace std;

//#include "f_lab2_arraysequance.h"
#include "f_lab2_sequance.h"

template <typename T>
class Dequeue {
    protected:
        Sequance<T> *value;
        int size;

    public:
        T GetFirst() const { return value->Get(0); }
        void SetFirst(T item) { value->Prepend(item); }
        T GetLast() const { return value->GetLast(); }
        void SetLast(T item) { value->Append(item); }
        void RemoveFirst() {
            Sequance<T> *tmp = value->GetSubSequance(1, size - 1);
            delete value;
            value = tmp;
            size--;
        }

        void RemoveLast() {
            Sequance<T> *tmp = value->GetSubSequance(0, size - 1);
            delete value;
            value = tmp;
            size--;
        }

        virtual ~Dequeue() {}
};

template <typename T>
class ArrayDequeue: public Dequeue<T> {
    public:
        ArrayDequeue(T *array, int count) {
            ArraySequance<T> *sequance = new ArraySequance<T>(array, count);
            this->value = sequance;
            this->size = this->value->GetLength();
        }
        ~ArrayDequeue() { delete this->value; }
};

template <typename T>
class LinkedListDequeue: public Dequeue<T> {
    public:
        LinkedListDequeue(T *array, int count) {
            LinkedListSequance<T> *sequance = new LinkedListSequance<T>(array, count);
            this->value = sequance;
            this->size = this->value->GetLength();
    }
    ~LinkedListDequeue() { delete this->value; }
};

#endif
