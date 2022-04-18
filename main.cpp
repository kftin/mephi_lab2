#include <iostream>

#include "f_lab2_linkedlist.h"
#include "f_lab2_dynamicarray.h"
#include "f_lab2_linkedlist_matrix.h"

using namespace std;

int main() {
    int *ptr = new int[4];
    for (int i = 0; i < 4; i++) {
        cin >> ptr[i];
    }
    LinkedListMatrix<int> *a = new LinkedListMatrix<int>(ptr, 4);

    a->Mult_on_const(5);
    LinkedListMatrix<int> *b = new LinkedListMatrix<int>(ptr, 4);

    LinkedListMatrix<int> *res = (LinkedListMatrix<int> *) a->Mult(b);
    cout << res->GetSize() <<"\n";
    for (int i = 0; i < 4; i++) {
        cout << res << " ";
    }
    //LinkedList<int> b;
    //LinkedList<int> a(ptr, 6);
    //LinkedList<int> b(ptr_1, 2);

    //LinkedList<int> *tmp = a.GetSubList(1, 5);
    //LinkedList<int> b(&a);
    /*b.Append(0);
    b.Append(1);
    b.Append(2);
    b.Append(3);
    LinkedList<int> *tmp = b.GetSubList(1, 2);
    cout << "0 index b " << b.GetFirst() << endl;
    cout << "length b " << b.GetLength() << endl;

    cout << "last index tmp " << tmp->GetLast() << endl;
    cout << "0 index tmp " << tmp->GetFirst() << endl;
    cout << "length tmp" << tmp->GetLength() << endl;*/
    delete[] ptr;
    delete a;
    delete b;
    delete res;
}
