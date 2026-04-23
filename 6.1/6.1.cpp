#include<iostream>
using namespace std;
class shape
{
    public:
    float r;
    void get();
    void put();
};
class circle : public shape
{
    float area;
    public:
    float cal();
    void display();

};
void shape :: get()
{


    cout<<"enter the radius:";
    cin>>r;


}
void shape::put()
{
    cout << "Radius is: " << r << endl;
}

float circle :: cal()
{
    area=3.14*r*r;
    return area;
}
void circle::display()
{
    cout << "Area is: " << area << endl;
}
int main()
{
    int i,n;
     cout<<"enter the number of the circle :";
    cin>>n;
    circle c[10];
    for(i=0;i<n;i++)
    {

    c[i].get();
    c[i].put();
    c[i].cal();
    c[i].display();

    }
  return 0;

}

