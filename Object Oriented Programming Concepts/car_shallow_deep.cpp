#include <iostream>
#include <cstring>
using namespace std;

class Car{
private:
	float price;

public:
	int model_no;
	char *name;

	Car(){
		name = NULL;
	}
	Car(float p, int m, char *n){
		price = p;
		model_no = m;
		name = new char[strlen(n)+1];
		strcpy(name, n);	
	}
	Car(Car &X){
		price = X.price;
		model_no = X.model_no;
		name = new char[strlen(X.name)+1];
		strcpy(name, X.name);
	}

	void operator=(Car &X){
		price = X.price;
		model_no = X.model_no;
		name = new char[strlen(X.name)+1];
		strcpy(name, X.name);
	}

	void print(){
		cout << endl;
		cout << "Name " << name << endl;
		cout << "Model no" << model_no << endl;
		cout << "Price " << price << endl;
	}

	~Car(){
		if(name!=NULL){
			cout << "Destructor called " << name << endl; 
			delete [] name;
		}
	}
};

int main(){
	Car c(100, 200, "BMW");
	Car d;
	d = c;
	d.name[0] = 'A';

	Car *e = new Car(10,20,"Ferrari");

	e->print();

	delete e;


	c.print();
	d.print();


	return 0;
}