#include <iostream>

class LinkedList;
class Node;

class File{
    private:
        std::string name;
        std::size_t bytes;
    public:
        File(){};
        File(std::string name, std::size_t bytes){
            this->name = name;
            this->bytes = bytes;
        }
        std::string getName(){ return this->name; }
        std::size_t getBytes(){ return this->bytes; }
    friend class Node;
    friend class LinkedList;
};

class Node{
    private:
        Node *next;
        File data;
    public:
        Node(std::string name, std::size_t size){
            this->next = nullptr;
            this->data = File(name, size);
        };
    friend class LinkedList;
};

class LinkedList{
    private:
        Node *head;
        Node *duplicates;
    public:
        LinkedList(){ 
            this->head = nullptr;
            this->duplicates = nullptr;
        }
        void Insert(std::string, std::size_t);
        void InsertDuplicate(std::string, std::size_t);
        void clearDuplicates();
        void Show();
        std::size_t getSize();
        void BubbleSort();
        void Erase(std::string);
        File &operator[](const int&);
};