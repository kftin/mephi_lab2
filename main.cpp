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
    //cout << a->GetHeigth() << endl;
    //cout << a->GetWidth() << endl;
    LinkedListMatrix<int> *c = new LinkedListMatrix(ptr, 6, 3, 2);
    c->Mult_on_const(5);
    LinkedListMatrix<int> *b = (LinkedListMatrix<int> *)a->Sum(c);

    cout << "Sum matrix a and a*5: " << endl;
    for (int i = 0; i < b->GetSize(); i++) {
        cout << b->Get(i) << ' ';
        if ((i + 1) % b->GetWidth() == 0) {
            cout << endl;
        }
    }
    cout << endl;

    LinkedListMatrix<int> *q = new LinkedListMatrix(ptr, 6, 2, 3);

    for (int i = 0; i < q->GetSize(); i++) {
        cout << q->Get(i) << ' ';
        if ((i + 1) % q->GetWidth() == 0) {
            cout << endl;
        }
    }
    cout << endl;

    //cout << q->GetHeigth() << ' ' << q->GetWidth() << endl;
    LinkedListMatrix<int> *w = (LinkedListMatrix<int> *)a->Mult(q);

    for (int i = 0; i < w->GetSize(); i++) {
        cout << w->Get(i) << ' ';
        if ((i + 1) % w->GetWidth() == 0) {
            cout << endl;
        }
    }
    cout << endl;

    delete[] ptr;
}

