/*
 *	======================================
 * 		Program Name: MapSTL.cpp
 *  	Created on: December 22, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */

#include <iostream>
#include <iomanip>
#include <map> // ...STL MAP
using namespace std;


class Person
{
	private:
	    string name;
	    string dob;
	    long int tel;
	
	public:
	    void Input();
	    friend ostream &operator<<(ostream &out, const Person &r);
};

// displaying data..
ostream &operator<<(ostream &out, const Person &p)
{
    out << left << setw(10) << p.name;
    out << left << setw(13) << p.dob;
    out << left << setw(10) << p.tel;
    return out;
}

// function for reading the data
void Person::Input()
{
    cout <<"\nEnter the name: ";
    cin >> name;
    cout <<"\nEnter the Date of Birth (dd/mm/yyyy): ";
    cin >> dob;
    cout <<"\nEnter the telephone number: ";
    cin >> tel;
}

// # Class Map
class Map
{
	    map<int, Person> m; // ...Map [key,data] pair
	public:
	    void add();
	    void display();
	    void search();
	    void del(); // ...Delete Function
	    void update();
};

//adding data..
void Map::add()
{
    int key;
    Person p;
    cout <<"\nEnter ID: ";
    cin >> key;
    cout <<"Enter the Person Data:\n";
    p.Input();
    m.insert(pair<int, Person>(key, p));
}

//displaying data..
void Map::display()
{
    cout << "\n================================================\n";
    cout << left << setw(10) << "ID";
    cout << left << setw(13) << "Name";
    cout << left << setw(10) << "DOB";
    cout << left << setw(10) << "Telephone";
    cout << "\n================================================\n";
    
    //iterator..
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
        cout << left << setw(10) << i->first;
        cout << i->second;
        cout << "\n================================================\n";
    }
}

//searching the data..
void Map::search()
{
    int key, flag = 0;
    cout <<"\nEnter ID of the person you want to search: ";
    cin >> key;
    //iterator..
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
        if (i->first == key)
        {
            flag = 1;
            cout <<"\nData Found Successfully!!" << endl;
            cout <<"\n================================================\n";
            cout << left << setw(10) << "Name";
            cout << left << setw(13) << "DOB";
            cout << left << setw(10) << "Telephone";
            cout <<"\n================================================\n";
            cout << i->second;
            cout <<"\n================================================\n";
            break;
        }
    }
    if (flag == 0)
        cout <<"\nEntered ID does not exist in the database..!!\n";
}

// # Delete Data
void Map::del()
{
    int key, flag = 0;
    cout <<"\nEnter the ID of the person you want to delete: ";
    cin >> key;
    //iterator..
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
        if (i->first == key)
        {
            flag = 1;
            m.erase(key);
            cout <<"\nData deleted Successfully!!" << endl;
            break;
        }
    }
    if (flag == 0)
        cout <<"\nEntered ID does not exist in the database..!\n";
}

//updating data..
void Map::update()
{
    int key, flag = 0;
    cout <<"\nEnter the ID of the person you want to update: ";
    cin >> key;
    //iterator..
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
        if (i->first == key)
        {
            flag = 1;
            m.erase(key);
            Person p;
            cout <<"\nEnter updated(new) data: " << endl;
            p.Input();
            m.insert(pair<int, Person>(key, p));
            cout <<"\nData updated Successfully!!" << endl;
            break;
        }
    }
    if (flag == 0)
        cout <<"\nEntered ID does not exist in the database..!\n";
}

// # Main Function
int main()
{
    // # STL MAP
    cout<<"\n=============WELCOME=============";
    cout<<"\n=============MAP STL=============";
    Map t;
    int ch,doch;
    do
    {
        cout << "\n====================";
        cout << "\n1.Add Record"
             << "\n2.Display Record"
             << "\n3.Search Record"
             << "\n4.Delete Record"
             << "\n5.Update Record"
             << "\n6.Exit";
        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nAdd Record==>" << endl;
            t.add();
            break;

        case 2:
            cout << "\nDisplay Record==>" << endl;
            t.display();
            break;

        case 3:
            cout << "\nSearch Record:==>" << endl;
            t.search();
            break;

        case 4:
            cout << "\nDelete Record==>" << endl;
            t.del();
            break;

        case 5:
            cout << "\nUpdate Record==>"<< endl;
            t.update();
            break;

        case 6:
            goto exit;
            break;

        default:
            cout << "\nPlease enter correct choice!" << endl;
            break;
        }
        cout<<"\n====\nDo you want to continue?[1 for YES || 0 for NO]";
        cin>>doch;
    } while (doch=1);
    
    exit:
    	cout<<"\n===========THANK YOU!==============";
    return 0;
}

