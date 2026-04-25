#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string filename;
    ifstream file;

    while (1) {
        cout << "Enter file name (or type exit): ";
        cin >> filename;

        if (filename == "exit")
            return 0;

        file.open(filename);

        if (!file) {
            cout << "File not found! Try again.\n";
        } else {
            break;
        }
    }

    string line;
    int lineNo = 0;

    while (getline(file, line)) {
        lineNo++;

        stringstream ss(line);
        double num, sum = 0;
        int count = 0;

        while (ss >> num) {
            sum += num;
            count++;
        }

        if (count > 0 && ss.eof()) {
            cout << "Line " << lineNo << " -> Sum = " << sum
                 << ", Avg = " << (sum / count) << endl;
        } else {
            cout << "Line " << lineNo << " -> Invalid data, skipped\n";
        }
    }

    file.close();
    return 0;
}
