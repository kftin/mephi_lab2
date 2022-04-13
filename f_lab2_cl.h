#ifndef F_LAB2_CL
#define F_LAB2_CL

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

#endif
