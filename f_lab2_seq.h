#ifndef F_LAB2_SEQ
#define F_LAB2_SEQ

template <typename T>
class Sequance {
    public:
        virtual T Get(int index);
        virtual int GetSize();
        virtual void Set(int index, T value);
}

#endif
