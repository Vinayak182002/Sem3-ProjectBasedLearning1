/*
 *	======================================
 * 		Program Name: ComplexNumbers.cpp
 *  	Created on: December 02, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */
 
#include <iostream>
using namespace std;

class ComplexNumbers
{
    int real,img;
    public:
        ComplexNumbers()
        {
            this->real=0;
            this->img=0;
        }
        //overloading insertion operator    
       friend istream &operator>>( istream  &input,ComplexNumbers &obj1)
       {
         input >> obj1.real >> obj1.img;
         return input;            
       }
        //overloading ectraction operator
       friend ostream &operator<<( ostream  &output,ComplexNumbers &obj1)
       {
         output<<obj1.real<<" + i"<<obj1.img;
         return output;            
       }
       //overloading addition + operator
       ComplexNumbers operator+(ComplexNumbers &obj)
       {
           ComplexNumbers cn;
           cn.real=this->real+obj.real;
           cn.img=this->img+obj.img;
           return cn;
       }
       //overloading multiplication * operator
       ComplexNumbers operator*(ComplexNumbers &obj)
       {
           ComplexNumbers cn;
           cn.real=this->real*obj.real;
           cn.img=this->img*obj.img;
           return cn;
       }
};

int main()
{
    ComplexNumbers c1,c2,c3,addresult,mulresult;
    cout<<"\n======Welcome===========";
    cout<<"\nThe Complex Numbers are-->";
    //default values are set using Constructor
    cout<<"\nFirst Number= "<<c1;
    cout<<"\nSecond Number= "<<c2;
    cout<<"\n======================================";
    cout<<"\nEnter the values for first complex number-->";
    cout<<"\nEnter real value and imaginary value:";
    cin>>c1;
    cout<<"\nThe values for first complex number are assigned by overloading insertion operator!";
    cout<<"\nSecond Number==>The Complex number is: "<<c1;
    cout<<"\n======================================";
    cout<<"\nEnter the values for second complex number-->";
    cout<<"\nEnter real value and imaginary value:";
    cin>>c2;
    cout<<"\nThe values for second complex number are assigned by overloading insertion operator!";
   //displaying values by overloading extraction operator
    cout<<"\nSecond Number==>The Complex number is: "<<c2;
    cout<<"\n======================================";
    cout<<"\n=====ADDITION OPERATION=====";
    cout<<"\nFirst Number= "<<c1;
    cout<<"\nSecond Number= "<<c2;
    addresult=c1+c2;
    cout<<"\nAddition of first and second Complex Number is= "<<addresult;
    cout<<"\n======================================";
    cout<<"\n======================================";
    cout<<"\n=====MULTIPLIATION OPERATION=====";
    cout<<"\nFirst Number= "<<c1;
    cout<<"\nSecond Number= "<<c2;
    mulresult=c1*c2;
    cout<<"\nMultiplication of first and second Complex Number is= "<<mulresult;
    cout<<"\n======================================";
    cout<<"\n======Thank You!===========";
    return 0;
}
