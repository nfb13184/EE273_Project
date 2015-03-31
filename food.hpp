#ifndef FOOD_CPP
#define FOOD_H

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class food
{
private:
	string name;
	int quantity;
	float cost;

public:
	food(){};
	//constructor
	food(string n,int q, float c);
	//destructor
	virtual~food(){};
	//setters and getters- setters asks user for inputs
	void set_name(string n);
    string get_name();
	void set_quantity(int q);
	int get_quantity();
	void set_cost(float c);
	float get_cost();


};
#endif;
