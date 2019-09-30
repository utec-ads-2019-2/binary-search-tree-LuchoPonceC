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

        // Hay casos donde falla
        bool remove(T data) {
            // TODO
            Node <T> **current = &(this->root);
            if(find(current,data)){
                remove(current, data);
            }
            // Falta return
        }

        // Debería ser privado
        void remove(Node<T> **& current, T data){

            
            Node<T> *temp2 = *current;
            if((*current)->left != nullptr && ((*current)->right) == nullptr){
                
                *current = ((*current)->left);
                //*current = nullptr;

            }
            else if((*current)->left == nullptr && ((*current)->right) != nullptr){
                
                *current = ((*current)->right);
                //*current = nullptr;

            }

            else if((*current)->left == nullptr && ((*current)->right) == nullptr){
                
                *current = nullptr;

            }
            

            else if((*current)->left != nullptr && ((*current)->right) != nullptr){
                Node<T> **temp = current;
                temp = getMax(current);
                temp2 = *temp;

                swap((*temp)->data,(*current)->data);

                current = temp;
                if((*current)){
                    *current = ((*current)->left);
                }


            }
            
            delete temp2;

            
        }

        // Debería ser privado
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


        Iterator<T> begin() {
            // TODO
            
            return Iterator<T>(this->root);
        }

        Iterator<T> end() { 
            // TODO
            return Iterator<T>(nullptr);
        }

        ~BSTree() {
            // TODO
            delet_all(root);
        }

        void delet_all(Node<T>* current) {
            // Mucho código repetido
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
