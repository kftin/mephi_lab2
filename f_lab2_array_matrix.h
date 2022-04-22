#ifndef F_LAB2_ARRAY_MATRIX
#define F_LAB2_ARRAY_MATRIX

#include <cmath>

#include "f_lab2_matrix.h"
#include "f_lab2_arraysequance.h"

template <typename T>
class ArrayMatrix : public Matrix<T> {
    public:
        ArrayMatrix(T *array, int count);
        //ArrayMatrix(Sequance<T> *sequance);

        Matrix<T> *Sum(Matrix<T> *m2) override;
        Matrix<T> *Mult(Matrix<T> *m2) override;

        ~ArrayMatrix() {
            delete this->value;
        }
};

template <typename T>
ArrayMatrix<T>::ArrayMatrix(T *array, int count) {
    ArraySequance<T> *sequance = new ArraySequance<T>(array, count);
    this->value = sequance;
    this->size = sqrt(this->value->GetLength());
}


/*template <typename T>
ArrayMatrix<T>::ArrayMatrix(Sequance<T> *sequance) {
    ArrayMatrix<T> *tmp = new ArraySequance<T>(sequance);
    this->value = tmp;
    this->size = sqrt(this->value->GetLength());
}*/

template <typename T>
Matrix<T> *ArrayMatrix<T>::Sum(Matrix<T> *m2) {
    T *array = new T[this->value->GetLength()];
    if (m2->GetSize() * m2->GetSize() == this->value->GetLength()) {
        for (int i = 0; i < this->value->GetLength(); i++) {
            array[i] = this->value->Get(i) + m2->Get(i);
        }
    } else {
        cout << "FUXK\n";
    }
    Matrix<T> *res = new ArrayMatrix(array, this->value->GetLength());
    return res;
}

template <typename T>
Matrix<T> *ArrayMatrix<T>::Mult(Matrix<T> *m2) {
    T *array = new T[this->value->GetLength()];
    for (int i = 0; i < this->value->GetLength(); i++) {
        array[i] = T(0);
    }
    int n = m2->GetSize();
    if (n * n == this->value->GetLength()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    array[i * n + j] += this->Get(i * n + k) * m2->Get(k * n + j);
                }
            }
        }
    }
    else {
        cout << "FUXK\n";
    }
    Matrix<T> *res = new ArrayMatrix(array, this->value->GetLength());
    return res;
}


#endif
