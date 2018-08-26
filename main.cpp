#include <iostream>
#include "list.h"
#include "node.h"
#include "iterator.h"

using namespace std;

int main (void) {
    cout << endl;
    cout << "Constructor:" << endl;
    cout << "List <int> L;" << endl << endl;

    List <int> L;

    cout << "L.push_front() and L.push_back()" << endl;

    for (int i = 0; i < 10; i++) {
        L.push_front(i);
        L.push_back(i * i);
    }

    cout << "L.print(): " << endl;
    L.print();

    cout << "L.pop_front(): " << endl;
    L.pop_front();
    L.print();

    cout << "L.pop_back(): " << endl;
    L.pop_back();
    L.print();

    cout << "L.print_reverse" << endl;
    L.print_reverse();

    cout << "L.front() = " << L.front() << endl;
    cout << "L.back() = " << L.back() << endl;
    cout << "L.size() = " << L.size() << endl;
    cout << "L.get(2) = " << L.get(2) << endl;
    cout << "L.empty() = " << L.empty() << endl << endl;

    cout << "New list: L2" << endl;

    List <int> L2;

    for (int i = 0; i < 5; i++)
        L2.push_back(i);


    cout << "L2.print()" << endl;

    L2.print();

    cout << "L.concat(L2)" << endl;

    L.concat(L2);
    L.print();

    cout << "L2.empty() = " << L2.empty() << endl;

    cout << "L.clear()" << endl;

    List <int> :: Iterator <int> i = L.begin();

    cout << i << endl;

    L.clear();

    cout << "L.empty() = " << L.empty() << endl << endl;

    return 0;
}
