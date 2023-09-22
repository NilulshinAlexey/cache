#include <iostream>

using namespace std;

template <typename T> struct Node{
    
    T data;
    Node *next;
    Node *prev;

    Node(T _data, Node * _next, Node * _prev){

        data = _data;
        next = _next;
        prev = _prev;
    }
};

template <typename T> struct CacheList{

    Node<T> *head = NULL;
    Node<T> *tail = NULL;

    void pushtop(T data); 
};
