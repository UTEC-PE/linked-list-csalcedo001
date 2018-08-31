#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    struct Node* next;

    void killSelf() {
        if (next) {
            next->killSelf();

            delete this; // Esto debería estar afuera
        }
    }
};

#endif
