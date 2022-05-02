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
    int *ptr = new int[4];
    cout << "Enter values" << endl;
    for (int i = 0; i < 4; i++) {
        cin >> ptr[i];
    }

    cout << "ArrayDequeue: " << endl;
    ArrayDequeue<int> a(ptr, 4);
    cout << "Get first: " << a.GetFirst() << endl;
    cout << "Get last: " << a.GetLast() << endl;
    a.SetLast(1111);
    cout <<  "Get last after set last 11111 : " << a.GetLast() << endl;
    a.RemoveFirst();
    a.RemoveLast();
    cout << "remove first and last, value: " << endl;
    cout << a.GetFirst() << endl;
    cout << a.GetLast() << endl << endl;;

    cout << "ArrayStack: " << endl;
    ArrayStack<int>  b(ptr, 4);
    cout << "Get first: " << b.GetFirst() << endl;
    b.SetFirst(666);
    cout << "Get first after set first 666 : " << b.GetFirst() << endl;
    b.RemoveFirst();
    cout << "GetFirst after remove first: " << b.GetFirst()<< endl << endl;

    cout << "LinkedListQueue: " << endl;
    LinkedListQueue<int> c(ptr, 4);
    c.SetFirst(777);
    cout << "Get last: " << c.GetLast() << endl;
    c.RemoveLast();
    cout << "Get last after remove last: " << c.GetLast() << endl << endl; 

    LinkedList<int> *c1 = new LinkedList<int>(ptr, 4);
    LinkedList<int> *a1 = new LinkedList<int>(ptr, 4);
    LinkedList<int> *b1 = a1->Concat(c1);
    cout << "concat two lists " << endl;
    for (int i = 0; i < 8; i++) {
        cout << b1->Get(i) << endl; 
    }

    //delete a1;
    //delete c1;
    delete b1;
    
    delete[] ptr;
}

