#include<iostream>
#include<iostream>
#include<stdexcept>
#include<cmath>
using namespace std;

class NegativeNumberException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Negative number not allowed!";
    }
};

int main()
{
    try
    {
        double x;
        cout<<"Enter the number: ";

        if(!(cin >> x))
        {
            throw invalid_argument("Invalid input! Enter a number.");
        }

        if(x < 0)
        {
            throw NegativeNumberException();
        }

        double result = sqrt(x);
        cout<<"RESULT = "<< result << endl;
    }
    catch (const NegativeNumberException &e)
    {
        cout<<"Custom Exception: "<< e.what() << endl;
    }
    catch (const invalid_argument &e)
    {
        cout<< e.what() << endl;
    }

    return 0;
}
