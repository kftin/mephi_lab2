#ifndef F_LAB2_LINKEDLIST_MATRIX
#define F_LAB2_LINKEDLIST_MATRIX

#include <cmath>

#include "f_lab2_matrix.h"
#include "f_lab2_linkedlistsequance.h"

template <typename T>
class LinkedListMatrix : public Matrix<T> {
    public:
        LinkedListMatrix(T *array, int count, int h, int w);
        //LinkedListMatrix(Sequance<T> *sequance);

        Matrix<T> *Sum(Matrix<T> *m2) override;
        Matrix<T> *Mult(Matrix<T> *m2) override;                    

        //friend LinkedListMatrix<T> &operator +(LinkedListMatrix<T> &m1, LinkedListMatrix<T> &m2);

        ~LinkedListMatrix() {
            delete this->value;
        }
};
/*
template <typename T>
LinkedListMatrix<T> & LinkedListMatrix<T>::operator + (LinkedListMatrix<T> &m1, LinkedListMatrix<T> &m2) {
return *(m1.Sum(&m2));
}
*/
template <typename T>
LinkedListMatrix<T>::LinkedListMatrix(T *array, int count, int h, int w) {
    LinkedListSequance<T> *sequance = new LinkedListSequance<T>(array, count, h, w);
    this->value = sequance;
    this->size = this->value->GetLength();
    this->width = w;
    this->heigth = h;
}

template <typename T>
Matrix<T> *LinkedListMatrix<T>::Sum(Matrix<T> *m2) {
    T *array = new T[this->value->GetLength()];
    if (m2->GetSize()  == this->value->GetLength()) {
        for (int i = 0; i < this->value->GetLength(); i++) {
            array[i] = this->value->Get(i) + m2->Get(i);
        }
    } else {
        cout << "FUXK\n";
    }
    Matrix<T> *res = new LinkedListMatrix(array, this->value->GetLength(), this->value->GetHeigth(), this->value->GetWidth());
    delete[] array;
    return res;
}

template <typename T>
Matrix<T> *LinkedListMatrix<T>::Mult(Matrix<T> *m2) {
    //int n_2 = m2->GetHeigth();
    int m_2 = m2->GetWidth();
    int n1 = this->GetHeigth();
    int m1 = this->GetWidth();
    //cout << n1 << m1 << n_2 << m_2 << endl;
    T *array = new T[n1 * m_2];
    for (int i = 0; i < n1 * m_2; i++) {
        array[i] = T(0);
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m_2; j++) {
            for (int k = 0; k < m1; k++) {
                array[i * m_2 + j] += this->Get(i * m1 + k) * m2->Get(k * m_2 + j);
                //cout << i * m1 + k << " * " << k * m_2 + j << '=' << i * m_2 + j  << endl;
            }
        }
    }

    Matrix<T> *res = new LinkedListMatrix(array, this->value->GetHeigth() * m2->value->GetWidth(), n1, m_2);
    delete[] array;
    return res;
}

#endif
