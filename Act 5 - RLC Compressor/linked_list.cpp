#include <iostream>

class linkedList;

class node{
    private:
        node* next;
        unsigned char data;
    public:
        node(){ this->next = nullptr; };
        node(unsigned char data){ 
            this->next = nullptr; 
            this->data = data;
        };
    friend class linkedList;
};

class linkedList{
    private:
        node* header;
    public:
        linkedList(){
            this->header = nullptr;
        }
        ~linkedList(){
            node* current = this->header;
            while(current){
                node* next = current->next;
                delete current;
                current = next;
            }
        }
        size_t size();
        void insert(unsigned char);
    unsigned char &operator[](const int&);
};

unsigned char &linkedList::operator[](const int &position) {
    node *aux = this->header;

    for (size_t i = 0; i < position; i++){
        aux = aux->next;
    }

    return aux->data;
}

size_t linkedList::size(){

    node* aux = this->header;
    size_t counter = 0;

    while(aux){
        counter++;
        aux = aux->next;
    }

    return counter;
}

void linkedList::insert(unsigned char data){

    node* value = new node(data);
    node* current = this->header;

    if(!this->header){
        this->header = value;
    }else{
        while(current->next){
            current = current->next;
        }
        current->next = value;
    }

}