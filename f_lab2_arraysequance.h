#ifndef F_LAB2_SEQ
#define F_LAB2_SEQ

class ArraySequance: public Sequance {
    private:
        DynamicArray *items;

    public:

        ArraySequance() { this->items = new DynamicArray<T>; }
        ArraySequance(T *items, int count);
        ArraySequance(const DynamicArray<T> *dynamicArray);


        T Get(int index) const override {
            return this->items->Get(index);
        }
        void Set(int index, T value) override {
            this->items->Set(index, value);
        }
        void Resize(int newSize) override {
            this->items->Resize(newSize);
        }
        T GetFirst() const override {
            return this->items->Get(0);
        }
        T GetLast() const override {
            return this->items->Get(this->items->GetLength() - 1);
        }
        int GetLength() const override {
            return this->items->GetLength();
        }


        void Append(T item) override {
            this->items->Resize(this->items->GetLength() + 1);
            this->items->Set(this->items->GetLength - 1, item);
        }
        void Prepend(T item) override {
            int size = this->items->GetLength();
            this->items->Resize(this->items->GetLength + 1);
            for (int i = size - 1; i >= 0; i--) {
                this->items->Set(i + 1, this->items->Get(i));
            }
            this->items->Set(0, item);
        }
        void InsertAt(T item, int index) override;
        Sequance<T> *Concat(Sequance<T> *list) override;
        Sequance<T> *GetSubsequance(int startIndex, int endIndex) const override;


        ~ArraySequance() { delete items; }
};

template <typename T>
ArraySequance<T>::ArraySequance(T *items, int count) {
    this->items = new DynamicArray<T>(items, count);
}

template <typename T>
ArraySequance<T>::ArraySequance(const DynamicArray<T> *dynamicArray) {
    this->items = new DynamicArray<T>(dynamicArray);
}

template <typename T>
Sequance<T> *ArraySequance<T>::Concat(Sequance<T> *list) {
    int oldsize = this->items->GetSize();
    this->items->Resize(oldSize + list->GetLength());
    for (int i = 0; i < list->GetLength(); i++) {
        this->items->Set(oldSize + i, list->Get(i));
    }
    return this;
}

template <typename T>
Sequance<T> *ArraySequance<T>::GetSubsequance(int startIndex, int endIndex) const {
    T *array = new T[endIndex - startIndex + 1];
    for (int i = 0; i < endIndex - startIndex + 1; i++) {
        array[i] = items->Get(startIndex + i);
    }
    ArraySequance<T> *newArraySequance = new ArraySequance(array, endIndex - startIndex + 1);
    //return static_pointer_cast<Sequance<T>>(newArraySequance);
}


#endif
