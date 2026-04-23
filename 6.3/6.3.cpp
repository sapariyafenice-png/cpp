#include<iostream>
using namespace std;
class fuel
{
protected:
string Fuel;
public :
    fuel()
    {
       Fuel="petrol";
    }
     fuel(string f)
    {
       Fuel=f;
    }
};
class brand
{
    protected:
   string Brand;
public:
    brand()
    {
       Brand="kia";
    }
    brand(string b)
    {
       Brand=b;
    }
};
class car : public fuel,public brand
{
    protected:

    string model_name;
public:
    car() : fuel(),brand()
    {
        model_name="kia";
    }

    car(string f,string b,string m) : fuel(f),brand(b)
    {
        model_name=m;
    }
   public:
       void display()
       {
        cout << "\n--- Car Details ---" << endl;
        cout << "Brand Name : " << Brand << endl;
        cout << "Model Name : " << model_name << endl;
        cout << "Fuel Type  : " << Fuel << endl;

       }
};
int main()
{

//    car c;
    string Fuel, Brand, model_name;
    int n;
car c1;
    c1.display();
    cout << "Enter number of cars: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "\nEnter details for Car " << i + 1 << endl;

        cout << "Enter Fuel Type (Petrol/Diesel/Electric): ";
        cin >> Fuel;

        cout << "Enter Brand Name: ";
        cin >> Brand;

        cout << "Enter Model Name: ";
        cin >> model_name;

        car c(Fuel, Brand, model_name);
        c.display();
    }

    return 0;
}

