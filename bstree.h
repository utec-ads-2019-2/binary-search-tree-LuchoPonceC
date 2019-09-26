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
            
            return find(current, data);
        } 

        bool find(Node<T> **& current, T data){
            
            if((*current)->data < data){
                current = &((*current)->right);
                return find(current, data);
            }
            else if((*current)->data > data){
                current = &((*current)->left);
                return find(current, data);
            }
            else if((*current)->data == data){
                return true;
            }
            
            return false;
        }


        bool insert(T data) {
            // TODO            
            Node<T> **current = &(this->root);

            while(*current){
                if((*current)->data > data){
                    current = &(*current)->left;
                }
                else{
                    current = &(*current)->right;
                }
            }
            (*current) = new Node<T>(data); 


        }

        bool remove(T data) {
            // TODO
            Node <T> **current = &(this->root);
            if(find(current,data)){
                remove(current, data);
            }

        }

        void remove(Node<T> **& current, T data){

            Node<T> **temp = current;

            if((*current)->left != nullptr && ((*current)->right) == nullptr){
                
                *current = (*current)->left;
            }
            else if((*current)->left == nullptr && ((*current)->right) != nullptr){
                
                *current = (*current)->right;
            }

            else if((*current)->left != nullptr && ((*current)->right) != nullptr){
                
                temp = getMax(current);
                swap((*temp)->data,(*current)->data);

            }
            

            delete *temp;
            *current = nullptr;
        }

        Node<T>** getMax(Node <T> **temp){
            temp = &((*temp)->left);
            while((*temp)->right){
                temp = &((*temp)->right);
            }
            return temp;
        }



        size_t size() {
            // TODO
            Node<T> **current = &(this->root);
            return size(current);
        }

        size_t size(Node<T> **current){
            if(*current){
                return 1 + size(&((*current)->left)) + size(&((*current)->right)); 
            }
            return 0;
            
        }

        size_t height() {
            // TODO
            return height(root);
        
        }
        size_t height(Node<T>* current) {

            if(!current) {
                return -1;
            }
            else {
                size_t lef = height(current->left);
                size_t rig = height(current->right);
                size_t max = (lef>rig)? lef : rig;
                return 1+max;
            }
        }

        void traversePreOrder() {
            // TODO
            Node<T> **current = &(this->root);
            print_traverse(current);
            std::cout<<std::endl;
        
        }

        void print_traverse(Node<T> **current){

            std::cout<<(*current)->data<<" - ";

            if((*current)->left!=nullptr){
                print_traverse(&((*current)->left));
            }
                       
            if((*current)->right!=nullptr){
                print_traverse(&((*current)->right));
            }

        }


        void traverseInOrder() {
            // TODO
            Node<T> **current = &(this->root);
            traverseInOrder(current);
            std::cout<<std::endl;
        }

        void traverseInOrder(Node<T> **current){

            if((*current)->left!=nullptr){
                traverseInOrder(&((*current)->left));
            }

            std::cout<<(*current)->data<<" - ";
                       
            if((*current)->right!=nullptr){
                traverseInOrder(&((*current)->right));
            }

        }

        void traversePostOrder() {
            // TODO
            Node<T> **current = &(this->root);
            traversePostOrder(current);
            std::cout<<std::endl;
        }

        void traversePostOrder(Node<T> **current){

            if((*current)->left!=nullptr){
                traversePostOrder(&((*current)->left));
            }
                       
            if((*current)->right!=nullptr){
                traversePostOrder(&((*current)->right));
            }

            std::cout<<(*current)->data<<" - ";

        }


        void moreLeft(Node<T> **&current){
            if((*current)->left){
                current = &((*current)->left);
                moreLeft(current);
            }
        }

        void moreRight(Node<T> **&current){
            if((*current)->right){
                current = &((*current)->right);
                moreRight(current);
            }
        }

        Iterator<T> begin() {
            // TODO
            Node<T> **current = &this->root;
            moreLeft(current);
            return *current;
        }

        Iterator<T> end() { 
            // TODO
            return nullptr;
        }

        ~BSTree() {
            // TODO
            delet_all(root);
        }

        void delet_all(Node<T>* current) {
            if(!current->right and current->left) {
                delet_all(current->left);
            }
            if(!current->left and current->right) {
                delet_all(current->right);
            }
            if(current->right and current->left) {
                delet_all(current->left);
                delet_all(current->right);
            }
            delete current;
            current = nullptr;
        }


};

#endif
