#include "food.h"
//implementation of the functions from the hpp

//constructor
food::food(string n,int q,float c)
{
	this->name=n;
	this->quantity=q;
	this->cost=c;
}

//setters and getters
void food::set_name(string n)
{
	
	this->name=n;
}

string food::get_name()
{
	return this->name;
}

void food::set_quantity(int q)
{
	
	this->quantity=q;
}

int food::get_quantity()
{
	return this->quantity;
}

void food::set_cost(float c)
{
	
	this->cost=c;
}

float food::get_cost()
{
	return this->cost;
}
