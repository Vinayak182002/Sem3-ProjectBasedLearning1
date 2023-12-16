/*
 *	======================================
 * 		Program Name: PizzaBurgerSET.cpp
 *  	Created on: December 22, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */
 
 #include <iostream>
using namespace std;
class Customer
{
    public:
    void wholikespizza(char pizza[], int n)
    {
        cout << "\n";
        cout<<"\n==================PIZZA===================";
        for (int i = 0; i < n; i++)
        {
            cout<<"\nDoes Customer "<<i+1<<" like PIZZA [YES(y) OR NO(n)]: ";
            cin>>pizza[i];
        }
        cout << "\n";
    }
    void wholikesburger(char burger[], int n)
    {
        cout<<"\n\n==================BURGER==================";
        for (int i = 0; i < n; i++)
        {
            cout<<"\nDoes Customer " <<i+1<<" like BURGER [YES(y) OR NO(n)]: ";
            cin>>burger[i];
        }
        cout << "\n";
    }
};
int main()
{
    Customer c;
    int n;
    cout<<"\nEnter the number of customers you want? ";
    cin>>n;
   
    char pizza[n];
    char burger[n];
    c.wholikespizza(pizza,n);
    c.wholikesburger(burger,n);
    int pcounter=0;
    int bcounter=0;
    int bothcounter=0;
    int pub;
    int ch;
    for(int i=0;i<n;i++)
            {
                    if(pizza[i]=='y'&&burger[i]=='y')
                        bothcounter++;
                    if(pizza[i]=='y')
                        pcounter++;
                    if(burger[i]=='y')
                        bcounter++;
            }
            pub=(pcounter+bcounter)-bothcounter;
            cout<<"\nA) Set of customers who like either pizza or burger or both: "<<pub;
            cout<<"\n\nB) Set of customers who like both pizza and burger: "<<bothcounter;
            cout<<"\n\nC) Set of customers who like only pizza, not burger: "<<pcounter;
            cout<<"\n\nD) Set of customers who like only burger not pizza: "<<bcounter;
            cout<<"\n\nE) Set of customers who like neither pizza nor burger: "<<n-pub;
   
}
