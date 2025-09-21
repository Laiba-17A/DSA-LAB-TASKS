#include <iostream>
using namespace std;

class Box {
private:
    int* val;
public:
    Box(int v = 0) {
        val = new int(v);
        cout << "Parameterised Constructor " << *val << endl;
    }
    ~Box() {
        cout << "Destructor called " << endl;
        delete val;
    }
    Box(const Box& other) {
        val = new int(*(other.val));
        cout << "Copy constructor " << *val << endl;
}
    Box& operator=(const Box& other) {
        cout << "Copy assignment operator" << endl;
        if (this == &other)
            return *this;
        delete val;
        val = new int(*(other.val));
        return *this;
    }
    int get() const {
        return *val;
    }
    void set(int v) {
        *val = v;
    }
};
int main(){
    Box b1(10);
    Box b2 = b1;
    b2.set(20);
    cout << "b1 value: " << b1.get() << endl;
    cout << "b2 value: " << b2.get() << endl;
    Box b3(30);
    b3 = b1;
    cout << "b3 value: " << b3.get() << endl;
    b3.set(40);
    cout << "b1 value: " << b1.get() << endl;
    cout << "b3 value: " << b3.get() << endl;
    return 0;}



