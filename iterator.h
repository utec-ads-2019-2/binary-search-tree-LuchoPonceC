#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T> 
class Iterator {
    private:
        Node<T> *current;

    public:
        Iterator() : current(nullptr) {}

        Iterator(Node<T> *node) : current(node) {}

        Iterator<T>& operator=(const Iterator<T> &other) {          
            // TODO

            if(this->current == other->current){
                return current;
            }
            return nullptr;
        }

        bool operator!=(Iterator<T> other) {
            // TODO
            if(this->current->data != other->current->data){return true;}
            return false;
        }

        Iterator<T>& operator++() {
            // TODO
        }

        Iterator<T>& operator--() {
            // TODO
        }

        T operator*() {
            // TODO
            if(!(this->current)) throw out_of_range("List is empty!");
            return this->current->data; 
        }
};

#endif
