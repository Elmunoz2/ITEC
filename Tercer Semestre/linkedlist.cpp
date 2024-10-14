#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void addNode(Node* &head, int value){
    Node* newNode = new Node(); //Crea un nuevo Nodo 
    newNode->data = value; // Asignacion de value a la estructura acceciendo a DATA
    newNode->next = nullptr; // el siguiente nodo es Nullptr

    if(head == nullptr){
        head = newNode; //si la lista esta vacia el nuevo nodo es la head
        }
        else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
                }
                temp->next = newNode; // el nuevo nodo se agrega al final de la lista         
    }
}

void showList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << "-->";
        temp = temp->next;
        }
}

int main()
{
    Node* list = nullptr;
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);

    cout << "Lista de Valores" << endl;
    showList(list);
    return 0;

}