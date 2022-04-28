#include <iostream>
#include <time.h>

#include "f_lab2_linkedlist.h"
#include "f_lab2_dynamicarray.h"
#include "f_lab2_linkedlist_matrix.h"
#include "f_lab2_array_matrix.h"
#include "f_lab2_stack.h"
#include "f_lab2_dequeue.h"

using namespace std;

int main() {
    int *ptr = new int[9];
    for (int i = 0; i < 9; i++) {
        cin >> ptr[i];
    }
    
    /*LinkedList<int> *n = new LinkedList<int>(ptr, 9);
    LinkedList<int> *s = n->Concat(n);
    for (int i = 0; i < 18; i++) {
        cout << s->Get(i) << endl;
    }*/
    
    LinkedListMatrix<int> a(ptr, 9);
    LinkedListMatrix<int> b(ptr, 9);
    cout << "matrix a: " << endl;
    for (int i = 0; i < a.GetSize() * a.GetSize(); i++) {
        cout << a.Get(i) << ' ';
        if ((i + 1) % a.GetSize() == 0) {
            cout << '\n';
        }
    }

    clock_t start = clock();
    b.Mult_on_const(5);
    cout << "matrix b (matrix a mult on const 5): " << endl;
    for (int i = 0; i < b.GetSize() * b.GetSize(); i++) {
        cout << b.Get(i) << ' ';
        if ((i + 1) % b.GetSize() == 0) {
            cout << '\n';
        }
    }
    cout << "mult matrix a and b (list, int):" << endl;
    LinkedListMatrix<int> res =*((LinkedListMatrix<int> *)a.Sum(&b));
    clock_t end = clock();
    float time = (float)(end - start) / CLOCKS_PER_SEC;
    for (int i = 0; i < res.GetSize() * res.GetSize(); i++) {
        cout << res.Get(i) << ' ';
        if ((i + 1) % res.GetSize() == 0) {
            cout << '\n';
        }
    }
    cout << "linkedlist int:   " << time << endl;
    delete[] ptr;
    //delete a;
    //delete b;
    //delete res;
///////////////////////////////////////////////////////////////////////////////////////////////
    int *tmp = new int[9];
    for (int i = 0; i < 9; i++) {
        cin >> tmp[i];
    }
    cout << "matrix a:" << endl;
    ArrayMatrix<int> *a1 = new ArrayMatrix<int>(tmp, 9);
    for (int i = 0; i < 9; i++) {
        cout << a1->Get(i) << ' ';
        if ((i + 1) % a1->GetSize() == 0) {
            cout << '\n';
        }
    }
    ArrayMatrix<int> *b1 =  new ArrayMatrix<int>(tmp, 9);
    clock_t start1 = clock();
    b1->Mult_on_const(5);
    cout << "matrix b:" << endl;
    for (int i = 0; i < 9; i++) {
        cout << b1->Get(i) << ' ';
        if ((i + 1) % b1->GetSize() == 0) {
            cout << '\n';
        }
    }
    cout << "matrix mult a and b (array, int):" << endl;
    ArrayMatrix<int> *res1 = (ArrayMatrix<int> *) a1->Mult(b1);
    clock_t end1 = clock();
    float time1 = (float)(end1 - start1) / CLOCKS_PER_SEC;
    for (int i = 0; i < 9; i++) {
        cout << res1->Get(i) << ' ';
        if ((i + 1) % res1->GetSize() == 0) {
            cout << '\n';
        }
    }
    cout << "array int:   " << time1 << endl; 
    delete[] tmp;
    delete a1;
    delete b1;
    delete res1;

///////////////////////////////////////////////////////////////////////////////////////////////
    float *ptr_1 = new float[9];
    for (int i = 0; i < 9; i++) {
        cin >> ptr_1[i];
    }
    LinkedListMatrix<float> *a3 = new LinkedListMatrix<float>(ptr_1, 9);
    LinkedListMatrix<float> *b3 = new LinkedListMatrix<float>(ptr_1, 9);
    cout << "matrix a: " << endl;
    for (int i = 0; i < a3->GetSize() * a3->GetSize(); i++) {
        cout << a3->Get(i) << ' ';
        if ((i + 1) % a3->GetSize() == 0) {
            cout << '\n';
        }
    }
    clock_t start2 = clock();
    b3->Mult_on_const(5);
    cout << "matrix b (matrix a mult on const 5): " << endl;
    for (int i = 0; i < b3->GetSize() * b3->GetSize(); i++) {
        cout << b3->Get(i) << ' ';
        if ((i + 1) % b3->GetSize() == 0) {
            cout << '\n';
        }
    }
    cout << "sum matrix a and b (list, float):" << endl;
    LinkedListMatrix<float> *res3 = (LinkedListMatrix<float> *) a3->Sum(b3);
    clock_t end2 = clock();
    float time2 = (float)(end2 - start2) / CLOCKS_PER_SEC;
    for (int i = 0; i < res3->GetSize() * res3->GetSize(); i++) {
        cout << res3->Get(i) << ' ';
        if ((i + 1) % res3->GetSize() == 0) {
            cout << '\n';
        }
    }
    cout << "linkedlist float:   " << time2 << endl;
    delete[] ptr_1;
    delete a3;
    delete b3;
    delete res3;

///////////////////////////////////////////////////////////////////////////////////////////////
    float *tmp_1 = new float[9];
    for (int i = 0; i < 9; i++) {
        cin >> tmp_1[i];
    }
    cout << "matrix a:" << endl;
    ArrayMatrix<float> *a2 = new ArrayMatrix<float>(tmp_1, 9);
    for (int i = 0; i < 9; i++) {
        cout << a2->Get(i) << ' ';
        if ((i + 1) % a2->GetSize() == 0) {
            cout << '\n';
        }
    }
    ArrayMatrix<float> *b2 =  new ArrayMatrix<float>(tmp_1, 9);
    clock_t start3 = clock();
    b2->Mult_on_const(5);
    cout << "matrix b:" << endl;
    for (int i = 0; i < 9; i++) {
        cout << b2->Get(i) << ' ';
        if ((i + 1) % b2->GetSize() == 0) {
            cout << '\n';
        }
    }
    cout << "matrix sum a and b (array, float)" << endl;
    ArrayMatrix<float> *res2 = (ArrayMatrix<float> *) a2->Sum(b2);
    clock_t end3 = clock();
    float time3 = (float)(end3 - start3) / CLOCKS_PER_SEC;
    for (int i = 0; i < 9; i++) {
        cout << res2->Get(i) << ' ';
        if ((i + 1) % res2->GetSize() == 0) {
            cout << '\n';
        }
    }
    cout << "array float:   " << time3 << endl;;
    delete[] tmp_1;
    delete a2;
    delete b2;
    delete res2;

/////////////////////////////////////////////////////////////////////////

    

}


