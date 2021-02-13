#include "dogsHeader.hpp"

int main() {
    DogTypes dogDatabase;
    int breedCount;
    bool success = false;
    char choice = ' ';
    choice = toupper(choice);
    
    breedCount = dogDatabase.loadBreeds();
    if(breedCount != 0) {
        cout << "Successfully loaded " << breedCount << " dog breeds." << endl;
        cout << endl;
        dogDatabase.listBreeds();

        do {
            cout << endl;
            cout << "What would you like to do? (S)earch for a breed, (A)dd a breed, (L)ist a breed, or (Q)uit? ";
            cin >> choice;
            choice = toupper(choice);
            if(choice == 'S') {
                success = dogDatabase.searchBreeds();
                if(!success) {
                    cout << " was not found in the database." << endl;
                }
            }
            if(choice == 'A') {
                dogDatabase.addABreed();
                breedCount++;
            }
            if(choice == 'L') {
                if(breedCount >= 0) { 
                    dogDatabase.listBreeds();
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