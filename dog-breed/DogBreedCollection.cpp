#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

const int STR_SIZE = 100;
const int ARR_SIZE = 100;

struct dogBreed {
    char name[STR_SIZE];
    char description[STR_SIZE];
    char classification[STR_SIZE];
    double avgWeight;
    double avgHeight;
    char origin[STR_SIZE];
};

// Loadbreeds() prototype.
int loadBreeds(dogBreed myDogs[]);
bool searchBreeds(dogBreed myDogs[], int count);
// prototypes for the other functions.
void addABreed(dogBreed myDogs[], int count);
void listBreeds(dogBreed myDogs[], int count); 

int main() {
    dogBreed myDogs[ARR_SIZE];
    int breedCount;
    bool success = false;
    char choice = ' ';
    choice = toupper(choice);
    
    breedCount = loadBreeds(myDogs);
    if(breedCount != 0) {
        cout << "Successfully loaded " << breedCount << " dog breeds." << endl;
        cout << endl;
        listBreeds(myDogs, breedCount);

        do {
            cout << endl;
            cout << "What would you like to do? (S)earch for a breed, (A)dd a breed, (L)ist a breed, or (Q)uit? ";
            cin >> choice;
            choice = toupper(choice);
            if(choice == 'S') {
                success = searchBreeds(myDogs, breedCount);
                if(!success) {
                    cout << " was not found in the database." << endl;
                }
            }
            if(choice == 'A') {
                addABreed(myDogs, breedCount);
                breedCount++;
            }
            if(choice == 'L') {
                if(breedCount >= 0) { 
                    listBreeds(myDogs, breedCount);
                }
                else {
                    cout << "There is no dog breed in data file" << endl;
                }
            }   
        } while(choice != 'Q');
        if(choice == 'Q') {
            cout << "Terminating Program." << endl;
        } 
    }
    else {
        cout << "Terminating program." << endl;
    }
    return 0;
}

void addABreed(dogBreed myDogs[], int count) {
    
    if(count >= ARR_SIZE) {
        cout << "Sorry, no more room in the array." << endl;
        return;
    }
    else {
        cin.ignore();
        cout << "What is the name of the new dog? ";
        cin.getline(myDogs[count].name, STR_SIZE);
        cout << "What is the description of the new dog? ";
        cin.getline(myDogs[count].description, STR_SIZE);
        cout << "What is the classification of the new dog? ";
        cin.getline(myDogs[count].classification, STR_SIZE);
        cout << "What is the average weight in pounds (between 4 and 195)? ";
        cin >> myDogs[count].avgWeight;
        while(cin.fail() || myDogs[count].avgWeight < 4 || myDogs[count].avgWeight > 195) {
            cin.clear();
            cin.ignore(STR_SIZE, '\n');
            cout << "Error, please enter positive numbers between 4 and 195." << endl;
            cout << "What is the average weight (between 4 and 195 pounds)? ";
            cin >> myDogs[count].avgWeight;
        }
        cout << "What is the average height in inches (between 8 and 33)? ";
        cin >> myDogs[count].avgHeight;
        while(cin.fail() || myDogs[count].avgHeight < 8 || myDogs[count].avgHeight > 33) {
            cin.clear();
            cin.ignore();
            cout << "Error, please enter positive numbers between 8 and 33." << endl;
            cout << "What is the average height (between 8 and 33 inches)? ";
            cin >> myDogs[count].avgHeight;
        }
        cin.ignore();
        cout << "What is the origin of the new dog? ";
        cin.getline(myDogs[count].origin, STR_SIZE);
        cout << myDogs[count].name << " was successfully added to the database." << endl;
        count++;
    }
}

bool searchBreeds(dogBreed myDogs[], int count) {
    int i = 0;
    bool result = false;
    char searchName[STR_SIZE];
    cin.ignore();
    cout << "What dog do you want to search for? ";
    cin.getline(searchName, STR_SIZE);
    for(i = 0; i < count; i++) {
        if(strcmp(myDogs[i].name, searchName) == 0) {
            result = true;
            cout << "The info for " << searchName << " is as follows:" << endl;
            cout << myDogs[i].description << ", "  << myDogs[i].classification << ", average weight: " 
                << myDogs[i].avgWeight << " pounds, average height: " << myDogs[i].avgHeight << " inches, from "
                << myDogs[i].origin << endl;
            break;
        } 
    }
    if(!result) {
        cout << searchName;
    }
    return result;
}

int loadBreeds(dogBreed myDogs[]) {
    char fileName[STR_SIZE];
    ifstream inFile;
    int index = 0;
    cout << "Welcome to the dog breed information program. What is the name of the dog breed data file? ";
    cin.getline(fileName, STR_SIZE);
    inFile.open(fileName);
    while(!inFile.is_open()) {
        cout << fileName << " was not found. Please try again or type 'quit' to exit the program. ";
        cin.getline(fileName, STR_SIZE);
        inFile.open(fileName);
        if(strcmp(fileName, "quit") == 0) {
            return 0;
        }
    }
    // Read all of the data from the file.
    // Pug,Loveable lap dog,Toy Group,12.5,11.0,China
    // German Shepherd,shepherd dog,Working Group, ...
    while(!inFile.eof()) {
        inFile.getline(myDogs[index].name, STR_SIZE, ','); // name will get "Pug"
        inFile.getline(myDogs[index].description, STR_SIZE, ',');
        inFile.getline(myDogs[index].classification, STR_SIZE, ',');
        inFile >> myDogs[index].avgWeight;
        inFile.ignore(1); // remove the comma.
        inFile >> myDogs[index].avgHeight;
        inFile.ignore();
        inFile.getline(myDogs[index].origin, STR_SIZE, '\n');
        index++;
        if(index >= ARR_SIZE) { // the array is full.
            break;
        }
        inFile.peek(); // checking for the end of file marker.
    }
    inFile.close();
    return index;
}

void listBreeds(dogBreed myDogs[], int count) {
    int listCount;
    cout << left << setw(22) << "Name" << setw(40) << "Description" << setw(20) << "Group" << setw(10) << "Weight"
        << setw(10) << "Height" << setw(20) << "Origin" << endl;
    cout << setfill('-') << setw(110) << "-" << endl;
    cout << setfill(' ');
    for(listCount = 0; listCount < count; ++listCount) {
        cout << left << setw(22) << myDogs[listCount].name << setw(40) << myDogs[listCount].description 
            << setw(20) << myDogs[listCount].classification << setw(10)
            << fixed << setprecision(2) << myDogs[listCount].avgWeight 
            << setw(10) << myDogs[listCount].avgHeight
            << setw(20) << myDogs[listCount].origin << endl;
    }
}

