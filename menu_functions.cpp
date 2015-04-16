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
	
	infile.open(file_name);

	//struct instance "holder" will keep the value of the food details from each line before it is written to the new file

	//variable "line" will hold one line at a time as the iterator goes through the original file

	if (!infile)
	{
		cout << "file cannot be located, make sure the file location is correct\n";
		system("pause");
		display_list_menu();
		
	}

	
	//until the end of file is reached, do this while loop
	while(!infile.eof())
	{
		

		getline(infile, line);

		if (line.empty())
		{
			continue;
		}

		holder = splitting_details_from_line(line);

		//clear the console before the next item is shown
		system("cls");
		//print the details of each item on to the console
		cout << "         name: " << holder.food_name << endl;
		cout << "         quantity: " << holder.quantity << endl;
		cout << "         cost: \x9c " << holder.cost << endl;
		cout << "         expiry date: " << holder.expiry_date << endl;
		cout << "         barcode: " << holder.barcode << endl;
		cout << "\n\n\n\n";
		system("pause");
		
	}
	cout << "\n\n\n         End of list     \n\n\n";
	system("pause");
	infile.close();
}

void search_menu(){

	system("cls");
	int option3;
	cout << "1. Search by name.\n";
	cout << "2. Search by barcode\n";
	cout << "3. Search by quantity.\n";
	cout << "4. Search by expiry date.\n";
	cout << "5. Back.\n";
	cout << "   Please choose an option from the menu:\n";
	cin >> option3;
	
	string line;
	string name;
	string bc;
	int quantity;
	string expiry_date;
	food holder;
	int hit;
	switch (option3){
	case 1:
		//if the person want to search by name
		system("cls");
		//get the name the user wnats to search
		cout << "Enter food name: \n";
		cin >> name;
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
			else{ hit = 0; }
		}
		//message output to screen if the food item is not found
		if (hit == 0){
			cout << "No matches found, make sure the value is correct and try again\n";
			system("pause");
		}
		infile.close();
		break;
		
	case 3:
		//if the person wants to search by quantity
		system("cls");
		//get the quantity from user
		cout << "Enter quantity: \n";
		cin >> quantity;
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

			holder = splitting_details_from_line(line);
			//compare each food item with the barcode
			if (quantity == holder.quantity){
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
			else{ hit = 0; }
		}
		//message output to screen if the food item is not found
		if (hit == 0){
			cout << "No matches found, make sure the value is correct and try again\n";
			system("pause");
		}
		infile.close();
		break;

	case 4:
		//if the person wants to search by quantity
		system("cls");
		//get the quantity from user
		cout << "Enter expiry date: \n";
		cin >> expiry_date;
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

			holder = splitting_details_from_line(line);
			//compare each food item with the barcode
			if (expiry_date == holder.expiry_date){
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
			else{ hit = 0; }
		}
		//message output to screen if the food item is not found
		if (hit == 0){
			cout << "No matches found, make sure the value is correct and try again\n";
			system("pause");
		}
		infile.close();
		break;

	case 5:
		break;

	default:cout << "\n\n Invalid option, please choose an appropriate option from the menu\n\n";
		system("pause");
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
		for (counter = 0; counter < 5; counter++){


			if (counter == 0)
			{
				poss = line.find(marker);
				holder.food_name = line.substr(0, poss);
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
				holder.cost = stoi(line.substr(0, poss));
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
void edit_list(){
	//clear the console
	system("cls");

	//new menu for displaying lists
	system("cls");
	cout << "1. Delete food item.\n";
	cout << "2. Edit entry.\n";
	cout << "3. back.\n";
	cout << "   Please choose a suitable option:\n";
	int option3;
	cin >> option3;




	switch (option3){


	case 1:
		
		break;

	case 2:
		
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

