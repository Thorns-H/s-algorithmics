#include "LinkedList.h"
#include "Helpers.cpp"

void LinkedList::Insert(std::string name, std::size_t size){

    Node *aux = new Node(name, size);

    if(!this->head){
        this->head = aux;
    }else{
        aux->next = this->head;
        this->head = aux;
    }
}

void LinkedList::InsertDuplicate(std::string name, std::size_t size){

    Node *aux = new Node(name, size);
    Node *check = this->duplicates;

    while(check){
        if(check->data.getName() == name){
            return;
        }
        check = check->next;
    }

    if(!this->duplicates){
        this->duplicates = aux;
    }else{
        aux->next = this->duplicates;
        this->duplicates = aux;
    }
}

void LinkedList::clearDuplicates(){

    Node *aux = this->duplicates;
    Node *ref;
    
    while(aux){
        Erase(aux->data.getName());
        moveFile(aux->data.getName());
        aux = aux->next;
    }

    this->duplicates = nullptr;
}

void LinkedList::Show(){

    Node *aux = this->head;

    std::cout << "\t   Archivos en el Directorio:\n\n";

    while(aux){
        std::cout << "\t - Archivo: " << aux->data.getName() << ", " << aux->data.getBytes() << " bytes.\n";
        aux = aux->next;
    }
}

File& LinkedList::operator[](const int &position) {
    Node *aux = this->head;

    for (int i = 0; i < position; i++){
        aux = aux->next;
    }

    return aux->data;
}

std::size_t LinkedList::getSize(){
    Node *aux = this->head;
    std::size_t iterator = 0;

    while (aux){
        iterator++;
        aux = aux->next;
    }

    return iterator;    
}

void LinkedList::BubbleSort(){

    File swap;

    if(this->head){
        for (int i = 0; i < getSize(); i++){
            bool flag = false;
            for (int j = 0; j < getSize() - i - 1; j++){
                if (areFilesEqual((*this)[j].getName(), (*this)[j+1].getName())){
                    InsertDuplicate((*this)[j+1].getName(), (*this)[j+1].getBytes());
                }else{
                    if((*this)[j].getBytes() < (*this)[j+1].getBytes()){
                        flag = true;
                        swap = (*this)[j];
                        (*this)[j] = (*this)[j+1];
                        (*this)[j+1] = swap;
                    }
                }   
            }
            if(!flag){
                return;
            }
        }
    }
}

void LinkedList::Erase(std::string file){
    
    Node *current, *behind;
    current = this->head;

    if(file == current->data.getName()){
        this->head = this->head->next;
    }else{
        while(file != current->next->data.getName()){
            current = current->next;
        }
        behind = current;
        current = current->next;
        behind->next = current->next;
    }
        delete current;
}