#ifndef NODE_H
#define NODE_H

template <typename T>
class BSTree; 

template <typename T>
class Iterator; 

template <typename T>
class Node {
	Node(T data) : data(data), left(nullptr), right(nullptr){}
    T data;
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;

    template<class>
    friend class BSTree; 

    template<class>
    friend class Iterator; 
};

#endif