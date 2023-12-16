/*
 *	======================================
 * 		Program Name: Theatre.cpp
 *  	Created on: December 22, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */
 
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Node
{
char ch;
int no;
Node *prev,*next;
}*head;

Node* arr[15];
Node *tmp=NULL;

class Theatre
{
    int pswd;

public:
void create()
{
int i,j;
   Node *head, *tmp;
   int seatno=1;

for(i=0;i<15;i++)
{
Node *nn=new Node();
head=nn;
arr[i]=head;
nn->prev=NULL;
nn->ch='V';
nn->no=seatno;
seatno++;
tmp=nn;
for(j=1;j<10;j++)
{
Node *nn1 = new Node();
tmp->next=nn1;
nn1->prev=tmp;
nn1->next=NULL;
nn1->ch='V';
nn1->no=seatno;
seatno++;
tmp=nn1;
}
}
}

void display()
{
int i,j;
cout<<"============================== Screen this way ==============================\n\n";
for(i=0;i<15;i++)
{
Node *tmp=arr[i];
for(j=0;j<10;j++)
{
cout<<"|"<<tmp->no<<"|"<<tmp->ch<<"|";
cout<<"  ";
// cout<<"\t";
tmp=tmp->next;
}
cout<<"\n";
}
}

void display_vacant()
{
   int i,j;
cout<<"============================== Screen this way ==============================\n\n";
for(i=0;i<15;i++)
{
Node *tmp=arr[i];
for(j=0;j<10;j++)
{
    if(tmp->ch=='B')
    {
        cout<<"|"<<tmp->ch<<"|";
        cout<<"  ";
    }
    else{
        cout<<"|"<<tmp->no<<"|"<<tmp->ch<<"|";
        cout<<"  ";
        // cout<<"\t";
    }
tmp=tmp->next;
}
cout<<"\n";
}
}

void book()
{
    int no,row,col,i;
    cout<<"Enter seat number to book the seat: ";
    cin>>no;
    row = floor(no/10);
    if(no%10==0)
    {
    	row=row-1;
    	col=10;
		}
		else{
    col=no%10;
  	}
    Node *tmp;
    tmp=arr[row];
    if(tmp->ch=='V')
    {
        cout<<"Enter your security pin: ";
        cin>>pswd;
        for(i=1;i<col;i++)
        tmp=tmp->next;
        tmp->ch='B';
    }
    else
    {
        cout<<"This seat is already booked!";
    }
}

void cancel()
{
    int no,row,col,i;
    cout<<"Enter seat number to cancel the seat: ";
    cin>>no;
    row = floor(no/10);
    if(no%10==0)
    {
    	row=row-1;
    	col=10;
		}
		else{
			col=no%10;
		}
    Node *tmp;
    tmp=arr[row];
    for(i=1;i<col;i++)
        tmp=tmp->next;
    if(tmp->ch=='B')
    {
        int no1;
        cout<<"Enter your security pin: ";
        cin>>no1;
        if(pswd==no1)
        {
            tmp->ch='V';  
            cout<<"Your booking has been successfullly cancelled!";
        }
        else
        {
            cout<<"\nSecurity password Mismatch!";
        }
    }
    else
    {
        cout<<"This seat is not booked!";
    }
}

};

int main() {
Theatre t;
int ch;

t.create();

do{
cout<<"========== Welcome to the  Terrible Theatre ==========";
cout<<"\n1. Display all seats status\n2. Display vacant seats\n3. Book a seat\n4. Cancel a seat\nEnter your choice: ";
cin>>ch;

switch(ch)
{
    case 1:
        t.display();
    break;
    case 2:
        t.display_vacant();
    break;
    case 3:
        t.book();
    break;
    case 4:
        t.cancel();
    break;
}

cout<<"\nTo continue press 1: ";
cin>>ch;

}while(ch==1);
cout<<"Thankyou!";
return 0;
}
