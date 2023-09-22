#include "cache.hpp"

void CacheList<T>::pushtop(T data){

    Node <T> *new_elem = new Node(data, NULL, head);

    if (head != NULL){

        head->prev = new_elem;
    }
    head = new_elem;

    if (tail == NULL){

        tail->prev = head;
    }
}