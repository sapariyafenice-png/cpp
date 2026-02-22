#include<iostream>
#include<cmath>
using namespace std;
class Accounts
{  private:
     int Loan_ID;
     string Applicant_name;
     long double P;
     float R;
     float T;
     long double EMI;
  public:
      Accounts()
{
   Loan_ID=22;
   Applicant_name="feni";
   P=3000;
   R=0.1;
   T=3;
   calculate();

}
      Accounts(int l,string n,long double p,float r,float t)
{
     Loan_ID=l;
     Applicant_name=n;
     P=p;
     R=r;
     T=t;
     //EMI=emi;
     calculate();
}
    void calculate();
    void display();
};
     void Accounts::calculate()

{

          EMI=(P*R*pow((1+R),T)/pow((1+R),T)-1);
}
         void Accounts::display()
          {
cout<<"________________DISPLAY____________________________"<<endl;
        cout << "Loan ID: " << Loan_ID << endl;
        cout << "Applicant Name: " << Applicant_name << endl;
        cout << "Principal Amount: " << P << endl;
        cout << "Rate of Interest: " << R  << "%" << endl;
        cout << "Time (Years): " << T << endl;
        cout << "Calculated EMI: " << EMI << endl;
          }
          int main()
           {
               int n;
               Accounts A1;
              A1.display();
              cout<<"enter the Member  number :";
              cin>>n;
              Accounts A[100];

              int Loan_ID,i;
              string Applicant_name;
              long double P;
              float R;
              float T;

 for(i=0;i<n;i++)
 {
     cout<<"_________________DETAILS______________"<<endl;
                  cout<<"ENTER THE LOAN ID:";
                  cin>>Loan_ID;
                  cout<<"\nENTER Applicant_name:";
                  cin>>Applicant_name;
                  cout<<"\nENTER THE P:";
                  cin>>P;
                  cout<<"\nENTER THE R:";
                  cin>>R;
                  cout<<"\nENTER THE T:";
                  cin>>T;

               A[i]=Accounts(Loan_ID, Applicant_name, P, R, T);

 }



            //   A[i]=Accounts(Loan_ID, Applicant_name, P, R, T);
for(i=0;i<n;i++)
{
     A[i].display();
}



              return 0;
            }
