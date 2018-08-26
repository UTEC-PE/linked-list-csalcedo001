#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <iostream>

template <typename T>
class Iterator {
    private:
        Node <T> *current;

    public:
        Iterator() {
            current = nullptr;
        }
        Iterator(Node <T> *node) {
            current = node;
        }

        Iterator <T> operator = (Iterator <T> node) {
            current = node;
        }
        bool operator != (Iterator <T> cmp) {
            return current != cmp;
        }
        Iterator <T> operator++ () {
            if (current)
                current = current->next;
            
            return this;
        }
        T operator *() {
            return current->data;
        }
};

#endif
