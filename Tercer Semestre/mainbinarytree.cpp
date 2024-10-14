#include <iostream>      // Para cout
#include "binarytree.h"  // Incluir el encabezado de BinaryTree

using namespace std;

int main() {
    BinaryTree tree;

    cout << "Hello World" << endl;  // Cambiar comillas simples por dobles

    // Insertar elementos en el árbol binario
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);

    int ValueToSearch = 30;
    Node* result = tree.search(tree.root, ValueToSearch);
    cout << result -> data;

    return 0;  // Retornar 0 al final de main
}



//g++ mainbinary.cpp binarytree.cpp -o binarytree.exe