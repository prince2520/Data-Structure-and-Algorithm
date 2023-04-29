#include <iostream>
#include <cstring>
using namespace std;

class Car{
private:
	float price;
public:
	int model_no;
	char name[20];

	Car(){
		cout << "Inside Car constructor" << endl;
	}

	Car(float p, int m, char *n){
		price = p;
		model_no = m;
		strcpy(name, n);
	}

	Car(float p){
		price = p;
	}

	Car(Car &x){
		cout << "Copy constructor " << endl;

		price = x.price;
		model_no = x.model_no;
		strcpy(name, x.name);
	}

	void print(){
		cout << endl;
		cout << "Name " << name << endl;
		cout << "Model no" << model_no << endl;
		cout << "Price " << price << endl;
	}

	float get_discounted_price(float x){
		return price*(1-x);
	}

	float apply_discount(float x){
		price = price * (1.0 - x);
		return price;
	}

	void set_price(float p){
		price = 110;
		if(p > 0){
			price = p;
		}
	}

	float get_price(){
		return price;
	}

};

int main(){

	Car c;
	Car d(222, 333, "Audi");

	cout << "Car D " << endl;
	d.print();

	Car e(d);
	e.set_price(456);
	cout << "Car E";
	e.print();

	c.model_no = 112;
	c.name[0] = 'B';
	c.name[1] = 'M';
	c.name[2] = 'W';
	c.name[3] = '\0';

	c.set_price(-110);

	d.print();


	c.print();



	return 0;
}