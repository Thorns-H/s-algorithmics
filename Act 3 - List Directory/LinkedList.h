#include <iostream>

class LinkedList;

class Node{
    private:
        Node *next;
        std::string name;
        std::size_t bytes;
    public:
        Node(std::string name, std::size_t size){
            this->next = nullptr;
            this->name = name;
            this->bytes = size;
        };
    friend class LinkedList;
};

class LinkedList{
    private:
        Node *head;
    public:
        LinkedList(){ this->head = nullptr; }
        void Insert(std::string, std::size_t);
        void Show();
};