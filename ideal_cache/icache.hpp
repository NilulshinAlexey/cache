#include <iostream>
#include <vector>

using namespace std;

template <typename T> struct Node{
    
    T data;
    int page_num = 0;
    Node *next;
    Node *prev;

    Node(int _page_num, T _data, Node * _next, Node * _prev){

        page_num = _page_num;
        data = _data;
        next = _next;
        prev = _prev;
    }
};

template <typename T> struct CacheList{

    Node<T> *head = NULL;
    Node<T> *tail = NULL;

    int size;
    int num_elem = 0;

    CacheList(int _size){

        size = _size;
    }

    void pushtop(vector<Node<T>*> &table, T data, int page_num){

        Node<T> *new_elem = new Node<T>(page_num, data, NULL, head);
        if (head != NULL){

            head->prev = new_elem;
            head->prev->next = head;
        }

        head = new_elem;
        if (tail == NULL) tail = head;

        num_elem++;
        table[page_num] = new_elem;
        
        if (num_elem > size){

            table[tail->page_num] = NULL;
            tail = tail->prev;
            delete tail->next;
            num_elem--;
        }
    } 

    void movetop(vector<Node<T>*> &table, T data, int page_num){

        if (table[page_num] == head) return;

        if (table[page_num] == tail){

            tail = table[page_num]->prev;
            table[page_num]->prev->next = NULL;
            pushtop(table, data, page_num);
            return;
        }

        table[page_num]->prev->next = table[page_num]->next;
        table[page_num]->next->prev = table[page_num]->prev;

        pushtop(table, data, page_num);
    }

    void desplayList(){

        Node<T> *node = head;
        while(node != NULL){

            cout << node->page_num << " = ";
            node = node->next;
        }
        cout << "end" << endl;
    }

    void clear(){

        Node<T> *node = head->next;
        while(node->next != NULL && node != NULL)
            delete node->prev;
        delete node;         
    }
};