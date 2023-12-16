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

Node* arr[10];
Node *tmp=NULL;

class Theatre
{
    int pswd;
	public:
		//creating a theatre seats
		void create()
		{
			int i,j;
			Node *head, *tmp;
			int seatno=001;
			for(i=1;i<11;i++)
			{
				Node *nn=new Node();
				head=nn;
				arr[i]=head;
				nn->prev=NULL;
				nn->ch='V';
				nn->no=seatno;
				seatno++;
				tmp=nn;
				for(j=1;j<4;j++)
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
		
		//displaying the all seat status
		void display()
		{
			int i,j;
			cout<<"============================== FRONT ==============================\n\n";
			for(i=1;i<11;i++)
			{
				Node *tmp=arr[i];
				for(j=1;j<5;j++)
				{
					cout<<"|"<<tmp->no<<"|"<<tmp->ch<<"|";
					cout<<"  ";
					// cout<<"\t";
					tmp=tmp->next;
				}
				cout<<"\n";
			}
		}
		
		//displaying only vacant seats
		void display_vacant()
		{
			int i,j;
			cout<<"============================== FRONT ==============================\n\n";
			for(i=1;i<11;i++)
			{
				Node *tmp=arr[i];
				for(j=1;j<5;j++)
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
		
		//function for booking a seat
		void book()
		{
		    int no,row,col,i;
		    cout<<"Enter seat number to book the seat: ";
		    cin>>no;
		    row = (floor(no/4))+1;
		    col=no%4;
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
		
		//function for cancelling booking
		void cancel()
		{
		    int no,row,col,i;
		    cout<<"Enter seat number to cancel the seat: ";
		    cin>>no;
		    row = floor(no/4);
		    col=(no%4)-1;
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

int main() 
{
	Theatre t;
	int ch;
	
	t.create();
	
	do{
	cout<<"========== Welcome to the  Pavillion Multiplex==========";
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
