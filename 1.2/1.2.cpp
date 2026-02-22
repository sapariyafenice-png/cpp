
#include <iostream>
using namespace std;

class Rectangle
{
    private:
        int l, b;

    public:
        void setValue(int length, int breadth)
        {
            l=length;
            b=breadth;
        }

        int area()
        {
            return l*b;
        }

        int perimeter()
        {
            return 2*(l+b);
        }

        int checkSquare()
        {
            return (l==b);
        }

        void compare(Rectangle r1,Rectangle r2)
        {
            if(r1.area()>r2.area())
            {
                cout<<"First has larger area";
            }
            else if(r1.area()<r2.area())
            {
                cout<<"Second has larger area";
            }
            else
            {
                cout<<"Both are equal";
            }
        }
};

int main()
{
    int l,b,i,n,x;
    Rectangle r[5];
    cout<<"How many rectangles you want to add:";
    cin>>n;
    for(i=0;i<n;i++)
    {
        y: cout<<"Enter length: ";
        cin>>l;
        cout<<"Enter breadth: ";
        cin>>b;

        if(l>0 && b>0)
        {
            r[i].setValue(l,b);
            x=r[i].checkSquare();
            if(x==1)
            {
                cout<<"IT IS A SQUARE"<<endl;
            }
            else
            {
                cout<<"NOT A SQUARE"<<endl;
            }
            cout<<"Area of "<<i+1<<" is "<<r[i].area()<<endl;
            cout<<"Perimeter of "<<i+1<<" is "<<r[i].perimeter()<<endl<<endl;
        }
        else
        {
            cout<<"INVALID INPUT. TRY AGAIN"<<endl;
            goto y;
        }
    }
    if(n==2)
        {
            r[0].compare(r[0],r[1]);
        }

    return 0;
}
