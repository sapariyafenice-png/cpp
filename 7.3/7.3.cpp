
#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
private:
    float temp;

public:
    Celsius(float t = 0) {
        temp = t;
    }

    float getTemp() {
        return temp;
    }

    operator Fahrenheit();

    void display() {
        cout << temp << " °C";
    }
};

class Fahrenheit {
private:
    float temp;

public:
    Fahrenheit(float t = 0) {
        temp = t;
    }

    float getTemp() {
        return temp;
    }

    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }

    void display() {
        cout << temp << " °F";
    }

    bool operator==(Fahrenheit f) {
        return temp == f.temp;
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main() {
    Celsius c1(25);
    Fahrenheit f1;

    f1 = c1;
    cout << "Celsius to Fahrenheit: ";
    f1.display();
    cout << endl;

    Celsius c2;
    c2 = f1;
    cout << "Fahrenheit to Celsius: ";
    c2.display();
    cout << endl;

    Fahrenheit f2(77);
    if (f1 == f2)
        cout << "Temperatures are equal\n";
    else
        cout << "Temperatures are not equal\n";

    float queue[5];
    int front = 0, rear = -1;

    queue[++rear] = c1.getTemp();
    queue[++rear] = c2.getTemp();

    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;

    float arr[3] = {c1.getTemp(), c2.getTemp(), 30};

    cout << "Array: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
