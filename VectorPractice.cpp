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
		void multiply();
		void display();
};

template<class T>
void Vector<T>::create()
{
	int i;
	int ch;
	T value;
	do
	{
		cout<<"\nEnter index and value to be inserted in vector";
		cin>>i>>value;
		v[i]=value;
		size++;
		cout<<"\nPress 1 to continue:";
		cin>>ch;
	}while(ch==1);
}

template<class T>
void Vector<T>::modify()
{
	int index;
	T newvalue;
	cout<<"\nEnter the index of element you want to update:";
	cin>>index;
	cout<<"\nEnter new value:";
	cin>>newvalue;
	v[index]=newvalue;
}

template<class T>
void Vector<T>::multiply()
{
	int sv;
	cout<<"\nEnter scalar value you want to multiply elements with:";
	cin>>sv;
	for(int i=0;i<size;i++)
	{
		v[i]*=sv;
	}
}

template<class T>
void Vector<T>::display()
{
	cout<<"\n(";
	for(int i=0;i<size;i++)
	{
		cout<<v[i]<<",";
	}
	cout<<")";
}

int main()
{
	Vector<int> obj;
	int ch,doch;
	do
	{
		cout<<"\n1.Create vector\n2.Modify elements\n3.Multiply all elements with scalar value\n4.Display";
		cout<<"\nEnter:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.create();
				break;
			
			case 2:
				obj.modify();
				break;
			
			case 3:
				obj.multiply();
				break;
			
			case 4:
				obj.display();
				break;
		}
		cout<<"\nPress 1 to continue:";
		cin>>doch;
	}while(doch==1);
	
	return 0;
}
