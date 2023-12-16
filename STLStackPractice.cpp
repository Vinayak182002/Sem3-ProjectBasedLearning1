#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> s1,s2,ans;
	int n,tmp1,tmp2,flag=0;
	int carry=0;
	int add=0;
	cout<<"\nEnter the number of bits of binary number:";
	cin>>n;
	cout<<"\nEnter first number:";
	for(int i=0;i<n;i++)
	{
		cin>>tmp1;
		if(tmp1==0 || tmp1==1)
		{
			s1.push(tmp1);
		}
		else
		{
			cout<<"\nPlease enter 0 or 1";
			flag=1;
//			goto exit;
		}
	}
	cout<<"\nEnter second number:";
	for(int i=0;i<n;i++)
	{
		cin>>tmp2;
		if(tmp2==0 || tmp2==1)
		{
			s2.push(tmp2);
		}
		else
		{
			cout<<"\nPlease enter 0 or 1";
			flag=1;
//			goto exit;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		add=s1.top()+s2.top()+carry;
		if(add==0 || add==1)
		{
			carry=0;
			ans.push(add);
		}
		else if(add==2)
		{
			carry=1;
			ans.push(0);
		}
		else if(add==3)
		{
			carry=1;
			ans.push(1);
		}
		s1.pop();
		s2.pop();
	}
	
	if(carry==1)
	{
		ans.push(1);
		n+=1;
	}
	
	cout<<"\nResultant binary number after addition:";
	for(int i=0;i<n;i++)
	{
		cout<<ans.top()<<" ";
		ans.pop();
	}
//	exit:
		cout<<"\nProgram ended!";
	cout<<"\n==THANK YOU!==";
	return 0;
}
