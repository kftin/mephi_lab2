#ifndef F_LAB2_LINKEDLISTSEQUANCE
#define F_LAB2_LINKEDLISTSEQUANCE

#include <f_lab2_linkedlist.h>
#include <f_lab2_sequance.h>

template <tyoename T>
class LinkedListSequance : public Sequance<T> {
    private:
        LinkedList<T> *items;

    public:
        LinkedListSequance() {
            this->items = new LinkedList<T>; 
        }
        LinkedListSequance(T *items, int count) {
            this->items = new LinkedList<T>(items, count);
        }
        LinkedListSequance(const LinkedList<T> *list) {
            this->items = new LinkedList<T>(list);
        }

        int GetLength() const override {
            return this->items->GetLength();
        }
        T GetFirst() const override {
            return this->items->GetFirst();
        }
        T GetLast() const override {
            return this->items->GetLast();
        }
        T Get(int index) const override {
            return this->items->Get(index);
        }

        Sequance<T> *GetSubSequance(int startIndex, int endIndex) const override {
            LinkedList<T> *list = this->items->GetSubList(startIndex, endIndex);
            LinkedListSequance<T> *listsequance = new LinkedListSequane<T>(list);
            delete list;
            return listsequance;
        }
        void Append(T item) override {
            this->items->Append(item);
        }
        void Prepend(T item) override {
            this->items->Prepend(item);
        }
        void InsertAt(T item, int index) override {
            this->items->InsertAt(item, index);
        }
        Sequance<T> *Concat(Sequance<T> *list) override {
            for (int i = 0; i < list->GetLength(); i++) {
                this->items->Append(list->Get(i));
            }
            return this;
        }

        ~LinkedListSequance() {
            delete items;
        }
};



#endif
