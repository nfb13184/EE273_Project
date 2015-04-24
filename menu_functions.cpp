#include"menu_functions.h"


ifstream infile;

//marker is what the details is seperated by in the file
//if the detail is to be seperated by a different symbol, simply just change the valuse of the variable "marker"
string marker = ",";

int make_a_new_list()
{
	string original__list_file_location;
	
	system("cls");
	//clear  the console and go to new screen
	

	////first need to get a file from the user that contains the variables
	//get the location of the original file
	cout << "enter the location of where the file contaning food details is stored:\n";
	cin >> original__list_file_location;
	
	
	//make a new file that will contain the copied list and will  be altered if needed
	ofstream newlist_file,original_list_file;
	//.open makes the new file that is placed int the same directory as the program
	newlist_file.open("updated_food_list.csv");
	//make a file that will store the original food list that will never be altered
	original_list_file.open("original_food_list.csv");
	
	
	//now open the file containing the original details
	infile.open(original__list_file_location);
	
	//struct instance "holder" will keep the value of the food details from each line before it is written to the new file
	food holder;
	//variable line will hold one line at a time as the iterator goes through the original file
	string line;
	if (!infile)
	{
		//if the user inputs a wrong file location, they will be asked if they want to try again or exit to menu
		string yn;
		cout << "file cannot be located, make sure the file location is correct\n";
		cout << "\n\npress Y to try again, press N to go back to menu: \n";
		cin >> yn;
		//if the person inputs anything except "y" and "n"
		while (yn!="y"& yn!="n"){
			cout << "please choose a suitable options (Y to try again, N to return to menu):\n";
			cin >> yn;
		}

		if (yn == "y")
		{
			make_a_new_list();
		}
		if (yn == "n"){
			return 0;
		}
		
		
		return 0;
	}

	
	//until the end of file is reached, do this while loop
	while (!infile.eof())
	{
		
		getline(infile, line);

		
		if (line.empty())
		{
			continue;
		}

		holder = splitting_details_from_line(line);
		
		    
			//the following line startting with "myfile" and "original_list_file" writes to the new files and places the list into there to be edited later
		newlist_file << holder.food_name << marker << holder.quantity << marker << holder.cost << marker << holder.expiry_date << marker << holder.barcode << marker << endl;
		original_list_file << holder.food_name << marker << holder.quantity << marker << holder.cost << marker << holder.expiry_date << marker << holder.barcode << marker << endl;

		
	}
	//close all files
	original_list_file.close();
	infile.close();
	newlist_file.close();

	cout << "             New List Made      \n";
	system("pause");
	return 0;
}

void display_list_menu()
{
	//clear the console
	system("cls");

	//new menu for displaying lists
	cout << "1. Display original list.\n";
	cout << "2. Display updated list.\n";
	cout << "3. Back.\n";
	cout << "   Please choose a suitable option:\n";
	int option2;
	cin >> option2;
	while (cin.fail())
	{
		cout << "Invalid character.\n Please choose a valid option: \n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> option2;
	}
	
	

	switch (option2){


	case 1:
		//display the original food list
		displaying_from_file("original_food_list.csv");
		break;

	case 2:
		//display the updated(altered) food list
		displaying_from_file("updated_food_list.csv");
		break;

	case 3:
		break;

	default: cout << "Invalid option. please choose a valid option from the menu provided\n";
		system("pause");
		break;
	}

	if (option2 == 3){
		exit;
	}

	if (option2 !=3){
		display_list_menu();
	}

	
}

void displaying_from_file(string file_name){
	food holder;
	string line;
	system("cls");
	infile.open(file_name);

	//struct instance "holder" will keep the value of the food details from each line before it is written to the new file

	//variable "line" will hold one line at a time as the iterator goes through the original file

	if (!infile)
	{
		cout << "file cannot be located, make sure the file location is correct\n";
		system("pause");
		display_list_menu();
		
	}

	cout << "\n\n\n";
	cout << setw(46) << "FOOD LIST\n\n\n";
	cout << "----------------------------------------------------------------------------\n";
	cout << setw(15) << "Food Name" << setw(15) << "Quantity" << setw(15) << "Cost" << setw(15) << "Expiry Date" << setw(15) << "Barcode\n";
	cout << "----------------------------------------------------------------------------\n";

	//until the end of file is reached, do this while loop
	while(!infile.eof())
	{
		
		getline(infile, line);

		if (line.empty())
		{
			continue;
		}

		holder = splitting_details_from_line(line);
		
		//print the details of each item on to the console
		cout << setw(15) << holder.food_name << setw(12) << holder.quantity << setw(15) << "\x9c"<< holder.cost
			<< setw(15) << holder.expiry_date << setw(15) << holder.barcode << endl;
		
		
	}
	cout << "----------------------------------------------------------------------------\n";
	system("pause");
	infile.close();
}

void search_menu(){

	system("cls");
	int option3= NULL;
	cout << "1. Search by name.\n";
	cout << "2. Search by barcode\n";
	cout << "3. Back.\n";
	cout << "   Please choose an option from the menu:\n";
	cin >> option3;
	while (cin.fail())
	{
		cout << "Invalid character.\n Please choose a valid option: \n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> option3;
	}
	
	string line;
	char name[100];
	char comp =NULL ;
	string name_holder;
	int i;
	int size;
	string bc;
	food holder;
	int hit;
	switch (option3){
	case 1:
		//if the person want to search by name
		system("cls");
		//get the name the user wnats to search
		cout << "Enter food name: \n";
		cin >> name;
		//to get the size
		size = 0;
		for (i = 0; i < 101; i++){
			if (comp == name[i]){ }
		}

		//open the file that contains the food list
		infile.open("updated_food_list.csv");


		if (!infile)
		{
			cout << "file cannot be located, make sure the file location is correct\n";
			system("pause");
			search_menu();

		}


		//until the end of file is reached, do this while loop
		while (!infile.eof())
		{


			getline(infile, line);

			if (line.empty())
			{
				continue;
			}

			holder = splitting_details_from_line(line);
			//compare each food item with the name to be searched for
			if (name == holder.food_name){
				//if found the variable hit will be set to 1
				hit = 1;
				cout << "Match found: \n";
				cout << "            name: " << holder.food_name << endl;
				cout << "            quantity: " << holder.quantity << endl;
				cout << "            cost: \x9c " << holder.cost << endl;
				cout << "            expiry date: " << holder.expiry_date << endl;
				cout << "            barcode: " << holder.barcode << endl;
				system("pause");
				break;
			}
			//if the food not found the variable hit will be set to 0
			else{ hit = 0; }
			
		}
		//if food not found a message will be displayed
		if (hit == 0){
			cout << "No matches found, make sure the value is correct and try again\n";
			system("pause");
			break;
		}
		infile.close();
		break;

	case 2:
		//if the person wants to search by barcode
		system("cls");
		//get barcode from user
		cout << "Enter barcode: \n";
		cin >> bc;
		//open file to be compared
		infile.open("updated_food_list.csv");


		if (!infile)
		{
			cout << "file cannot be located, make sure the file location is correct\n";
			system("pause");
			search_menu();

		}


		//until the end of file is reached, do this while loop
		while (!infile.eof())
		{


			getline(infile, line);

			if (line.empty())
			{
				continue;
			}
			hit = 0;
			holder = splitting_details_from_line(line);
			//compare each food item with the barcode
			if (bc == holder.barcode){
				//if food item found the variable hit will be set to 1
				hit = 1;
				cout << "Match found: \n";
				cout << "            name: " << holder.food_name << endl;
				cout << "            quantity: " << holder.quantity << endl;
				cout << "            cost: \x9c " << holder.cost << endl;
				cout << "            expiry date: " << holder.expiry_date << endl;
				cout << "            barcode: " << holder.barcode << endl;
				system("pause");
				break;
			}
			//if food item not found the variable hit will be set to 0
			//else if (bc != holder.barcode){ hit = 0; };
		}
		//message output to screen if the food item is not found
		if (hit == 0){
			cout << "No matches found, make sure the value is correct and try again\n";
			system("pause");
			break;
		}
		infile.close();
		break;

	case 3:
		break;

	default:cout << "\n\n Invalid option, please choose an appropriate option from the menu\n\n";
		system("pause");
		search_menu();
		break;
	}
	if (option3 == 3){
		exit;
	}
	else{
		search_menu();
	}
}

food splitting_details_from_line(string line)
{	//this function is called when ever a file is read from
	food holder;
		//the following for loop goes through the each line from  file 5 times since there are 5 pieces of information in the line
		//if more information is added this loop counter will need to be increased
		int counter;
		int poss;
		string name;
		int size;
		int i;
		for (counter = 0; counter < 5; counter++){


			if (counter == 0)
			{
				poss = line.find(marker);
				name = line.substr(0, poss);
				size = name.size();
				for (i = 0; i < size; i++){
					holder.food_name[i] = line.substr(0, poss)[i];
				}
				for (i = size; i < 100; i++){
					holder.food_name[i] = NULL;
				}
				line = line.substr(poss + 1, line.length());

			}
			if (counter == 1)
			{
				poss = line.find(marker);
				holder.quantity = stoi(line.substr(0, poss));
				line = line.substr(poss + 1, line.length());
			}
			if (counter == 2)
			{
				poss = line.find(marker);
				holder.cost = stof(line.substr(0, poss));
				line = line.substr(poss + 1, line.length());
			}

			if (counter == 3)
			{
				poss = line.find(marker);
				holder.expiry_date = line.substr(0, poss);
				line = line.substr(poss + 1, line.length());
			}
			if (counter == 4)
			{
				poss = line.find(marker);
				holder.barcode = line.substr(0, poss);

			}

		}

		return holder;
}

//contains the menu for editing
void edit_list(){
	/////////////////////////////////////////////////////BEFORE EDITING//////////////////////
	///have to get the number of lines in the file so a vector of theat size can be made to store the food items
	string line;
	int number_of_lines;

	//open the file that contains the food list
	infile.open("updated_food_list.csv");


	if (!infile)
	{
		cout << "file cannot be located, make sure the file location is correct\n";
		system("pause");
		search_menu();

	}
	//set the number of lines to zero to start off with
	number_of_lines = 0;
	//until the end of file is reached, do this while loop
	while (!infile.eof())
	{


		getline(infile, line);

		if (line.empty())
		{
			continue;
		}

		//increase the number for everyline read in
		number_of_lines++;
	}
	//close the file after counting the number of lines
	infile.close();

	//create a dynamic vector, have to use pointer to make it dynamic memory
	food* vc = new food[number_of_lines];
	//////putting food info from each line into vectors
	infile.open("updated_food_list.csv");

	if (!infile)
	{
		cout << "file cannot be located, make sure the file location is correct\n";
		system("pause");
		search_menu();

	}
	//counter counts the up to the number of lines
	int counter = 0;

	//until the end of file is reached, do this while loop
	while (!infile.eof())
	{
		//holder is where each line info will be  heald beofre put into the vector
		food holder;

		getline(infile, line);

		if (line.empty())
		{
			continue;
		}

		while (counter < number_of_lines){
			//each line is split into the food item details and put into the vector
			holder = splitting_details_from_line(line);
			vc[counter] = holder;
			counter++;
			break;
		}
	}
	infile.close();
	//////////////////////////////////////////////////////////BEFORE EDITING DONE////////////
	//clear the console
	system("cls");

	//new menu for displaying lists
	system("cls");
	cout << "1. Delete food item\n";
	cout << "2. Edit entry\n";
	cout << "3. Back\n";
	cout << "   Please choose a suitable option:\n";
	int option3;
	cin >> option3;
	while (cin.fail())
	{
		cout << "Invalid character.\n Please choose a valid option: \n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> option3;
	}




	switch (option3){


	case 1:
		delete_food(vc,number_of_lines);
		break;

	case 2:
		edit_item(vc, number_of_lines);
		break;

	case 3:
		break;

	default: cout << "Invalid option. please choose a valid option from the menu provided\n";
		system("pause");
		break;
	}

	if (option3 == 3){
		exit;
	}

	if (option3 != 3){
		edit_list();
	}
}

void delete_food(food *vector,int number_of_lines){
	system("cls");
	string delete_barcode;
	//found variable is set to 1 if the item is found, and 0 otherwise
	int found;
	found = 0;
	cout << "Which item do you want to delete? (Enter barcode):\n";
	cin >> delete_barcode;


	ofstream override;
	override.open("updated_food_list.csv");
	int counter;
	for (counter = 0; counter < number_of_lines; counter++)
	{
		if (vector[counter].barcode == delete_barcode)
		{
			found = 1;
			continue;
		}

		else
		{
			override << vector[counter].food_name << marker << vector[counter].quantity << marker << vector[counter].cost << marker << vector[counter].expiry_date << marker << vector[counter].barcode << marker << endl;
		}

	}
	override.close();
	if (found == 1){
		cout << "\n\n Item Deleted\n";
		system("pause");
	}
	else if (found == 0){ cout << "Item not found, make sure the barcode entered is correct and try again\n"; system("pause"); }
}
