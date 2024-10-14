#include <iostream>
using namespace std;

class Queue {
private:
    int frontIndex, rearIndex, size;
    int* arr;  // arreglo dinámico para almacenar los elementos de la cola
    int capacity;

public:
    // Constructor para inicializar la cola con una capacidad específica
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    // Destructor para liberar memoria
    ~Queue() {
        delete[] arr;
    }

    // Insertar un elemento al final de la cola (enqueue)
    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;  // Cola circular
        arr[rearIndex] = value;
        size++;
        cout << value << " enqueued to the queue." << endl;
    }

    // Remover el primer elemento de la cola (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << arr[frontIndex] << " dequeued from the queue." << endl;
        frontIndex = (frontIndex + 1) % capacity;  // Cola circular
        size--;
    }

    // Obtener el primer elemento de la cola sin eliminarlo (front)
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // Verificar si la cola está vacía (isEmpty)
    bool isEmpty() {
        return (size == 0);
    }

    // Verificar el tamaño actual de la cola
    int currentSize() {
        return size;
    }
};

// Prueba de la implementación
int main() {
    Queue q(5);  // Crear una cola con capacidad de 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element is: " << q.front() << endl;

    q.dequeue();
    cout << "Front element after dequeue is: " << q.front() << endl;

    q.enqueue(60);  // Intentar agregar un nuevo elemento cuando la cola está llena

    while (!q.isEmpty()) {
        q.dequeue();
    }

    cout << "Queue is empty now." << endl;

    return 0;
}
