//#include <iostream>
#include "dogsHeader.hpp"

// const int STR_SIZE = 100;
// const int ARR_SIZE = 100;

DogTypes::DogTypes() {
    countAndIndex = 0;
    file.open(fileName, ios::in | ios::app);
}

void DogTypes::addABreed() {
    
    if(countAndIndex >= ARR_SIZE) {
        cout << "Sorry, no more room in the array." << endl;
        return;
    }
    else {
        cin.ignore();
        cout << "What is the name of the new dog? ";
        cin >> ws; // eat up any leading white spaces
        cin.getline(breeds[countAndIndex].name, STR_SIZE);
        cout << "What is the description of the new dog? ";
        cin >> ws;
        cin.getline(breeds[countAndIndex].description, STR_SIZE);
        cout << "What is the classification of the new dog? ";
        cin >> ws;
        cin.getline(breeds[countAndIndex].classification, STR_SIZE);
        cout << "What is the average weight in pounds (between 4 and 195)? ";
        cin >> breeds[countAndIndex].avgWeight;
        while(cin.fail() || breeds[countAndIndex].avgWeight < 4 || breeds[countAndIndex].avgWeight > 195) {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Error, please enter positive numbers between 4 and 195." << endl;
            cout << "What is the average weight (between 4 and 195 pounds)? ";
            cin >> breeds[countAndIndex].avgWeight;
        }
        cout << "What is the average height in inches (between 8 and 33)? ";
        cin >> breeds[countAndIndex].avgHeight;
        while(cin.fail() || breeds[countAndIndex].avgHeight < 8 || breeds[countAndIndex].avgHeight > 33) {
            cin.clear();
            cin.ignore();
            cout << "Error, please enter positive numbers between 8 and 33." << endl;
            cout << "What is the average height (between 8 and 33 inches)? ";
            cin >> breeds[countAndIndex].avgHeight;
        }
        cin.ignore();
        cout << "What is the origin of the new dog? ";
        cin >> ws;
        cin.getline(breeds[countAndIndex].origin, STR_SIZE);
        cout << breeds[countAndIndex].name << " was successfully added to the database." << endl;
        countAndIndex++;
    }
}

bool DogTypes::searchBreeds() {
    int i = 0;
    bool result = false;
    char searchName[STR_SIZE];
    cin.ignore();
    cout << "What dog do you want to search for? ";
    cin.getline(searchName, STR_SIZE);
    for(i = 0; i < countAndIndex; i++) {
        if(strcmp(breeds[i].name, searchName) == 0) {
            result = true;
            cout << "The info for " << searchName << " is as follows:" << endl;
            cout << breeds[i].description << ", "  << breeds[i].classification << ", average weight: " 
                << breeds[i].avgWeight << " pounds, average height: " << breeds[i].avgHeight << " inches, from "
                << breeds[i].origin << endl;
            break;
        } 
    }
    if(!result) {
        cout << searchName;
    }
    return result;
}

int DogTypes::loadBreeds() {
    cout << "Welcome to the dog breed information program. What is the name of the dog breed data file? ";
    cin.getline(fileName, STR_SIZE);
    file.open(fileName);
    while(!file.is_open()) {
        cout << fileName << " was not found. Please try again or type 'quit' to exit the program. ";
        cin.getline(fileName, STR_SIZE);
        file.open(fileName);
        if(strcmp(fileName, "quit") == 0) {
            return 0;
        }
    }
    // Read all of the data from the file.
    // Pug,Loveable lap dog,Toy Group,12.5,11.0,China
    // German Shepherd,shepherd dog,Working Group, ...
    while(!file.eof()) {
        file.getline(breeds[countAndIndex].name, STR_SIZE, ','); // name will get "Pug"
        file.getline(breeds[countAndIndex].description, STR_SIZE, ',');
        file.getline(breeds[countAndIndex].classification, STR_SIZE, ',');
        file >> breeds[countAndIndex].avgWeight;
        file.ignore(1); // remove the comma.
        file >> breeds[countAndIndex].avgHeight;
        file.ignore();
        file.getline(breeds[countAndIndex].origin, STR_SIZE, '\n');
        countAndIndex++;
        if(countAndIndex >= ARR_SIZE) { // the array is full.
            break;
        }
        file.peek(); // checking for the end of file marker.
    }
    file.close();
    return countAndIndex;
}

void DogTypes::listBreeds() {
    int listCount;
    cout << left << setw(22) << "Name" << setw(40) << "Description" << setw(20) << "Group" << setw(10) << "Weight"
        << setw(10) << "Height" << setw(20) << "Origin" << endl;
    cout << setfill('-') << setw(110) << "-" << endl;
    cout << setfill(' ');
    for(listCount = 0; listCount < countAndIndex; ++listCount) {
        cout << left << setw(22) << breeds[listCount].name << setw(40) << breeds[listCount].description 
            << setw(20) << breeds[listCount].classification << setw(10)
            << fixed << setprecision(2) << breeds[listCount].avgWeight 
            << setw(10) << breeds[listCount].avgHeight
            << setw(20) << breeds[listCount].origin << endl;
    }
}

void DogTypes::writeBreeds() {
    int i;
    file.open(fileName);
    file.clear();
    for(i = 0; i < countAndIndex; ++i) {
        file << breeds[i].name << "," << breeds[i].description << "," << breeds[i].classification 
        << "," << fixed << setprecision(2) << breeds[i].avgWeight << "," << breeds[i].avgHeight << "," << breeds[i].origin << endl;
    }
    file.close();
}

