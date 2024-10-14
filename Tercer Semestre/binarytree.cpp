#include "binarytree.h"
#include <iostream>

using namespace std;

// Implementación del constructor del nodo
Node::Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

// Implementación del constructor del árbol binario
BinaryTree::BinaryTree() {
    root = nullptr;
}

// Implementación del método de inserción
Node* BinaryTree::insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);  // Crear un nuevo nodo
    }
    if (value < node->data) {
        node->left = insert(node->left, value);  // Insertar en el subárbol izquierdo
    } else {
        node->right = insert(node->right, value);  // Insertar en el subárbol derecho
    }
    return node;
}

// Implementación de un recorrido en preorden (opcional para pruebas)
void BinaryTree::preorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Implementación del método search de BinaryTree
Node* BinaryTree::search(Node* node, int value) {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return search(node->left, value);
    }
    return search(node->right, value);
}