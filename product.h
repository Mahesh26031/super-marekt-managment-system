#include<iostream>
#include<string>
using namespace std; 
class product{
	double price;
	double discount;
	string expiry;
	public:
		string name;
		void show(){
			cout<<"\n Name of product: "<<name;
			cout<<"\n Price of product: "<<price;
			cout<<"\n Today's Discount: "<<discount;
			cout<<"\n Expiry of product: "<<expiry;
		}
		product(){
			cout<<"\n Name of product: ";cin>>name;
			cout<<"\n Price of product: ";cin>>price;
			cout<<"\n Today's Discount: ";cin>>discount;
			cout<<"\n Expiry of product(DD/MM/YYYY): ";cin>>expiry;
			cout<<"\n--->Product Added!!";
		}
		void update(){
			cout<<"\n 1.Price ";
			cout<<"\n 2.Discount ";
			cout<<"\nSelect the quantity you want to change: ";
			int choice;
			cin>>choice;
			switch(choice){
				case 1:cout<<"\nEnter new price: ";cin>>price;break;
				case 2:cout<<"\nEnter new discount: ";cin>>discount;break;
				default:cout<<"\nInvaild entry\n--->Update Failed!";break;
							}
			cout<<"\n--->Product Updated!!";
		}
		double getprice(){
			return price;
		}
		double getdiscount(){
			return discount;
		}
};

