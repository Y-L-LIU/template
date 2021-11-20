#include<iostream>
using namespace std;

template<typename T>
class Node{
    private:
        T data;
        Node<T>* next;
    public:
        Node(){
            this->next = nullptr;
        }
        Node(T x){
            this->data=x;
            this->next=nullptr;
        }
};

template<typename T>
class LinkedList{
    private:
        Node<T>* head;
    public:
        int len=0;
        LinkedList(){
            head=new Node<T>();
        }
        ~LinkedList(){}

        void addFront(T item){
            Node<T>* node=new Node<T>(item);
            if(head->next==nullptr)
                head->next=node;
                ++len;
            else{
                ++len;
                node->next=head->next;
                head->next=node;
            }
        };


};

