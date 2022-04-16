#include <iostream>

#include "f_lab2_cl.h"

using namespace std;

int main() {
    int *ptr = new int[6];
    for (int i = 0; i < 6; i++) {
        cin >> ptr[i];
    }
    LinkedList<int> a(ptr, 6);
    LinkedList<int> b(ptr, 6);
    //LinkedList<int> *tmp = a.Concat(&b);
}
