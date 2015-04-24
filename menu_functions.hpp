#ifndef MENU_FUNCTIONS_CPP
#define MENU_FUNCTIONS_HPP

//calling libraries needed by the program
#include<iostream>
#include <string>
#include<fstream>
#include<iomanip>
#include <cctype>
using namespace std;

//structure "food" is an object that will store the listed variables before a file list is made
struct food{
	char food_name[100];
	int quantity;
	float cost;
	string expiry_date;
	string barcode;

};

//function for making a new list choice 1 in the main menu
int make_a_new_list();

void display_list_menu();
//displaying from file is the function called from "display_list_menu" functions; reusable code saved as a function
void displaying_from_file(string file_name);

//this function is used when ever a file is being read in 
//instead of typing the code 4-5 times to split lines read in from file each time a new file is open its put into a function and simply called in
food splitting_details_from_line(string line);

//the search function contains a mini menu to searche through the database of foods
void search_menu();

void edit_list();

void delete_food(food *vector, int number_of_lines);
void edit_item(food*vector, int number_of_lines);

#endif;
