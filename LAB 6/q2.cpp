#include <iostream>
#include <string>

using namespace std;

class Order {
public:
    string name;
    int count;

    Order() : name(""), count(0) {} // default constructor
    Order(string name, int count) : name(name), count(count) {} // parameterized constructor
};

class Queue {
private:
    Order* orders;
    int front;
    int rear;
    int n;    // current size
    int cap;  // capacity

public:

    Queue(int cap) : cap(cap), front(0), rear(0), n(0) {
        orders = new Order[cap];
    }

    ~Queue() {  // destructor
        delete[] orders;
    }

    void enqueue(string item, int quantity) {
        if (n == cap) {
            cout << "Queue is full, cannot take more orders" << endl;
            return;
        }

        orders[rear] = Order(item, quantity);
        rear = (rear + 1) % cap;
        n++;
        cout << "Order added: " << item << " (Quantity: " << quantity << ")" << endl;
    }

    void dequeue() {
        if (n == 0) {
            cout << "The queue is empty. No orders in list" << endl;
            return;
        }

        Order frontOrder = orders[front];
        front = (front + 1) % cap;
        n--;
       
    }

    void printOrders() {
        if (n == 0) {
            cout << "No orders in the queue.\n";
            return;
        }

        cout << "All completed orders:(that are deleted from oredr queue)\n";
        int tempFront = front;
        int tempSize = n;

        while (tempSize > 0) {
            Order order = orders[tempFront];
            cout << "Item: " << order.name << ", Quantity: " << order.count << endl;
            tempFront = (tempFront + 1) % cap;
            tempSize--;
        }
    }

    bool isEmpty() {
        return n == 0;
    }

    bool isFull() {
        return n == cap;
    }
};

int main() {

    Queue orderQueue(5);

    orderQueue.enqueue("Burger", 2);
    orderQueue.enqueue("Pizza", 1);
    orderQueue.enqueue("Pasta", 3);
    orderQueue.enqueue("Salad", 2);
    orderQueue.enqueue("Soda", 4);
    orderQueue.enqueue("Steak", 1); 

    orderQueue.dequeue();
    orderQueue.dequeue();

    orderQueue.printOrders();

    return 0;
}

