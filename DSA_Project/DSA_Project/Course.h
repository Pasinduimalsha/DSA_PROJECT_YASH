#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include<bits/stdc++.h>
#include <unordered_map>
#ifndef HASH_H
#define HASH_H
#endif // HASH_H

using namespace std;

class listnode {
public:
    string university;
    string description;
    string price;
    listnode* next;
    listnode* prev;

    listnode() {
        university = "NULL";
        description = "NULL";
        price = "NULL";
        next = NULL;
        prev = NULL;
    }

    listnode(string uni, string dec, string pr) {
        university = uni;
        description = dec;
        price = pr;
    }
};

class Doubly_Linked_List {
private:
    listnode* head;
    listnode* tail;

public:
    int size;

    Doubly_Linked_List() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertLast(string uni, string dec, string pr) {
        listnode* newnode = new listnode(uni, dec, pr);

        if (tail == NULL) {
            head = newnode;
            tail = newnode;
            size++;
        }
        else {


            if (size % 2 != 0) {
                tail->next = newnode;
                newnode->prev = tail;
                tail = newnode;
                tail->university = uni;
                tail->price = pr;
                size++;

            }
            else {
                tail->next = newnode;
                newnode->prev = tail;
                tail = newnode;
                tail->description = dec;
                size++;
            }
        }


    }

    void printAll() {
        listnode* current = head;

        if (size == 0) {
            cout << "Empty List" << endl;
        }
        else {
            for (int i = 0; i <= size; ++i) {
                cout << "| Course - " << i + 1 << "\t|" << endl;
                cout << current->university << endl;
                cout << current->description << endl;
                cout << "Price: " << current->price << " RUPEES" << endl;
                cout << "-----------------------------" << endl;
                current = current->next;
            }
        }
    }

    void sortByPrice() {
        if (size <= 1) {
            // Already sorted or empty list
            return;
        }

        bool swapped;
        listnode* ptr1;
        listnode* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->price > ptr1->next->price) {
                    // Swap the nodes
                    swapNodes(ptr1, ptr1->next);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void swapNodes(listnode* a, listnode* b) {
        // Swap university
        string tempUniversity = a->university;
        a->university = b->university;
        b->university = tempUniversity;

        // Swap description
        string tempDescription = a->description;
        a->description = b->description;
        b->description = tempDescription;

        // Swap price
        string tempPrice = a->price;
        a->price = b->price;
        b->price = tempPrice;
    }

    void printSortedByPrice() {
        sortByPrice();
        printAll();
    }
    void printCoursesInPriceRange(string range) {
        listnode* current = head;

        cout << "Courses in the selected price range:" << endl;

        while (current != NULL) {
            // Check if the current node's price falls within the selected range
            if ((range == "1" && stoi(current->price) >= 100000 && stoi(current->price) <= 500000) ||
                (range == "2" && stoi(current->price) >= 500000 && stoi(current->price) <= 1000000) ||
                (range == "3" && stoi(current->price) >= 1500000 && stoi(current->price) <= 2000000) ||
                (range == "4" && stoi(current->price) >= 2000000 && stoi(current->price) <= 2500000)) {
                cout << "| Course - " << endl;
                cout << current->university << endl;
                cout << current->description << endl;
                cout << "Price: " << current->price << " RUPEES" << endl;
                cout << "-----------------------------" << endl;
            }

            // Move to the next node
            current = current->next;
        }
    }
    //void printCoursesInPriceRangeSorted(string range) {
    //    listnode* current = head;

    //    cout << "Courses in the selected price range:" << endl;

    //    while (current != NULL && stoi(current->price) < stoi(range)) {
    //        current = current->next; // Move to the first Course within or after the range
    //    }

    //    while (current != NULL && stoi(current->price) <= stoi(range) * 10) {
    //        // Check if the current node's price falls within the selected range (considering the multiplied range)
    //        cout << "| Course - " << endl;
    //        cout << current->university << endl;
    //        cout << current->description << endl;
    //        cout << "Price: " << current->price << " RUPEES" << endl;
    //        cout << "-----------------------------" << endl;

    //        // Move to the next node
    //        current = current->next;
    //    }
    //}

    void printCoursesInPriceRange_1(string range) {
        sortByPrice();
        printCoursesInPriceRange(range);


    }

    //void printSortedCoursesInPriceRange(string range) {
    //    sortByPrice();
    //    //printCoursesInPriceRange(range);
    //    printCoursesInPriceRangeSorted(range);

    //}


};

struct Students {
    string Name = "NULL";
    string NIC = "NULL";
    string Address = "NULL";
    string PhoneNumber = "NULL";

};

class Course {
private:
    listnode* head;
    Doubly_Linked_List CourseList;
    vector<Students> data; //To save students Details
    Students temp; //Tempory object to input student data
    int NumberOfStudents = 0;
    bool shouldCallStudents; // Flag to determine whether to call students() function

    // Other member variables and functions...

public:
    /*Course() {

        // Initialize other variables or functionalities if needed...
    }
    ~Course() { //Defaul Destructor
    }*/
    Course() : shouldCallStudents(true) {
        // Initialize other variables or functionalities if needed...
    }

    void Menu();
    void students();
    string selectField();
    string priceRange();
    void fileRead();

    // Other member functions...
};
/*
class Hash
{
    int BUCKET;    // No. of buckets

    // Pointer to an array containing buckets
    list<int>* table;
public:
    Hash(int V);  // Constructor

    // inserts a key into hash table
    void insertItem(int x);

    // deletes a key from hash table
    void deleteItem(int key);

    // hash function to map values to key
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    void displayHash();
};
*/