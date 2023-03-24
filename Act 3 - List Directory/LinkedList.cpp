#include "LinkedList.h"

void LinkedList::Insert(std::string name, std::size_t size){

    Node *aux = new Node(name, size);

    if(!this->head){
        this->head = aux;
    }else{
        aux->next = this->head;
        this->head = aux;
    }

}

void LinkedList::Show(){

    Node *aux = this->head;

    std::cout << "\t   Archivos en el Directorio:\n\n";

    while(aux){
        std::cout << "\t - Archivo: " << aux->name << ", " << aux->bytes << " bytes.\n";
        aux = aux->next;
    }
    
}