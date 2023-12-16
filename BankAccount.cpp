/*
 *	======================================
 * 		Program Name: BankAccount.cpp
 *  	Created on: November 25, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */

#include<iostream>
#include<string.h>
using namespace std;

class BankAccPrg
{
	int accNo;
	char accHolderName[100];
	double wdAmt,accBal;
	
	public:
		BankAccPrg(int acc_No, char *name, float balance)//constructor for initialising values.
		{
			accNo=acc_No;
			strcpy(accHolderName, name);
			accBal=balance;
		}
		void deposit();
		void withdraw();
		void display();
};

void BankAccPrg::deposit()
{
	int depAmt;
	cout<<"\nEnter the amount to be deposited:";
	cin>>depAmt;
	accBal=accBal+depAmt;
	cout<<"\nAccount balance after deposit: Rs."<<accBal;
}

void BankAccPrg::withdraw()
{
	int witAmt;
	cout<<"\nEnter the amount to be withdrawed:";
	cin>>witAmt;
	if(witAmt>accBal)
	{
		cout<<"\nInsufficient amount! Withdraw operation failed!";
	}
	else
	{
		accBal=accBal-witAmt;
		cout<<"\nAccount balance after withdraw: Rs."<<accBal;	
	}
	
}

void BankAccPrg::display()
{
	cout<<"=========================================";
	cout<<"\n===========ACCOUNT DETAILS===============";
	cout<<"\nAccount Information:";
	cout<<"\nAccount Holder Name:"<<accHolderName;
	cout<<"\nAccount Balance: Rs."<<accBal;
	cout<<"\n=========================================";
}

int main()
{
	int acno;
	int ch,ch1;
	char name[100];
	double bal;
	cout<<"\n================Welcome===================";
	cout<<"\nEnter the bank account details:\n";
	cout<<"\nBank account holder name:";
	cin>>name;
	cout<<"\nEnter the account number:";
	cin>>acno;
	cout<<"\nEnter the account balance:";
	cin>>bal;
	BankAccPrg b(acno,name,bal); //object created
	cout<<"\n===================";
	do
	{
		cout<<"\n1.Deposit an Amount.\n2.Withdraw an Amount\n3.See your account details.\n -->>Enter your correct choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				b.deposit();
			break;
			
			case 2: 
				b.withdraw();
			break;
			
			case 3:
				b.display();
			break;	
		
		}
		cout<<"\nDo you want to continue?[Press 1 for Yes || Press 0 for No]";
		cin>>ch1;
	}while(ch1!=0);

	cout<<"\n=====================Thank You!=================================";
	return 0;	
}
