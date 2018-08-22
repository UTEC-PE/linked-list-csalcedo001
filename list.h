#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node <T> *head;
        Node <T> *tail;
        int nodes;

        void print_reverse(Node <T> *head) {
            if (head) {
                print_reverse(head->next);
                cout << head->data << " ";
            }
        }

    public:
        List() {
            head = nullptr;
            tail = nullptr;
            nodes = 0;
        }

        T front() {
            if (head)
                return head->data;
            else
                return -1;
        }
        T back() {
            if (tail)
                return tail->data;
            else
                return -1;
        }
        void push_front(T value) {
            Node <T> *new_node = new Node <T>;

            new_node->data = value;
            new_node->next = head;

            if (!head)
                tail = new_node;

            head = new_node;

            nodes++;
        }
        void push_back(T value) {
            Node <T> *new_node = new Node <T>;

            new_node->data = value;
            new_node->next = nullptr;

            if (tail)
                tail->next = new_node;
            else
                head = new_node;

            tail = new_node;

            nodes++;
        }
        void pop_front() {
            if (head) {
                Node <T> *tmp = head;

                head = head->next;

                delete tmp;

                nodes--;
            }
        }
        void pop_back() {
            if (!tail)
                return;

            if (!head->next) {
                delete tail;

                head = nullptr;
                tail = nullptr;
                nodes = 0;

                return;
            }

            Node <T> *tmp = head;

            while (tmp->next != tail)
                tmp = tmp->next;

            tail = tmp;

            delete tmp->next;

            tail->next = nullptr;

            nodes--;
        }
        T get(int position) {
            if (position >= nodes || position < 0)
                return -1;

            Node <T> *tmp = head;

            while (position--)
                tmp = tmp->next;

            return tmp->data;
        }
        void concat(List <T> &other) {
            if (tail)
                tail->next = other.head; // other.head es un atributo privado
            else
                head = other.head;

            tail = other.tail; // también es un atributo privado
            nodes += other.nodes; // también privado
        }
        bool empty() {
            return head == nullptr;
        }
        int size() {
            return nodes;
        }
        void print() {
            for (Node <T> *tmp = head; tmp != nullptr; tmp = tmp->next)
                cout << tmp->data << " ";

            cout << endl;
        }
        void print_reverse() {
            print_reverse(head);

            cout << endl;

            // Node *list[nodes];
            //
            // Node *tmp = head;
            //
            // for (int i = 0; i < nodes; i++, tmp = tmp->next)
            //     list[i] = tmp->data;
            //
            // for (int i = 0; i < nodes; i++)
            //     cout << list[i] << " ";
        };
        void clear() {
            if (head)
                head->killSelf();

            head = nullptr;
            tail = nullptr;
            nodes = 0;
        }
        Iterator <T> begin() {
            return Iterator <T> (head);
        }
        Iterator <T> end() {
            return Iterator <T> (tail);
        }

        ~List() {
            clear();
        }
};

// List :: List() {
//     head = nullptr;
//     tail = nullptr;
//     nodes = 0;
// }
//
// T List :: front() {
//     if (head)
//         return head->data;
//     else
//         return -1;
// }
//
// T List :: back() {
//     if (tail)
//         return tail->data;
//     else
//         return -1;
// }
//
// void List :: push_front(T value) {
//     Node <T> *new_node = new Node <T>;
//
//     new_node->data = value;
//     new_node->next = head;
//
//     if (!head)
//         tail = new_node;
//
//     head = new_node;
//
//     nodes++;
// }
//
// void List :: push_back(T value) {
//     Node <T> *new_node = new Node <T>;
//
//     new_node->data = value;
//     new_node->next = nullptr;
//
//     if (tail)
//         tail->next = new_node;
//     else
//         head = new_node;
//
//     tail = new_node;
//
//     nodes++;
// }
//
// void List :: pop_front() {
//     if (head) {
//         Node <T> *tmp = head;
//
//         head = head->next;
//
//         delete tmp;
//
//         nodes--;
//     }
// }
//
// void List :: pop_back() {
//     if (!tail)
//         return;
//
//     if (!tail->next) {
//         delete tail;
//
//         head = nullptr;
//         tail = nullptr;
//         nodes = 0;
//
//         return;
//     }
//
//     Node <T> *tmp = head;
//
//     while (tmp->next != tail)
//         tmp = tmp->next;
//
//     tail = tmp;
//
//     delete tmp->next;
//
//     tail->next = nullptr;
//
//     nodes--;
// }
//
// T List :: get(int position) {
//     if (position >= nodes || position < 0)
//         return -1;
//
//     Node <T> *tmp = head;
//
//     while (position--)
//         tmp = tmp->next;
//
//     return tmp->data;
// }
//
// void List :: concat(List <T> &other) {
//     if (tail)
//         tail->next = other.head; // other.head es un atributo privado
//     else
//         head = other.head;
//
//     tail = other.tail; // también es un atributo privado
//     nodes += other.nodes; // también privado
// }
//
// bool List :: empty() {
//     return head == nullptr;
// }
//
// int List :: size() {
//     return nodes;
// }
//
// void List :: print() {
//     for (Node <T> *tmp = head; tmp != nullptr; tmp = tmp->next)
//         cout << tmp->data << " ";
//
//     cout << endl;
// }
//
// void List :: print_reverse() {
//     print_reverse(head);
//
//     cout << endl;
//
//     // Node *list[nodes];
//     //
//     // Node *tmp = head;
//     //
//     // for (int i = 0; i < nodes; i++, tmp = tmp->next)
//     //     list[i] = tmp->data;
//     //
//     // for (int i = 0; i < nodes; i++)
//     //     cout << list[i] << " ";
// };
//
// void List :: clear() {
//     head->killSelf();
//
//     head = nullptr;
//     tail = nullptr;
//     nodes = 0;
// }
//
// Iterator <T> List :: begin() {
//     return Iterator(head);
// }
//
// Iterator <T> List :: end() {
//     return Iterator(tail);
// }
//
// List :: ~List () {
//     this.clear();
// }

#endif
