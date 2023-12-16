/*
 *	======================================
 * 		Program Name: CarInheritance.cpp
 *  	Created on: November 29, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */
/*
	How the inheritance in program will work??
	==>>
	===============================================================================
								Class Vehicle
									 ||
									 ||
					==================================
					||								||
					||								||
				class Cars						class Bike
					||								||
					||								||
			==================				==================
			||				||				||				||
			||				||				||				||
		class Audi		class Ford		class Bajaj		class TVS
	
	===============================================================================
*/
 #include<iostream>
 #include<string.h>
 using namespace std;
 
 class Vehicle
 {
 	int mileage;
 	double price;
 	
 	public:
 		void setmileage()
 		{
 			cout<<"\nEnter the mileage for the car:";
 			cin>>mileage;
		}
		int getmileage()
		{
			return mileage;
		}
		void setprice()
		{
			cout<<"\nEnter the price for the car:";
			cin>>price;
		}
		double getprice()
		{
			return price;
		}
 };
 
 class Car:public Vehicle
 {
 	double ownership_cost;
 	int warranty,seat_capacity;
 	string fuel_type;
 	public:
 		void setownership_cost()
 		{
 			cout<<"\nEnter the ownership cost for the car:";
			cin>>ownership_cost;	
		}
		double getownership_cost()
		{
			return ownership_cost;
		}
		void setwarranty()
		{
			cout<<"\nEnter the warranty for the car in years:";
			cin>>warranty;
		}
		int getwarranty()
		{
			return warranty;
		}
		void setseat_capacity()
		{
			cout<<"\nEnter the capacity of seats for the car:";
			cin>>seat_capacity;
		}
		int getseat_capacity()
		{
			return seat_capacity;
		}
		void setfuel_type()
		{
			cout<<"\nEnter the fuel type for the car[Petrol/Diesel]:";
			cin>>fuel_type;
		}
		string getfuel_type()
		{
			return fuel_type;
		}
 };
 

 class Bike:public Vehicle
 {
 	int no_cylinders,no_gears,fuel_tank_size;
 	string cooling_type,wheel_type;
 };
 
 class Audi:public Car
 {
 	string audi_model_type;
 	public:
 		void addSpecifications()
 		{
 			cout<<"\n================= Add Specifications for Car AUDI=======================";
 			cout<<"\nEnter the model type for the car:";
 			cin>>audi_model_type;
 			setmileage();
 			setprice();
 			setownership_cost();
 			setwarranty();
 			setseat_capacity();
 			setfuel_type();
		}
		
		void displaySpecifications()
		{
			cout<<"\n=================Specifications for Car AUDI=======================";
			cout<<"\n\tModel Type: "<<audi_model_type;
			cout<<"\n\tMileage: "<<getmileage();
			cout<<"\n\tPrice: "<<getprice();
			cout<<"\n\tOwnership Cost: "<<getownership_cost();
			cout<<"\n\tSeat Capacity: "<<getseat_capacity();
			cout<<"\n\tFuel Type: "<<getfuel_type();
			cout<<"\n=====================================================================";
		}
 };
 
 class Ford:public Car
 {
 	string ford_model_type;
 	public:
 		void addSpecifications()
 		{
 			cout<<"\n================= Add Specifications for Car FORD=======================";
 			cout<<"\nEnter the model type for the car:";
 			cin>>ford_model_type;
 			setmileage();
 			setprice();
 			setownership_cost();
 			setwarranty();
 			setseat_capacity();
 			setfuel_type();
		}
		
		void displaySpecifications()
		{
			cout<<"\n=================Specifications for Car FORD=======================";
			cout<<"\n\tModel Type: "<<ford_model_type;
			cout<<"\n\tMileage: "<<getmileage()<<"kms/l";
			cout<<"\n\tPrice: $"<<getprice();
			cout<<"\n\tOwnership Cost: "<<getownership_cost();
			cout<<"\n\tWarrant: "<<getwarranty()<<"years";
			cout<<"\n\tSeat Capacity: "<<getseat_capacity();
			cout<<"\n\tFuel Type: "<<getfuel_type();
			cout<<"\n=====================================================================";
		}
 };
 
 class Bajaj:public Bike
 {
 	string bajaj_make_type;
 };
 
 class TVS:public Bike
 {
	string tvs_make_type; 	
 };
 
 int main()
 {
 	Audi audi;
 	Ford ford;
 	
 	string model_t;
 	int ch,ch1,doch,doch1,doch2;
 	
 	cout<<"=================Welcome======================\n";
 	cout<<"\n=============Vehicles===================";
 	cout<<"\n======Cars======";
 	do
 	{
 		cout<<"\n1.Audi\n2.Ford";
 		cout<<"\nSelete the car you want by entering the proper choice:";
 		cin>>ch;
 		switch(ch)
 		{
 			case 1:
 				do
 				{
 					cout<<"\n===============CAR-->>AUDI===================";
 					cout<<"\n1.Add Specifications\n2.View Specifications.";
 					cout<<"\nEnter your proper choice:";
 					cin>>ch1;
 					switch(ch1)
 					{
 						case 1:
 							audi.addSpecifications();
 							break;
 						
 						case 2:
 							audi.displaySpecifications();
 							break;
 						
 						default:
 							cout<<"\nYou have entered wrong choice! Please Enter the proper choice!";
 							break;
					}
 					cout<<"\nDo you want to continue with AUDI? [1-YES || 0-NO]";
 					cin>>doch1;
				}while(doch1==1);
 				break;
 			
 			case 2:
 				do
 				{
 					cout<<"\n===============CAR-->>FORD===================";
 					cout<<"\n1.Add Specifications\n2.View Specifications.";
 					cout<<"\nEnter your proper choice:";
 					cin>>ch1;
 					switch(ch1)
 					{
 						case 1:
 							ford.addSpecifications();
 							break;
 						
 						case 2:
 							ford.displaySpecifications();
 							break;
 						
 						default:
 							cout<<"\nYou have entered wrong choice! Please Enter the proper choice!";
 							break;
					}
 					cout<<"\nDo you want to continue with FORD? [1-YES || 0-NO]";
 					cin>>doch2;
				}while(doch2==1);
 				break;
 			
 			default:
 				cout<<"\nYou have entered wrong choice! Please Enter the proper choice!";
		}
 		cout<<"\nDo you want to continue with Cars? [1-YES || )-NO]-->";
 		cin>>doch;
	}while(doch==1);
 }
