#include "Course.h"
using namespace std;
#include <string>
#include <fstream>
#include <vector>
//Bellow includes are recently added
 
#include <iostream>
#ifdef _WIN32
#include <windows.h> // For Windows console functions
#endif

// ANSI escape codes for text colors
// Reset Color:
#define ANSI_RESET "\033[0m"


//Foreground Colors:
#define ANSI_BLACK "\033[30m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_MAGENTA   "\033[34m"
//#define ANSI_MAGENTA "\033[35m"
#define ANSI_CYAN "\033[36m"
#define ANSI_WHITE "\033[37m"

//Background Colors:
#define ANSI_BG_BLACK "\033[40m"
#define ANSI_BG_RED "\033[41m"
#define ANSI_BG_GREEN "\033[42m"
#define ANSI_BG_YELLOW "\033[43m"
#define ANSI_BG_BLUE "\033[44m"
#define ANSI_MAGENTA  "\033[45m"
#define ANSI_BG_CYAN "\033[46m"
#define ANSI_BG_WHITE "\033[47m"



void setTextColor(int color) {
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif
}


void Course::Menu() {
	// Your menu implementation
	string Choose;
	cout   << ANSI_RED <<"====================================" << ANSI_RESET <<endl;
	cout   << ANSI_CYAN << "|A|->Students                       " << ANSI_RESET << endl;
	cout   << ANSI_CYAN << "|B|->Field                          " << ANSI_RESET << endl;
	cout   << ANSI_CYAN   << "|C|->Selected Caurse                " << ANSI_RESET << endl;
	cout   << ANSI_CYAN  << "|E|->Add to data                    " << ANSI_RESET << endl;
	cout   << ANSI_RED << "====================================" << ANSI_RESET << endl;
	cout   << ANSI_CYAN   << "|    Insert A, B, C, D or E        |" << ANSI_RESET << endl;
	cout   << ANSI_RED << "====================================" << ANSI_RESET << ANSI_RESET << endl;
	cin >> Choose;


	if (Choose == "A" || Choose == "a")
	{
		//student selection
		system("cls"); //clear the screen and cursor go to the left top cornor

		//student function
		students();

	}
	else if (Choose == "B" || Choose == "b") {
		system("cls");


		//select field
		selectField();
	}
	else if (Choose == "C" || Choose == "c") {
		system("cls");
		cout << "jef";
		//selected caurses
	}
	else if (Choose == "E" || Choose == "e") {
		system("cls");

		//add testing data
		fileRead();
		system("cls");
		Menu();

	}
	else {
		system("cls");
		cout   << ANSI_CYAN   <<"OOPs.....!!!! Wrong selection....Try again" << ANSI_RESET<<  endl;
		Menu();
	}
}


string Course::selectField() {
	// Logic to select a field
	string category;
	cout << ANSI_RED << " =================================" << ANSI_RESET << endl;
	cout   << ANSI_CYAN   << "     Select Your Field            " << ANSI_RESET << endl;
	cout   << ANSI_RED <<  " =================================" << ANSI_RESET << endl;
	cout   << ANSI_CYAN << "01. Chemical Engineering         " << ANSI_RESET << endl;
	cout   << ANSI_CYAN << "02. Civil Engineering" << ANSI_RESET << endl;
	cout   << ANSI_CYAN << "03. Electrical and Electronic Engineering" << ANSI_RESET << endl;
	cout   << ANSI_CYAN << "04. Mechanical Engineering" << ANSI_RESET << endl;
	

	cin >> category;
	if (category == "1" || category == "2" || category == "3" || category == "4" || category == "5") {
		system("cls");
		priceRange();
	}
	else {
		system("cls");
		cout   << ANSI_MAGENTA  << "Invalied Field" <<ANSI_RESET<< endl;
		category = selectField();
	}
	return(category);
}


void Course::students() {
	// Your student handling logic
	string student_1;
	cout << ANSI_RED << "=========================================" << ANSI_RESET <<  endl;
	cout << ANSI_CYAN   << "|E| Studant is an exsisting student    " << ANSI_RESET<< endl;
	cout << ANSI_CYAN   << "|N| Student is a new Student             " << ANSI_RESET << endl;
	cout << ANSI_CYAN   << "|B| Go Back                              " << ANSI_RESET << endl;
	cout << ANSI_RED << "=========================================" << ANSI_RESET << endl;

	cin >> student_1;


	if (student_1 == "N" || student_1 == "n") {
		//creating a new Student
		system("cls");
		cout << "Name = "; cin.ignore();
		getline(cin, temp.Name); //get input in seperate lines
		cout << "NIC = "; cin >> temp.NIC;
		cout << "Address = "; cin.ignore();
		getline(cin, temp.Address);
		cout << "Mobile Number = "; cin >> temp.PhoneNumber;



		NumberOfStudents++;

		data.push_back(temp);

		string anotherNewStudent;
		cout << "====================================" << endl;
		cout << "|A|->Add onther Student" << endl;
		cout << "|B|->Go back" << endl;
		cout << "|C|->Menu" << endl;
		cout << "====================================" << endl;
		cin >> anotherNewStudent;

		if (anotherNewStudent == "A" || anotherNewStudent == "a") {
			//addNewStudent();

			//add a newStudent using students's linkedList

			system("cls");
			students();

		}
		else if (anotherNewStudent == "B" || anotherNewStudent == "b") {
			//Go back
			system("cls");
			students(); //redirecting the student


		}
		else if (anotherNewStudent == "C" || anotherNewStudent == "c") {
			system("cls");
			Menu(); //redirecting the main menu

		}
		else if (anotherNewStudent == "K") {
			//operating for an existing customer

		}

	}
	else if (student_1 == "B" || student_1 == "b") {
		system("cls");
		Menu();
	}
	else {
		// Operation for existing customer
		system("cls");
		int j = 0;
		bool found = false;
		cout << "Enter NIC for existing customer: ";
		string inputNIC;
		cin >> inputNIC;
		cout << data.size();

		while (j < data.size()) {
			if (data[j].NIC == inputNIC) {
				found = true;
				break;
			}
			j++;
		}
		int loopfactor = 0;
		while (loopfactor == 0) {
			system("cls");
			if (found) {
				// Print information for the existing customer
				cout << "Name: " << data[j].Name << endl;
				cout << "NIC: " << data[j].NIC << endl;
				cout << "Address: " << data[j].Address << endl;
				cout << "Phone Number: " << data[j].PhoneNumber << endl;

				string option_1;
				cout << "Need to change student details(y/n)";
				cin >> option_1;
				if (option_1 == "y" || option_1 == "Y") {
					string Opinion;
					cout << "| A | Edit Customer's Name\t\t|\n| B | Edit Customer's NIC\t\t|\n| C | Edit Customer's Address\t\t|" << endl;
					cout << "| D | Edit Customer's Phone Number\t|\n| G | Main menu \t\t\t| \n----------------------------------------" << endl;
					cin >> Opinion;


					//Editing customer's data section
					if (Opinion == "A" || Opinion == "a") //Edit custormer's name
					{
						cout << "New Name =";
						cin >> data[j].Name;
					}
					else if (Opinion == "B" || Opinion == "b") //Edit custormer's NIC
					{
						cout << "New NIC =";
						cin >> data[j].NIC;
					}
					else if (Opinion == "C" || Opinion == "c") //Edit custormer's Address
					{
						cout << "New Address =";
						cin >> data[j].Address;
					}
					else if (Opinion == "D" || Opinion == "d") //Edit custormer's Phone no.
					{
						cout << "New Phone Number =";
						cin >> data[j].PhoneNumber;
					}
					else //Direct to the main menu
					{
						loopfactor = 1;
						system("cls");
						Menu();
					}

				}
				else {
					Menu();
				}
			}
			else {
				cout << "Customer with NIC " << inputNIC << " not found." << endl;
			}

		}


	}
	system("cls");
	students();
	//Edit student details


}


string Course::priceRange() {
	system("cls");
	string range;
	
	cout << ANSI_CYAN <<"   Select a preference price range    " << ANSI_RESET <<endl;
	cout << ANSI_RED << "=====================================" << ANSI_RESET<< endl;
	cout << endl;
	cout << ANSI_CYAN <<"|1|.RS. 1 000 000 - 1 500 000"    << ANSI_RESET << endl;
	cout << ANSI_CYAN <<"|2|.RS. 1 500 000 - 2 000 000"    << ANSI_RESET<<endl;
	cout << ANSI_CYAN <<"|3|.RS. 2 000 000 - 2 500 000"    << ANSI_RESET<< endl;
	cout << ANSI_CYAN <<"|4|.RS. 2 500 000 - 3 000 000"    << ANSI_RESET <<endl;
	cout << endl;
	cout << ANSI_RED << "=====================================" << ANSI_RESET<< endl;

	cin >> range;

	system("cls");

	
	// Traverse the linked list
	CourseList.printCoursesInPriceRange_1(range);

	return range;
}


void Course::fileRead() {
	
	fstream task;
	task.open("Tasklist.txt", ios::in);

	cout << "What department details you want to store";
	cout << endl;
	

	string category_1;

	cout << "\n1.Chemical Engineering\n2.Civil Engineering\n3.Electrical and Electronic Engineering\n4.Mechanical Engineering" << endl;

	cin >> category_1;
	if (category_1 == "1") {
		system("cls");

	}
	else {
		system("cls");
		cout << "Invalied Field" << endl;
	}


	if (true) {
		if (task.peek() == ifstream::traits_type::eof()) {
			
		}
		else {
			cout << "File is not empty" << endl;
		}

		int lenth = 0;
		cout << "Enter the number of courses you want to store: ";
		cin >> lenth;
		cin.ignore();

		for (int i = 0; i < lenth; ++i) {
			string uni, dec, pr,dr;
			cout << "University " << i + 1 << endl;

			cout << "University Name " << ": ";
			getline(cin, uni);

			cout << "Description "  << ": ";
			getline(cin, dec);

			cout << "Price "  << ": "<<"RS. ";
			getline(cin, pr);

			cout << "Duration" << ": ";
			getline(cin, dr);
			

			task << uni << " " << dec << " " << pr << endl;
			CourseList.insertLast(uni, dec, pr ,dr);
		}

		task.close();

	}
}

/*

int getConsoleWidth() {
#ifdef _WIN32
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	return columns;
#else
	// For other platforms, you may need to find a different way to get the console width
	return 80; // Default width
#endif
}*/
/*
void centerText(const std::string& text) {
	int consoleWidth = getConsoleWidth();
	int padding = (consoleWidth - text.length()) / 2;

	for (int i = 0; i < padding; ++i) {
		std::cout << " ";
	}

	std::cout << text << std::endl;
} */
