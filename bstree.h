#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;

    public:
        BSTree() : root(nullptr) {};

        bool find(T data) { 
            // TODO
            Node<T> **current = &(this->root);
            while(*current!=nullptr){
                if((*current)->data > data){
                    *current = (*current)->left;
                } 
                else if((*current)->data < data){
                    *current = (*current)->right;
                }
                else if((*current)->data == data){
                    return true;
                }
                
            }
            return false;
        } 

        bool insert(T data) {
            // TODO            
            Node<T> *nuevo = new Node<T>(data);
            if(this->root == nullptr){
                this->root = nuevo;
                return true;
            }
            Node<T> **current = &(this->root);

            while(true){
                if((*current)->data > data){
                    current = &(*current)->left;
                    if(*current == nullptr){
                        *current = nuevo;
                        break;
                    }
                }
                else{
                    current = &(*current)->right;
                    if(*current == nullptr){
                        *current = nuevo;
                        break;
                    }
                }
            }


        }

        bool remove(T data) {
            // TODO

        }

        size_t size() {
            // TODO
            Node<T> **current = &(this->root);
            while(true){
                if((*current)->data > data){
                    current = &(*current)->left
                }
            }
        }

        size_t height() {
            // TODO
        }

        void traversePreOrder() {
            // TODO
            Node<T> **current = &(this->root);
            print(current);
        
        }

        void print(Node<T> **current){

            std::cout<<(*current)->data<<" - ";



            if((*current)->left!=nullptr){
                print(&((*current)->left));
            }
            
           
           
            if((*current)->right!=nullptr){
                print(&((*current)->right));
            }

        }


        void traverseInOrder() {
            // TODO
        }

        void traversePostOrder() {
            // TODO
        }

        Iterator<T> begin() {
            // TODO
        }

        Iterator<T> end() { 
            // TODO
        }

        ~BSTree() {
            // TODO
        }
};

#endif
