#include <iostream>
#include <time.h>

#include "f_lab2_linkedlist.h"
#include "f_lab2_dynamicarray.h"
#include "f_lab2_linkedlist_matrix.h"
#include "f_lab2_array_matrix.h"
#include "f_lab2_stack.h"
#include "f_lab2_dequeue.h"
#include "f_lab2_queue.h"

using namespace std;

int main() {

    int *ptr = new int[6];
    cout << "Enter matrix a" << endl;
    for (int i = 0; i < 6; i++) {
        cin >> ptr[i];
    }

    LinkedListMatrix<int> *a = new LinkedListMatrix(ptr, 6, 3, 2);
    LinkedListMatrix<int> *q = new LinkedListMatrix(ptr, 6, 2, 3);

    cout << "matrix 1 3*2: " << endl << '\t'; 
    for (int i = 0; i < a->GetSize(); i++) {
        cout << a->Get(i) << ' ';
        if ((i + 1) % a->GetWidth() == 0) {
            cout << endl << '\t';
        }
    }
    cout << endl;

    q->Mult_on_const(5);
    cout << "matrix 2 2*3 and mult on 5: " << endl << '\t';
    for (int i = 0; i < q->GetSize(); i++) {
        cout << q->Get(i) << ' ';
        if ((i + 1) % q->GetWidth() == 0) {
            cout << endl << '\t';
        }
    }
    cout << endl;

    LinkedListMatrix<int> *f = (LinkedListMatrix<int> *)a->Sum(a);
    cout << "sum matrix 1 and 1: " << endl << '\t';
    for (int i = 0; i < f->GetSize(); i++) {
        cout << f->Get(i) << ' ';
        if ((i + 1) % f->GetWidth() == 0) {
            cout << endl << '\t';
        }
    }
    cout << endl;


    LinkedListMatrix<int> *w = (LinkedListMatrix<int> *)a->Mult(q);

    cout << "mult matrix 1 and 2: " << endl << '\t';
    for (int i = 0; i < w->GetSize(); i++) {
        cout << w->Get(i) << ' ';
        if ((i + 1) % w->GetWidth() == 0) {
            cout << endl << '\t';
        }
    }
    cout << endl;

    int *ptr_1 = new int[9];
    cout << "Enter matrix: " << endl;
    for (int i = 0; i < 9; i++) {
        cin >> ptr_1[i];
    }
    LinkedListMatrix<int> *z = new LinkedListMatrix(ptr_1, 9, 3, 3);
    cout << "matrix1: " << endl << '\t';

    for (int i = 0; i < z->GetSize(); i++) {
        cout << z->Get(i) << ' ';
        if ((i + 1) % z->GetWidth() == 0) {
            cout << endl << '\t';
        }
    }
    cout << endl << "matrix2 from matrix1 * 5: " << endl << '\t';

    LinkedListMatrix<int> *x = new LinkedListMatrix(ptr_1, 9, 3, 3);
    x->Mult_on_const(5);
    for (int i = 0; i < x->GetSize(); i++) {
        cout << x->Get(i) << ' ';
        if ((i + 1) % x->GetWidth() == 0) {
            cout << endl << '\t';
        }
    }
    cout << endl << "mult matrix1 on matrix2: " << endl << '\t';
    LinkedListMatrix<int> *c = (LinkedListMatrix<int> *) z->Mult(x);
    for (int i = 0; i < c->GetSize(); i++) {
        cout << c->Get(i) << ' ';
        if ((i + 1) % c->GetWidth() == 0) {
            cout << endl << '\t';
        }
    }
    cout << endl;



    int *ptr_3 = new int[3];
    cout << "Enter matrix: " << endl;
    for (int i = 0; i < 3; i++) {
        cin >> ptr_3[i];
    }
    LinkedListMatrix<int> *z1 = new LinkedListMatrix(ptr_3, 3, 3, 3);
    cout << "matrix1: " << endl << '\t';

    for (int i = 0; i < z1->GetSize(); i++) {
        cout << z1->Get(i) << ' ';
        if ((i + 1) % z1->GetWidth() == 0) {
            cout << endl << '\t';
        }
    }
    cout << endl << "matrix2 from matrix1 * 5: " << endl << '\t';

    LinkedListMatrix<int> *x1 = new LinkedListMatrix(ptr_3, 3, 3, 3);
    x1->Mult_on_const(5);
    for (int i = 0; i < x1->GetSize(); i++) {
        cout << x1->Get(i) << ' ';
        if ((i + 1) % x1->GetWidth() == 0) {
            cout << endl << '\t';
        }
    }
    cout << endl << "mult matrix1 on matrix2: " << endl << '\t';
    LinkedListMatrix<int> *c1 = (LinkedListMatrix<int> *) z1->Mult(x1);
    for (int i = 0; i < c1->GetSize(); i++) {
        cout << c1->Get(i) << ' ';
        if ((i + 1) % c1->GetWidth() == 0) {
            cout << endl << '\t';
        }
    }
    cout << endl;

    //delete[] ptr;
    //delete[] ptr_1;
}

