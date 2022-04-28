#ifndef F_LAB2_MATRIX
#define F_LAB2_MATRIX

//using namespace std;

//#include "f_lab2_arraysequance.h"
#include "f_lab2_sequance.h"

template <typename T>
class Matrix {
    protected:
        Sequance<T> *value;
        int size;

    public:
        int GetSize() const { return this->size; }
        T Get(int index) const { return value->Get(index); }

        virtual Matrix<T> *Sum(Matrix<T> *m2) = 0;
        virtual Matrix<T> *Mult(Matrix<T> *m2) = 0;
        void Mult_on_const(int cnst) {
            for (int i = 0; i < value->GetLength(); i++) {
                value->Set(i, value->Get(i) * cnst);
            }
        }
        /*
        Matrix<T> *operator + (Matrix<T> *m2) {
            return this->Sum(m2);
        }*/

        virtual ~Matrix() {}
};

#endif
