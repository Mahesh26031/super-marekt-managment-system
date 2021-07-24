#include<iostream>
#include<vector>
#include<conio.h>
#include "product.h"
vector<product> products;
vector<product> sales;
string pass="Super123\r";
void addProduct(){
	char pas[10];	
	int i=0;
	cout<<"\nEnter admin password: ";
    while((pas[i]=getch())!='\r')
    {
    cout<<"#";
    i++;
    }
    if(pas==pass){
	product p;
	products.push_back(p);}
	else cout<<"\nIncorrrect Password!!!";
}
void delProduct(){
	char pas[10];	
	int i=0;
	cout<<"\nEnter admin password: ";
    while((pas[i]=getch())!='\r')
    {
    cout<<"#";
    i++;
    }
    if(pas==pass){
	string x;
	cout<<"\nEnter the name of product you want stop selling: ";
	cin>>x;
	int f=0;
	for(int i=0;i<products.size();i++)
	{ 
   		if(x==products[i].name)
		{ swap(products[i], products.back());
    	products.pop_back();
    	cout<<"\n--->Product Deleted!!";
    	f=1;
    	break;}
	}
	if(f==0)
	cout<<"\n--->Product Not Found!!";
	}
	else cout<<"\nIncorrrect Password!!!";
}
void updateProduct(){
		char pas[10];	
	int i=0;
	cout<<"\nEnter admin password: ";
    while((pas[i]=getch())!='\r')
    {
    cout<<"#";
    i++;
    }
    if(pas==pass){
	string x;
	cout<<"\nEnter the name of product you want update: ";
	cin>>x;
	int f=0;
	for(int i=0;i<products.size();i++)
	{if(x==products[i].name)
		{ f=1;
    	products[i].update();
    	break;}
		
	}
	if(f==0)
	cout<<"\n--->Product Not Found!!";
	}
	else cout<<"\nIncorrrect Password!!!";
	
	
}
void view(){
	cout<<"\n1.Show all products";
	cout<<"\n2.Show specific product";
	int choice;
	cin>>choice;
	switch(choice){
	case 1:
	{
	for(int i=0;i<products.size();i++)
	{
		products[i].show();
	}break;}
	case 2:{
		string x;
	cout<<"\nEnter the name of product you want to view: ";
	cin>>x;
	int f=0;
	for(int i=0;i<products.size();i++)
	{if(x==products[i].name)
		{ products[i].show();
		f=1;
    	break;}
		}
		if(f==0)
	cout<<"\n--->Product Not Found!!";
	
		break;
	}
	}
}
void makebill(){
	vector<product> cart;
	cout<<"\n1.Add item to cart";
	cout<<"\n2.Remove item from cart";
	cout<<"\n3.Discard cart";
	cout<<"\n4.Checkout";
	int choice=0;
	while(choice!=4){
	cout<<"\nEnter choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:{string x;
		cout<<"\nEnter the name of product you want add to cart: ";
		cin>>x;
		int f=0;
		for(int i=0;i<products.size();i++)
		{	if(x==products[i].name)
			{ 
    		cart.push_back(products[i]);
    		f=1;
    		cout<<"\n--->Product Added!!";
    		break;}
    		
	}if(f==0)
	cout<<"\n--->Product Not Found!!";
		
			break;
		}
		case 2:{
		string x;
		cout<<"\nEnter the name of product you want to remove from cart: ";
		cin>>x;
		int f=0;
		for(int i=0;i<cart.size();i++)
		{if(x==cart[i].name)
		{ swap(cart[i], cart.back());
    	cart.pop_back();
    	f=1;
    	cout<<"\n--->Product Removed!!";
    	break;}
		}
		if(f==0)
		cout<<"\n--->Product Not Found!!";
	
			break;
		}
		case 3:{
		cout<<"\nCart discarded!!";	
		choice=4;break;}
		case 4:{
			double bill=0;
			for(int i=0;i<cart.size();i++)
			{sales.push_back(cart[i]);
			bill+=cart[i].getprice()-cart[i].getdiscount();}
			cout<<"\nYour cart bill is: "<<bill;
			break;
		}
	}
	}
}
int main()
{cout<<"--------------------Welcome to Supermarket management System-------------------";
cout<<"\nHere is the list of things you can do";
cout<<"\n****ADMIN ACCESS****";
cout<<"\n1.Add a new product";
cout<<"\n2.Stop selling a product";
cout<<"\n3.Update a product";
cout<<"\n****NORMAL ACCESS****";
cout<<"\n4.View product details";
cout<<"\n5.Make a bill";
cout<<"\n6.View Sales";
cout<<"\n7.EXIT";
int choice=0;
while(choice!=7)
{
cout<<"\n\nEnter Your Choice: ";
cin>>choice;
switch(choice){
	case 1:{
	addProduct();
		break;
	}
	case 2:{
	delProduct();	
		break;
	}
	case 3:{
	updateProduct();	
		break;
	}
	case 4:{
	view();
	break;}
	case 5:{
		makebill();
		break;
	}
	case 6:{
		for(int i=0;i<sales.size();i++)
		{
			sales[i].show();
		}
		break;
	}
	
}
}
}
