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
        void SetFirst(T item) { 
            value->Prepend(item);
            size++;
        }
        T GetLast() const { return value->GetLast(); }
        void RemoveLast() {
            Sequance<T> *tmp = value->GetSubSequance(0, size - 2);
            //cout << "удаляем то, что было" << endl;
            delete this->value;
            this->value = tmp;
            size--;
            //cout << "size--  "  << size << endl;
        }

        virtual ~Queue() {}
};

template <typename T>
class ArrayQueue: public Queue<T> {
    public:
        ArrayQueue(T *array, int count) {
            ArraySequance<T> *sequance = new ArraySequance<T>(array, count);
            this->value = sequance;
            //this->size = this->value->GetLength();
            this->size = count;
        }
        ~ArrayQueue() { delete this->value; }
};

template <typename T>
class LinkedListQueue: public Queue<T> {
    public:
        LinkedListQueue(T *array, int count) {
            LinkedListSequance<T> *sequance = new LinkedListSequance<T>(array, count);
            this->value = sequance;
            //this->size = this->value->GetLength();
            this->size = count;
    }
    ~LinkedListQueue() { delete this->value; }
};

#endif
