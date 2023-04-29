#include <iostream>
#include "hashing.h"
using namespace std;

int main(){

	hastable<int> price_menu;

	price_menu.insert("Burger", 120);
	price_menu.insert("Pepsi", 20);
	price_menu.insert("BurgerPizza", 150);
	price_menu.insert("Noodles", 25);
	price_menu.insert("Coke", 40);

	price_menu.print();


	int *price =  price_menu.search("BurgerPizza");

	if(price == NULL){
		cout << "Not Found! " << endl; 
	}else{
		cout << "Price " << *price << endl;
	}

	price_menu["Dosa"] = 60;

	price_menu["Dosa"] += 70;

	cout << "Price Dosa" << price_menu["Dosa"] << endl;



	return 0;
}