
#include <iostream>
using namespace std;

class Calculator {
public:

    int add(int a, int b) {
        return a + b;
    }
    float add(float a, float b) {
        return a + b;
    }

    float add(int a, float b) {
        return a + b;
    }

    float add(float a, int b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    int x = 10, y = 20;
    float p = 5.5, q = 2.5;

    cout << "Addition of two integers: " << calc.add(x, y) << endl;
    cout << "Addition of two floats: " << calc.add(p, q) << endl;
    cout << "Addition of int and float: " << calc.add(x, p) << endl;
    cout << "Addition of float and int: " << calc.add(p, y) << endl;

    return 0;
}
