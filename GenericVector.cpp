/*
 *	======================================
 * 		Program Name: GenericVector.cpp
 *  	Created on: December 20, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */

#include<iostream>
using namespace std;

template<class T>
class Vector
{
    T v[20];
    int size;
    public:
        void create();
        void modify();
        void mult();
        void display();
};

template<class T>
void Vector<T>::create()
{
    int i;
    T value;
    int ch;
    size=0;
    do
	{
        cout<<"\nEnter the index of the vector & value of any type to be stored:";
        cin>>i>>value;
        v[i]=value;
        size++;
        cout<<"\nDo you want to enter more elements?[1 for YES | 0 for NO]";
        cin>>ch;
    }while(ch==1);
}

template<class T>
void Vector<T>::modify()
{
    int key;
    T newval;
    cout<<"\nEnter index value for modificaion:";
    cin>>key;
    cout<<"\nEnter new value:";
    cin>>newval;
    v[key]=newval;
}

template<class T>
void Vector<T>::mult()
{
    int i;
    int scalarval;
    cout<<"\nEnter scalar value for multiplication-->";
    cin>>scalarval;
    for(i=0;i<size;i++)
    {
    	v[i]=v[i]*scalarval;
	}
}

template<class T>
void Vector<T>::display()
{
    int i;
    cout<<"\nSize of vector is:"<<size;
    cout<<"\nElements in vector are:";
    cout<<"(";
    for(i=0;i<size;i++)
    {
        cout<<v[i]<<",";
    }
    cout<<")";
}

int main()
{
    int ch;
    Vector<int>obj;
    cout<<"\n=======WELCOME==========";
    do
    {
    	cout<<"\n=======================";
        cout<<"\n1.Create Vector(Add elements into Vector)\n2.Display elements from the Vector\n3.Multiply Vector eith Scalar Value\n4.Modify the elements in the Vector\n5.EXIT";
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                obj.create();
                break;
               
            case 2:
                obj.display();
                break;
               
            case 3:
                obj.mult();
                break;
               
            case 4:
                obj.modify();
                break;
               
            case 5:
                goto exit;
                break;
               
            default:
                cout<<"\nPlease enter correct choice!";
                break;
        }
    }while(ch!=0);
    
    exit:
    	cout<<"\n======THANK YOU!=======";
    return 0;
}


