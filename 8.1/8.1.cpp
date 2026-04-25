
#include<iostream>
#include<stdexcept>
using namespace std;

int main()
{
    try
    {
        int a, b;

        cout<<"ENTER TWO NUMBERS: ";

        if(!(cin >> a >> b))
        {
            throw invalid_argument("Invalid input! Enter integers only.");
        }

        if(b == 0)
        {
            throw runtime_error("Division by zero not allowed.");
        }

        cout<<"Result: "<< static_cast<double>(a)/b << endl;
    }
    catch(const invalid_argument &e)
    {
        cout<<e.what()<<endl;
    }
    catch(const runtime_error &e)
    {
        cout<<e.what()<<endl;
    }

    return 0;
}
