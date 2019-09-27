#ifndef ITERATOR_H
#define ITERATOR_H
#include <stack>
#include "node.h"

template <typename T> 
class Iterator {
    private:
        Node<T> *current = nullptr;
        std::stack<Node<T>*> stack_node;

    public:
        Iterator() : current(nullptr) {}



        Iterator(Node<T> *node) : current(node) {

            insert_left(current);
            current = stack_node.top();
        }

        void insert_left(Node<T> *current){
            if(current){
                stack_node.push(current);
                if(current->left){
                    insert_left(current->left);
                }
            }  
            
        }

        Iterator<T>& operator=(const Iterator<T> &other) {          
            // TODO

            this->current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            // TODO
            if(this->current->data != (other.current)->data){return true;}
            return false;
        }

        Iterator<T>& operator++() {
            // TODO

            this->current = stack_node.top();
            stack_node.pop();
            if(this->current->right){
                insert_left(current->right);
            }
            return *(this);

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
