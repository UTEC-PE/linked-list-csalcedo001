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
                cout << head->data << ", ";
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
                return -1; // Sería mejor mandar una excepción en caso de una lista vacía
        }
        T back() {
            if (tail)
                return tail->data;
            else
                return -1; // Igual que el caso anterior
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
                return -1; // Sería mejor manejarlo con una excepción

            Node <T> *tmp = head;

            while (position--)
                tmp = tmp->next;

            return tmp->data;
        }
        void concat(List <T> &other) {
            // This version of concat clears other
            if (tail)
                tail->next = other.head;
            else
                head = other.head;

            tail = other.tail;
            nodes += other.nodes;

            other.head = nullptr; // No se porque haces esto
            other.tail = nullptr;
            other.nodes = 0;
        }
        bool empty() {
            return head == nullptr;
        }
        int size() {
            return nodes;
        }
        void print() {
            cout << "{";

            for (Node <T> *tmp = head; tmp != nullptr; tmp = tmp->next)
                cout << tmp->data << ", ";

            if (head)
                cout << "\b\b";

            cout << "}" << endl;
        }
        void print_reverse() {
            cout << "{";

            print_reverse(head);

            if (head)
                cout << "\b\b";

            cout << "}" << endl;
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
            return Iterator <T> ();
        }

        ~List() {
            clear();
        }
};

#endif
