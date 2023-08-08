//============================================================================
// Name        : Source.cpp
// Author      : Kirklen Allen
// Version     : 1.0
// Description : SNHU CS 210 Final
//============================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#pragma once
using namespace std;

// This function is used to read the input file and store the frequency of each item
map<string, int> read_file(string filename) {
    map<string, int> freq; // A map to hold the item and its frequency
    ifstream infile(filename); //  Read the file
    string item; // A string to hold the place of an item
    while (infile >> item) { //
        freq[item]++; // Increment the frequency of the item 
    }
    infile.close(); // Close the file
    return freq; // Return the map
}

// This function is used to show the frequency of a specific item
void print_item_freq(map<string, int> freq, string item) {
    if (freq.count(item) > 0) { 
        cout << "The frequency of " << item << " is " << freq[item] << endl; // Print the frequency
    }
    else { // If the item does not exist
        cout << "The item " << item << " is not found in the file." << endl; // Print a message
    }
}

// This function is used to print the list of items and their frequencies
void print_list_freq(map<string, int> freq) {
    cout << "The list of items and their frequencies are:" << endl;
    for (auto pair : freq) { 
        cout << pair.first << " " << pair.second << endl; // Print the item and its frequency
    }
}

// This function is used to print a histogram of all items and frequencies
void print_histogram_freq(map<string, int> freq) {
    cout << "The histogram of items and their frequencies are:" << endl;
    for (auto pair : freq) { 
        cout << pair.first << " "; // Print the item
        for (int i = 0; i < pair.second; i++) { // For each frequency unit
            cout << "*"; // Print an asterisk
        }
        cout << endl; // Print a new line
    }
}
// This function is used to create a data file with frequencies of all items
void create_data_file(map<string, int> freq) {
    ofstream outfile("frequency.dat"); // Create an output file stream object
    if (outfile.is_open()) { // Check if the output file stream is open
        for (auto pair : freq) { // For each pair in the map
            outfile << pair.first << " " << pair.second << endl; // Write the item and its frequency to the output file
        }
        outfile.close(); // Close the output file stream
        cout << "The data file has been created successfully." << endl; // Print a confirmation message
    }
    else { // If the output file stream is not open
        cout << "The data file could not be created." << endl; // Print an error message
    }
}
// The main function
int main() {
    string filename = "CS210_Project_Three_inInput_File.txt"; // The name of the input file
    map<string, int> freq = read_file(filename); // Read the file and store the frequency map

    int choice; // An integer for the user choice
    string item; // A string to for the user input

    do { //loop to repeat until the user exits the program
        // Print the menu options
        cout << "Menu Options:" << endl;
        cout << "1. Search an item and show its frequency." << endl;
        cout << "2. Print the current list with frequencies of every item." << endl;
        cout << "3. Print a histogram with frequencies of all items." << endl;
        cout << "4. Exit the program." << endl;
        cout << "5. Backup Frequency Data." << endl;

        cout << "Enter your choice: "; // Prompt the user to selct a choice
        cin >> choice; // Validate the user's choice

        switch (choice) { // Switch case based on the user's choice
        case 1: // If the user selects option 1
            cout << "You have Selected Option 1" << endl;
            cout << "- Initiaitng Item Frecquecy Search Engine -" << endl;
            cout << "Enter an item: "; // Prompt the user to enter an item
            cin >> item; // Read the user's input item
            print_item_freq(freq, item); // Print the frequency of that item
            break; // Break 

        case 2: // If the user selects option 2
            cout << "You have Selected Option 2" << endl;
            cout << "- Initiaitng Item Displayer -" << endl;
            print_list_freq(freq); // Print the list of all items and their frequencies
            break; // Break

        case 3: // If the user selects option 3
            cout << "You have Selected Option 3" << endl;
            cout << "- Initiating Histogram Report -" << endl;
            print_histogram_freq(freq); // Print a histogram of all items and their frequencies
            break; // Break

        case 4: // If the user selects option 4
            cout << "You have Selected Option 4" << endl;
            cout << "Exiting the Program... Farewell!" << endl; // Exit Program
            break; // Break 
        
        case 5: // If the user selects option 5
            cout << "Backing Up Now ... Complete!" << endl;
            create_data_file(freq); // Create a data file with frequencies of all items
            break; // Break

        default: // If the user chooses an invalid option
            cout << "Invalid choice. Please try again." << endl; // Print an error message
            break; // Break 

        }

        cout << endl;

    } while (choice != 4); // Repeat until the user chooses option 4

    return 0; // Return 0 to indicate successful termination
}
