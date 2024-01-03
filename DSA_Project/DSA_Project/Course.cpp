#include "Course.h"
using namespace std;
#include <string>
#include <fstream>
#include <vector>
//#include "Hash.h"
//Bellow includes are recently added

#include <iostream>
#ifdef _WIN32
#include <windows.h> // For Windows console functions
#endif
#include <iomanip>  // for setw

// ANSI escape codes for text colors
// Reset Color:
#define ANSI_RESET "\033[0m"


//Foreground Colors:
#define ANSI_BLACK "\033[30m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"
#define ANSI_MAGENTA "\033[35m"
#define ANSI_CYAN "\033[36m"
#define ANSI_WHITE "\033[37m"

//Background Colors:
#define ANSI_BG_BLACK "\033[40m"
#define ANSI_BG_RED "\033[41m"
#define ANSI_BG_GREEN "\033[42m"
#define ANSI_BG_YELLOW "\033[43m"
#define ANSI_BG_BLUE "\033[44m"
#define ANSI_BG_MAGENTA "\033[45m"
#define ANSI_BG_CYAN "\033[46m"
  //#define    "000\033[47m"



void setTextColor(int color) {
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif
}

void Course::Menu() {
	// Your menu implementation
	string Choose;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10);

	cout << ANSI_GREEN << setw(80) << "===================================="<< ANSI_RESET << endl;
	cout << setw(60) << "\t  |A|->Students" << endl;
	cout << setw(60) << "|B|->Field" << endl;
	cout << setw(70) << "|C|->Selected Course" << endl;
	//cout << setw(80) << "     |D|->Login as a Field" << endl;
	cout << setw(60) << "\t  |E|->Add to data" << endl;
	cout << ANSI_GREEN << setw(80) << "     ====================================" << ANSI_RESET << endl;
	cout << setw(70) << "|    Insert A, B, C, D or E" << endl;
	cout << ANSI_GREEN << setw(80) << "     ====================================" << ANSI_RESET << endl;
	SetConsoleTextAttribute(h, 15);

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
	else if (Choose == "D" || Choose == "d") {
		system("cls");
		//caurse adder
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
		cout    << "OOPs.....!!!! Wrong selection....Try again" << ANSI_RESET << endl;
		Menu();
	}
}



string Course::selectField() {
	// Logic to select a field
	string category;
	cout    << "     Select Your Field            " << ANSI_RESET << endl;
	cout <<     ANSI_RED << " =================================" << ANSI_RESET << endl;
	cout    << "01. Architecture & Design         " << ANSI_RESET << endl;
	cout    << "02. Arts & Humanities             " << ANSI_RESET << endl;
	cout    << "03. Aviation Industry             " << ANSI_RESET << endl;
	cout    << "04. Beauty & Hair                 " << ANSI_RESET << endl;
	cout    << "05. Business & Management         " << ANSI_RESET << endl;



	cin >> category;
	if (category == "1" || category == "2" || category == "3" || category == "4" || category == "5") {
		system("cls");
		priceRange();
	}
	else {
		system("cls");
		cout    << "Invalied Field" << ANSI_RESET << endl;
		category = selectField();
	}
	return(category);
}


void Course::students() {
	// Your student handling logic
	string student_1;
	cout <<     ANSI_RED << "=========================================" << ANSI_RESET << endl;
	cout    << "|NIC| Studant is an exsisting student    " << ANSI_RESET << endl;
	cout    << "|N| Student is a new Student             " << ANSI_RESET << endl;
	cout    << "|B| Go Back                              " << ANSI_RESET << endl;
	cout <<     ANSI_RED << "=========================================" << ANSI_RESET << endl;

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
					cout << "| A | Existing case    |\n| B | New case     |\n| C | Edit Customer's Name  |\n| D | Edit Customer's NIC  |\n| E | Edit Customer's Address  |" << endl;
					cout << "| F | Edit Customer's Phone Number |\n| G | Main menu    | \n----------------------------------------" << endl;
					cin >> Opinion;

					if (Opinion == "A" || Opinion == "a")
					{
						//cout << "Customer will have a discount\nWhat is the case number?" << endl;
						//int CaseNumber;			//The case number that customer wish to pay
						//cin >> CaseNumber;

						////The loop runs until all cases of a particular customer finished
						//while (CaseNumber > data[j].Cases->size) {
						//	cout << "invalid case number\nWhat is the case number?" << endl;
						//	cin >> CaseNumber;
						//}

						////Add an existing case for relavant repaimen
						//AddCaseToRepairmen(data[j].NIC, data[j].Cases->getOne(CaseNumber)->repairmen,
						//	data[j].Cases->getOne(CaseNumber)->Problem,
						//	data[j].Cases->getOne(CaseNumber)->description);


						//LoopFactor = 1;
					}

					else if (Opinion == "B" || Opinion == "b") //Add a new case
					{/*
						AddNewCase(data[j], data[j].NIC);
						LoopFactor = 1;*/
					}

					//Editing customer's data section
					else if (Opinion == "C" || Opinion == "c") //Edit custormer's name
					{
						cout << "New Name =";
						cin >> data[j].Name;
					}
					else if (Opinion == "D" || Opinion == "d") //Edit custormer's NIC
					{
						cout << "New NIC =";
						cin >> data[j].NIC;
					}
					else if (Opinion == "E" || Opinion == "e") //Edit custormer's Address
					{
						cout << "New Address =";
						cin >> data[j].Address;
					}
					else if (Opinion == "F" || Opinion == "f") //Edit custormer's Phone no.
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
	cout << "Select preference price range" << endl;
	cout << "|1|. 100 000 -  500 000 RUPEES" << endl;
	cout << "|2|. 500 000 - 1 000 000 RUPEES" << endl;
	cout << "|3|. 1 500 000 - 2 000 000 RUPEES" << endl;
	cout << "|4|. 2 000 000 - 2 500 000 RUPEES" << endl;

	cin >> range;

	system("cls");

	cout << "Courses in the selected price range:" << endl;


	// Traverse the linked list
	CourseList.printCoursesInPriceRange_1(range);

	//string x;
	/*cout << "If you want sortd caurse list(y/n)";
	cin >> x;
	if (x == "Y" || x == "y") {
		system("cls");
		CourseList.printSortedCoursesInPriceRange(range);

	}
	else {
		cout << "You seleted caurses" << endl;
	}*/



	return range;
}





void Course::fileRead() {
	cout << "File Reading" << endl;
	fstream task;
	task.open("Tasklist.txt", ios::in);

	cout << "What department details you want to store";

	string category_1;

	cout << "1.COM\n2.Elec\n3.Con\n4.BS" << endl;

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
			cout << "Link is empty" << endl;
		}
		else {
			cout << "File is not empty" << endl;
		}

		int lenth = 0;
		cout << "Enter the number of entries: ";
		cin >> lenth;
		cin.ignore();

		for (int i = 0; i < lenth; ++i) {
			string uni, dec, pr;


			cout << "Enter university " << i + 1 << ": ";
			getline(cin, uni);

			cout << "Enter description " << i + 1 << ": ";
			getline(cin, dec);

			cout << "Enter price " << i + 1 << ": ";
			getline(cin, pr);

			task << uni << " " << dec << " " << pr << endl;
			CourseList.insertLast(uni, dec, pr);
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

/*
Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
	// get the hash index of key
	int index = hashFunction(key);

	// find the key in (index)th list
	list <int> ::iterator i;
	for (i = table[index].begin();
		i != table[index].end(); i++) {
		if (*i == key)
			break;
	}

	// if key is found in hash table, remove it
	if (i != table[index].end())
		table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() {
	for (int i = 0; i < BUCKET; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " --> " << x;
		cout << endl;
	}
}
*/