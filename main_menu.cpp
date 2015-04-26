#include "menu_functions.h"



int main()
{
	//setting the title on top of the console/window
	system("title Food Inventory Management");

	//setting colour of console
	system("color B2");

	//clear the console screen
	system("cls");

	/////outputing menu options
	cout << "1. Make a new list\n";
	cout << "2. Display list\n";
	cout << "3. Edit list\n";
	cout << "4. Search\n";
	cout << "5. Exit\n";
	cout << "\n Please choose an option:\n";
	int option;
	cin >> option;

	while (cin.fail())
	{
		cout << "Invalid character.\n Please choose a valid option: \n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> option;
	}
	

	switch (option){

	case 1:
		//calling function from "menu_functions.cpp"
		make_a_new_list();
		break;
		
	case 2 :
		//calling function from "menu_functions.cpp"
		display_list_menu();
		break;

	case 3:
		edit_list();
		break;

	case 4:
		search_menu();
		break;

	case 5:
		
		break;

	default: cout << "Invalid option\n Please choose an option from the menu.\n";
		system("pause");
		break;
	}

	if (option == 5){
		exit;
	}

	if (option != 5){
		main();
	}

	return 0;
}
