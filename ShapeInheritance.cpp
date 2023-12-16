/*
 *	======================================
 * 		Program Name: ShapeInheritance.cpp
 *  	Created on: November 30, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */
/*
	How the inheritance in program will work??
	==>>
	===============================================================================
								Class Shape
									 ||
									 ||
					==================================
					||								||
					||								||
				class Triangle					class Rectangle
	
	===============================================================================
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Shape
{
	protected:
		//data members for class Shape
		double height,base;
		
	public:	
		//function for accepting the values from the user
		void get_data()
		{
			cout<<"\n==============================";
			cout<<"\nEnter the value of height for the selected geometrical object:";
			cin>>height;
			cout<<"\nEnter the value of base for the selected geometrical object:";
			cin>>base;
			cout<<"\n==============================";
			cout<<"\nValues are entered successfully!!";
			cout<<"\n==============================";	
		}
	
		//pure virtual function for computing and displaying the results
		virtual void display_area()=0;
};

class Triangle:public Shape
{
	public:
		void display_area()
		{
			cout<<"\n\n==================SELECTED OBJECT IS TRIANGLE=================";
			cout<<"\nThe height of the triangle is: "<<height<<" units.";
			cout<<"\nThe base of the triangle is: "<<base<<" units."; 
			double area=(0.5*height*base);
			cout<<"\nThe area of Triangle with height "<<height<<" and base "<<base<<" is: "<<area<<" units sq.";\
			cout<<"\n==============================================================\n\n";
		}
};

class Rectangle:public Shape
{
		public:
		void display_area()
		{
			cout<<"\n==================SELECTED OBJECT IS RECTANGLE=================";
			cout<<"\nThe breadth of the rectangle is: "<<height<<" units.";
			cout<<"\nThe length of the rectangle is: "<<base<<" units."; 
			double area=(height*base);
			cout<<"\nThe area of Rectangle with breadth "<<height<<" and height "<<base<<" is: "<<area<<" units sq.";\
			cout<<"\n================================================================\n\n";
		}
};

int main()
{
	int ch,ch1;
	Triangle t;
	Rectangle r;
	do
	{
		cout<<"\n=====================WELCOME====================";
		cout<<"\nGeometrical objects available are:\n1.TRIANGLE\n2.RECTANGLE\n3.EXIT";
		cout<<"\nSelect the appropriate option you want:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				t.get_data();
				t.display_area();
				break;
			
			case 2:
				r.get_data();
				r.display_area();
				break;
			
			case 3:
				goto exit1;
				break;	
		}
		cout<<"\nDo you want to continue with geometrical objects? [1-YES||0-NO]-->";
		cin>>ch1;
	}while(ch1==1);
	exit1:
		cout<<"\n===============THANK YOU!================";
	return 0;
}


