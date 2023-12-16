#include<iostream>
#include<fstream>
#include<string.h>
#include <math.h>
#include <iomanip>

using namespace std;

//booking section

class Node
{
	public:
		char ch;
		int no;
		Node *prev,*next;
}*head;

Node* arr[10];
Node *tmp=NULL;

class BookingIntoFile
{
	char name[50];
	int phoneno;
	int busno;
	int noOfSeats;
	
	public:
		void setBookingData(char n[ ],int ph,int busn,int ns)
		{
			strcpy(this->name,n);
			this->phoneno=ph;
			this->busno=busn;
			this->noOfSeats=ns;
		}
		
		void displayBooking()
		{
			cout<<"\n==============================";
			cout<<"\nName of Passenger:"<<this->name;
			cout<<"\nNumber of seats Booked:"<<this->noOfSeats;
			cout<<"\n===============================";
		}
		
		int getBusNo()
		{
			return this->busno;
		}
		
		int getns()
		{
			return this->noOfSeats;
		}
};



class UserDB
{
	char name[50],username[30],password[30];
	int age;
	int phoneno;
	public:
		
		
		void getData()
		{
			cout<<"\n======================";
			cout<<"\nREGISTRATION!!"<<endl;
			cout<<"Enter your full Name: ";
			cin>>this->name;
			cout<<"Enter your age: ";
			cin>>this->age;
			cout<<"Enter your Phone No: ";
			cin>>this->phoneno;
			cout<<"Enter Username: ";
			cin>>this->username;
			cout<<"Enter PASSWORD: ";
			cin>>this->password;
			cout<<"\n======================";
		}
		void displayData()
		{
			cout<<"\n======================";
			cout<<"\nUSER DETAILS:"<<endl;
			cout<<"NAME:"<<this->name<<endl;
			cout<<"USERNAME:"<<this->username<<endl;
			cout<<"AGE:"<<this->age<<endl;
			cout<<"PHONE NUMBER:"<<this->phoneno<<endl;
			cout<<"\n======================";
		}
		
		string getU()
		{
			return this->username;
		}
		
		string getP()
		{
			return this->password;
		}
		
		string getName()
		{
			return this->name;
		}
		
		int getPhoneNo()
		{
			return this->phoneno;
		}
};

class Buses
{
	public:
		int no;
		char src[30],dest[30];
		double time;
		
		void getData()
		{
			cout<<"\n======================";
			cout<<"\nEnter the following details of the Bus ==>"<<endl;
			cout<<"Bus no:";
			cin>>this->no;
			cout<<"\nSource:";
			cin>>this->src;
			cout<<"\nDestination:";
			cin>>this->dest;
			cout<<"\nTime:";
			cin>>this->time;
			cout<<"\n======================";
		}
		void displayData()
		{
			cout<<"\n";
			cout<<"\n===========================";
			cout<<"\nBus No.:"<<this->no;
			cout<<"\nSource:"<<this->src<<" ---> Destination:"<<this->dest;
			cout<<"\nTime:";
			printf("%0.2lf",this->time);
			cout<<"\n===========================";
			cout<<"\n";
		}
};

class Booking
{
	string pswd;
	public:
		void create()
		{
			int i,j;
   			Node *head, *tmp;
   			int seatno=001;
			for(i=0;i<10;i++)
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

		void display()
		{
			int i,j;
			cout<<"========== Entrance ==========\n\n";
			for(i=0;i<10;i++)
			{
				Node *tmp=arr[i];
				for(j=0;j<4;j++)
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
			cout<<"======= Entrance =======\n\n";
			for(i=0;i<10;i++)
			{
				Node *tmp=arr[i];
				for(j=0;j<4;j++)
				{
				    if(tmp->ch=='B')
				    {
				        cout<<"|"<<tmp->ch<<"|";
				        cout<<"  ";
				    }
				    else
					{
				        cout<<"|"<<tmp->no<<"|"<<tmp->ch<<"|";
				        cout<<"  ";
				        // cout<<"\t";
				    }
					tmp=tmp->next;
				}	
				cout<<"\n";
			}
		}

		void book(string pwd,UserDB uObj,Buses bObj)
		{
		    int no,row,col,i,num,flag=0;
		    fstream bfile;
		    BookingIntoFile bif;
		    cout<<"\nHow many seats you want to book?-->";
		    cin>>num;
		    
		    cout<<"\nEnter your password:";
		    cin>>pswd;
		        
		    for(int j=0;j<num;j++)
		    {
			    cout<<"\nEnter seat number to book the seat: ";
			    cin>>no;
			    row = floor(no/4); //1
			    col=no%4; //0
			    if(no%4==0) //0(vary) 4
		    	{
			    	row= (floor((no/4)))-1;
			    	col=4;
				}
			    Node *tmp;
			    tmp=arr[row];
		    	if(tmp->ch=='V')
		    	{
		        	if(pswd==pwd)
		        	{
		        		for(i=1;i<col;i++)
		       			 	tmp=tmp->next;
		       		 	tmp->ch='B';	
		       			cout<<"\nYour seat is successfully booked!";
		       			flag=1;
		       			
					}
					else
					{
						cout<<"\nIncorrect password!";
						break;
					}
		    	}
		    	else
		    	{
		        	cout<<"This seat is already booked!";
		    	}	
			}
			if(flag==1)
			{
				cout<<"\n===================================================================";
				cout<<"\n============================== BILL ===============================";
				cout<<"\n=======================BUS MANAGEMENT SYSTEM=======================";
				cout<<"\n\t\tBus No.:"<<bObj.no;
				cout<<"\n\t\tSource:"<<bObj.src<<" Destination:"<<bObj.dest;
				cout<<"\n\t\tName of the Passanger:"<<uObj.getName();
				cout<<"\n\t\tPhone Number of Passenger:"<<uObj.getPhoneNo();
				cout<<"\n\t\tNumber of Seats:"<<num;
				cout<<"\n\t\tAmount Per Seat: Rs.800";
				cout<<"\n\t\tYour total Billing Amount:"<<num*800;
				cout<<"\nNote:Please handle this bill at the time of your journey..";
				cout<<"\n===================================================================";
				
				bfile.open("userBookings.txt",ios::out|ios::app|ios::binary);
				char passename[50];
				strcpy(passename,uObj.getName().c_str());
				bif.setBookingData(passename,uObj.getPhoneNo(),bObj.no,num);
				bfile.write((char*)&bif,sizeof(BookingIntoFile));
				bfile.close();
			}
			
		}

		void cancel(string p)
		{
		    int no,row,col,i;
		    cout<<"\nEnter seat number to cancel the seat: ";
		    cin>>no;
		    row = floor(no/4); //1
		    col=no%4; //0
		    if(no%4==0) //0(vary) 4
		    {
		    	row= (floor((no/4)))-1;
		    	col=4;
			}
		    Node *tmp;
		    tmp=arr[row];
		    for(i=1;i<col;i++)
		        tmp=tmp->next;
		    if(tmp->ch=='B')
    		{
        		int no1;
        		cout<<"\nEnter your password: ";
        		cin>>pswd;
        		if(pswd==p)
        		{
            		tmp->ch='V';  
            		cout<<"\nYour booking has been successfullly cancelled!";
        		}
        		else
        		{
            		cout<<"\nSecurity password Mismatch!";
        		}
    		}
    		else
    		{
        		cout<<"This seat is not booked!Cancel Operation failed!";
    		}
		}

};

//booking section

class LoginCheck
{
		string username,password;
	public:
		void setdetails(string unm,string paswd)
		{
			username=unm;
			password=paswd;
		}
		string getuname()
		{
			return username;
		}
		string getpass()
		{
			return password;
		}
		void setuname(string unm)
		{
			this->username=unm;
		}
		void setpass(string pas)
		{
			this->password=pas;
		}
		bool checklogin();
};

class Admin:public LoginCheck
{
	public:
		bool checklogin(string uname, string pass)
		{
			if(uname==getuname() && pass==getpass())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};


int main()
{
	int ch,doch,uch,mainch;
	int serID,isfound=0;
	int upID,pos,flag;
	int delID;
	Buses b1,b2,b3;
	fstream file,file2;
	Admin Ad;
	int err=0;
	string u,p,sr,de;
	bool b;
	string uname;
	string bussrc,busdest;
	double time;
	int bn;
	fstream bookingFile;
	BookingIntoFile buf;
	
	//for user side
	UserDB u1,u2;
	int chu,dochu;
	int isfoundu=0;
	Booking t;
	int chx;
	ofstream fout;

	Ad.setdetails("Admin","Admin123");
	do
	{
		cout<<"========== Welcome To Bus management system ==========";
		cout<<"\n1. Admin \n2. Customer\n3. Exit\nEnter: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n====== Admin ======";
				cout<<"\nEnter username: ";
				cin>>u;
				cout<<"Enter password: ";
				cin>>p;
				b=Ad.checklogin(u,p);
				if(b)
				{
					do
					{
						cout<<"\n========= Welcome Admin ==========";
						cout<<"\n1.Add bus record\n2.Search for bus\n3.Remove bus record\n4.Modify bus record\n5.View Buses\n6.View Users Booking for Particular Bus\n7.Logout";		
						cout<<"\nEnter your choice: ";
						cin>>ch;
						switch(ch)
						{
							case 1:
								b1.getData();
								file.open("BusDets.txt",ios::out|ios::app|ios::binary);
								file.write((char *)&b1,sizeof(Buses));
								file.close();
							break;
						
							case 2:
								cout<<"\nEnter the Bus number you want to search for:";
								cin>>serID;
								file.open("BusDets.txt",ios::in);
								while((file.read((char *)&b2,sizeof(Buses)))!=NULL)
								{
									if(serID==b2.no)
									{
										isfound=1;
										break;
									}
									else
									{
										isfound=0;
									}
								}
								if(isfound==1)
								{
									cout<<"\nBus FOUND==>";
									b2.displayData();
								}
								else
								{
									cout<<"\nBus NOT FOUND!!";
								}
								file.close();
							break;
						
							case 3:
								cout<<"\nEnter Bus Number to delete:";
								cin>>delID;
								file.open("BusDets.txt",ios::in|ios::binary);
								if(file.eof())
								{
									cout<<"File is empty";	
								}
								else
								{
									Buses e;
									ofstream fout("bustmp.txt");
									while(file.read((char*)&e,sizeof(Buses)))
									{
										if(e.no!=delID)
										{
											fout.write((char*)&e,sizeof(Buses));
										}
									}
									fout.close();
									file.close();
									remove("BusDets.txt");
									rename("bustmp.txt","BusDets.txt");
									cout<<"\nRecord has been deleted successfully!"<<endl;
								}
								file.close();
							break;
					
							case 4:
								cout<<"\nEnter Bus Number you want to UPDATE:";
								cin>>upID;
								file.open("BusDets.txt",ios::in|ios::binary);
								if(file.eof())
									cout<<"\nFile is empty";
								else
								{
									Buses e;
									ofstream fout("bustmp.txt");
									while(file.read((char*)&e,sizeof(Buses)))
									{
										if(e.no==upID)
										{
											cout<<"\nEnter new details:";
											e.getData();
											flag=1;
										}
										fout.write((char*)&e, sizeof(Buses));
									}
									fout.close();
									file.close();
									remove("BusDets.txt");
									rename("bustmp.txt","BusDets.txt");
									if(flag)
										cout<<"\nRecord is Updated Successfully!"<<endl;
									else
										cout<<"\nRecord Not Found.."<<endl;
								}
							break;
					
							case 5:
								file.open("BusDets.txt",ios::in|ios::binary);
								if(file.eof())
									cout<<"\nFile is empty";
								else
								{
									cout<<"\n========= Bus Details ===========";
									while((file.read((char *)&b2,sizeof(Buses)))!=NULL)
									{
										b2.displayData();
									}
								}
								file.close();
							break;
							
							case 6:
								bookingFile.open("userBookings.txt",ios::in|ios::binary);
								if(bookingFile.eof())
								{
									cout<<"\nThere are no bookings for any Bus";
								}
								else
								{
									cout<<"\nEnter the bus number you want to see the bookings for:";
									cin>>bn;
									cout<<"\n=======BOOKINGS FOR BUS ARE=======";
									cout<<"\n=========BUS NO.:"<<bn<<"=========";
									while((bookingFile.read((char*)&buf,sizeof(BookingIntoFile)))!=NULL)
									{
										if(buf.getBusNo()==bn)
										{
											buf.displayBooking();	
										}
									}	
								}
								bookingFile.close();
							break;
							
							case 7:
								goto exit;
							break;
					
							default:
								cout<<"\nPlease enter correct choice!";
							break;
						}
						cout<<"\nDo you want to continue with ADMIN Main Menu?[1 for YES || 0 for NO]-->";
						cin>>doch;
					}while(doch==1);
				}
				else
				{
					cout<<"\nInvalid Credentials!";
					goto exit;
				}
			break;
			
			case 2:
				cout<<"\n======== Welcome user =========";
				do
				{
					cout<<"\n1.Registration\n2.Login";
					cout<<"\nEnter:";
					cin>>chu;
					switch(chu)
					{
						case 1:
							u1.getData();
							file2.open("users.txt",ios::out|ios::app|ios::binary);
							file2.write((char *)&u1,sizeof(UserDB));
							file2.close();
						break;
				
						case 2:
							cout<<"\n==============LOGIN=============";
							cout<<"\nEnter the username:";
							cin>>u;
							cout<<"\nEnter the password:";
							cin>>p;
							file2.open("users.txt",ios::in|ios::binary);
							while(!file2.eof())
							{
								file2.read((char *)&u2,sizeof(UserDB));
								if(u==u2.getU() && p==u2.getP())
								{
									isfoundu=1;
									break;
								}
								else
								{
									isfoundu=0;
								}
							}
							if(isfoundu==1)
							{
								cout<<"\nLOGIN SUCCESSFUL!!";
								u2.displayData();
								do
								{
									cout<<"\n1.View bus timetable\n2.Search bus from source to destination";
									cout<<"\n3.Seat reservation/cancelling portal\n4.Logout";
									cout<<"\nEnter your choice: ";
									cin>>ch;
									switch(ch)
									{
										case 1:
											file.open("BusDets.txt",ios::in|ios::binary);
											if(file.eof())
												cout<<"\nFile is empty";
											else	
											{
												cout<<"\n========= Bus details ===========";
												while((file.read((char *)&b2,sizeof(Buses)))!=NULL)
												{
													b2.displayData();
												}
												cout<<"\n==================================";
											}
											file.close();
										break;
								
										case 2:
											cout<<"\nEnter the Bus source:";
											cin>>sr;
											cout<<"\nEnter the Bus destination:";
											cin>>de;
											file.open("BusDets.txt",ios::in);
											while((file.read((char *)&b2,sizeof(Buses)))!=NULL)
											{
												if(sr==b2.src && de==b2.dest)
												{
													isfound=1;
													break;
												}
												else
												{
													isfound=0;
												}
											}
											if(isfound==1)
											{
												cout<<"\nBus FOUND==>";
												b2.displayData();
											}
											else
											{
												cout<<"\nNo bus is available from "<<sr<<" to "<<de<<" !";
											}
											file.close();
										break;
										
										case 3:
											cout<<"\nWelcome to seat reservation system";
											cout<<"\nEnter the Bus source:";
											cin>>sr;
											cout<<"\nEnter the Bus destination:";
											cin>>de;
											file.open("BusDets.txt",ios::in);
											while((file.read((char *)&b2,sizeof(Buses)))!=NULL)
											{
												if(sr==b2.src && de==b2.dest)
												{
													isfound=1;
													break;
												}
												else
												{
													isfound=0;
												}
											}
											if(isfound==1)
											{
												t.create();
												do
												{
													cout<<"\nWelcome to seat reservation system.. ";
													cout<<"\nFrom: "<<sr;
													cout<<"\nTo: "<<de;
													cout<<"\n=============================";
													cout<<"\n1.Display all seats status\n2.Display vacant seats\n3.Book a seat\n4.Cancel a seat\nEnter your choice: ";
													cin>>chx;
													switch(chx)
													{
											    		case 1:
											        		t.display();
											    		break;
											    		
														case 2:
											        		t.display_vacant();
											    		break;
											    
														case 3:
											        		t.book(p,u2,b2);
											    		break;
											    
														case 4:
											       			t.cancel(p);
											    		break;
											    		
											    		default:
											    			cout<<"\nPlease enter correct choice!";
											    		break;
													}
													cout<<"\nDo you want to continue with the Portal?[Press 1 for YES | 0 for No]: ";
													cin>>chx;
												}while(chx==1);
											}
											else
											{
												cout<<"\nNo bus is available from "<<sr<<" to "<<de<<" !";
											}
											file.close();
										break;
										
										case 4:
											goto exit;
										break;
										
										default:
											cout<<"\nPlease enter correct choice!";
										break;
									}
									cout<<"\nDo you want to continue with the User Main Menu?[Press 1 for YES | 0 for No]: ";
									cin>>ch;
								}while(ch==1);
							}
							else
							{
								cout<<"\nINVALID CREDENTIALS!!";
							}
							file2.close();
						break;
					}
					cout<<"\nDo you want to continue with USER REGISTRATION/LOGIN?[Press 1 for YES || 0 for NO]-->";
					cin>>dochu;
				}while(dochu==1);
			
			break;
			
			case 3:
				goto exit;
			break;
			
			default:
				cout<<"\nPlease enter correct choice!";
			break;
		}
		cout<<"\nDo yo want to continue with ADMIN/USER?[Press 1 for YES | 0 for NO]-->";
		cin>>mainch;
	}while(mainch==1);
	
	exit:
	cout<<"\n======THANK YOU!======";
	return 0;
}
