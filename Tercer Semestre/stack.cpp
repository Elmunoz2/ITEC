#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;       // arreglo dinámico para almacenar los elementos de la pila
    int topIndex;   // índice para rastrear el elemento superior
    int capacity;   // capacidad máxima de la pila

public:
    // Constructor para inicializar el stack con una capacidad específica
    Stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        topIndex = -1; // La pila empieza vacía
    }

    // Destructor para liberar la memoria reservada
    ~Stack() {
        delete[] arr;
    }

    // Verificar si la pila está vacía
    bool isEmpty() {
        return topIndex == -1;
    }

    // Verificar si la pila está llena
    bool isFull() {
        return topIndex == capacity - 1;
    }

    // Insertar un elemento en la parte superior de la pila (push)
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow. Cannot push " << value << endl;
            return;
        }
        arr[++topIndex] = value;
        cout << value << " pushed onto the stack." << endl;
    }

    // Remover el elemento superior de la pila (pop)
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop." << endl;
            return;
        }
        cout << arr[topIndex--] << " popped from the stack." << endl;
    }

    // Obtener el elemento superior sin removerlo (peek/top)
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // Obtener el tamaño actual de la pila
    int size() {
        return topIndex + 1;
    }
};

// Prueba de la implementación del Stack
int main() {
    Stack s(5);  // Crear un stack con capacidad de 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    cout << "Top element after pop is: " << s.peek() << endl;

    s.push(60);  // Intentar agregar cuando la pila está llena

    while (!s.isEmpty()) {
        s.pop();
    }

    cout << "Stack is empty now." << endl;

    return 0;
}
