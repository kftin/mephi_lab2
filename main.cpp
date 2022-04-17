#include <iostream>

#include "f_lab2_linkedlist.h"
#include "f_lab2_dynamicarray.h"

using namespace std;

int main() {
    int *ptr = new int[6];
    for (int i = 0; i < 6; i++) {
        cin >> ptr[i];
    }
    LinkedList<int> b;
    //LinkedList<int> a(ptr, 6);
    //LinkedList<int> b(ptr_1, 2);

    //LinkedList<int> *tmp = a.GetSubList(1, 5);
    //LinkedList<int> b(&a);
    b.Append(0);
    b.Append(1);
    b.Append(2);
    b.Append(3);
    LinkedList<int> *tmp = b.GetSubList(1, 2);
    cout << "0 index b " << b.GetFirst() << endl;
    cout << "length b " << b.GetLength() << endl;

    cout << "last index tmp " << tmp->GetLast() << endl;
    cout << "0 index tmp " << tmp->GetFirst() << endl;
    cout << "length tmp" << tmp->GetLength() << endl;
    delete[] ptr;
    
}
