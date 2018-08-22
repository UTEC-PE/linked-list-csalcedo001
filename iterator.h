#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node <T> *current;

    public:
        Iterator();
        Iterator(Node <T> *node);

        Iterator <T> operator = (Iterator <T> node);
        bool operator != (Iterator <T> cmp);
        Iterator <T> operator++ ();
        T operator *();
};

Iterator :: Iterator () {
    current = nullptr;
}

Iterator :: Iterator (Node <T> *node) {
    current = node;
}

Iterator <T> operator = (Iterator <T> node) {
    current = node;
}

bool Iterator :: operator != (Iterator <T> cmp) {
    return current != cmp;
}

Iterator <T> Iterator :: operator++ () {
    return current->next;
}

T Iterator :: operator *() {
    return current->data;
}

#endif
