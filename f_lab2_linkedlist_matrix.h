#ifndef F_LAB2_LINKEDLIST_MATRIX
#define F_LAB2_LINKEDLIST_MATRIX

#include <cmath>

#include "f_lab2_matrix.h"
#include "f_lab2_linkedlistsequance.h"

template <typename T>
class LinkedListMatrix : public Matrix<T> {
    public:
        LinkedListMatrix(T *array, int count);
        LinkedListMatrix(Sequance<T> *sequance);

        Matrix<T> *Sum(Matrix<T> *m2) override;
        Matrix<T> *Mult(Matrix<T> *m2) override;

        ~LinkedListMatrix() {
            delete this->value;
        }
};

template <typename T>
LinkedListMatrix<T>::LinkedListMatrix(T *array, int count) {
    LinkedListSequance<T> *sequance = new LinkedListSequance<T>(array, count);
    this->value = sequance;
    this->size = sqrt(this->value->GetLength());
}

template <typename T>
Matrix<T> *LinkedListMatrix<T>::Sum(Matrix<T> *m2) {
    T *array = new T[this->value->GetLength()];
    if (m2->GetSize() * m2->GetSize()  == this->value->GetLength()) {
        for (int i = 0; i < this->value->GetLength(); i++) {
            array[i] = this->value->Get(i) + m2->Get(i);
        }
    }
    Matrix<T> *res = new LinkedListMatrix(array, this->value->GetLength());
    return res;
}

template <typename T>
Matrix<T> *LinkedListMatrix<T>::Mult(Matrix<T> *m2) {
    T *array = new T[this->value->GetLength()];
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
    Matrix<T> *res = new LinkedListMatrix(array, this->value->GetLength());
    return res;
}

#endif
