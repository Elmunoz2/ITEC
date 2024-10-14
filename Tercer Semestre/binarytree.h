#ifndef BINARYTREE_H
#define BINARYTREE_H

// Definición de la estructura de un nodo del árbol binario
struct Node {
    int data;  // Valor del nodo
    Node* left;  // Puntero al subárbol izquierdo
    Node* right; // Puntero al subárbol derecho

    // Constructor del nodo
    Node(int value);
};

// Definición de la clase del árbol binario
class BinaryTree {
public:
    Node* root;  // Raíz del árbol

    // Constructor
    BinaryTree();

    // Métodos del árbol binario
    Node* insert(Node* node, int value);   // Inserción de un valor en el árbol
    Node* search(Node* node, int value);   // Búsqueda de un valor en el árbol
    void preorder(Node* node);             // Recorrido en preorden (opcional para pruebas)
};

#endif
