/*
 *	======================================
 * 		Program Name: StudentDB.cpp
 *  	Created on: November 25, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//global static variable
static int std_count;

class StudentDB
{
	string std_name;
	int std_rollno;
	string std_class;
	char std_div;
	string std_dob;
	string std_bg;
	string std_contaddr;
	string std_telno;

public:
	StudentDB()
	{
		cout<<"\nConstructor!";
	}
	//definition for static function.
	static void std_countfun(){
		cout<<"\n==================================================================";
		cout<<"\nInside Static function!";
		cout<<"\nTotal no of Students entered in the database are: "<<std_count;
		cout<<"\n==================================================================";
	}

	//declaring member functions
	inline void displayData();
	void insertData(int);

	//use of constructor for initialization of an objects.
	~StudentDB()
	{
		cout<<"\nDestructor!";		
	}

};

void StudentDB::insertData(int max_size)
{
	if(std_count>=max_size){
		cout<<"\nThe max size of the database exceeded! Insertion Operation failed!";
	}
	else{
		cout<<"=====================Insertion Operation=====================";
		cout<<"\nEnter the name of the student:";
		cin>>std_name;
		cout<<"Enter the roll number of the student:";
		cin>>std_rollno;
		cout<<"Enter the class of the student:";
		cin>>std_class;
		cout<<"Enter the division of the student:";
		cin>>std_div;
		cout<<"Enter the date of birth of the student[dd/mm/yyyy]:";
		cin>>std_dob;
		cout<<"Enter the date of blood group of the student[eg:AB+ve]:";
		cin>>std_bg;
		cout<<"Enter the contact address of the student:";
		cin>>std_contaddr;
		cout<<"Enter the telephone number of the student:";
		cin>>std_telno;
		//incrementing count
		std_count++;
	}
}

inline void StudentDB::displayData(){
	cout<<"\n"<<std_rollno<<"\t\t"<<std_name<<"\t\t"<<std_class<<"\t"<<std_div<<"\t\t"<<std_dob<<"\t"<<std_bg<<"\t\t"<<std_contaddr<<"\t\t"<<std_telno;
}

int main()
{
	int ch,doch,size_db;
	cout<<"====================WELCOME====================";
	cout<<"\nEnter the number of students you want to store into database:";
	cin>>size_db;
	int array_index=0;//storing array indexes.
	StudentDB obj1;
	StudentDB obj[size_db+1];//call to default constructor
	do
	{
		cout<<"\n=================================================================";
		cout<<"\n1.Insert Student record in the database.\n2.Display the records in the database.\n3.See the student count entered in the database.\n4.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			obj1.insertData(size_db);
			obj[array_index]=obj1;
			array_index++;
			break;
			
		case 2:
			if(std_count==0){
				cout<<"\nNo records are present! Empty Database-->>";
			}
			cout<<"\n====================================================STUDENT DATBASE=====================================================";
			cout<<"\nRoll No\t\tName\t\tClass\tDivision\tDOB\t\tBG\t\tAddress\t\tTelNo.";
			for(int j=0;j<std_count;j++)
			{
				obj[j].displayData();
			}
			cout<<"\n========================================================================================================================";
			break;

		case 3:
			obj1.std_countfun();
			break;

		case 4:
			goto exit;
			break;

		default:
			cout<<"\nPlease Enter the correct choice!";
			break;
		}
		cout<<"\n=============================\nDo you want to continue?Press 1 for YES and Press 0 for NO-->";
		cin>>doch;
	}while(doch==1);
	exit:
	cout<<"=================Thank You!==================";
	return 0;
}

