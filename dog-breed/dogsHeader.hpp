#ifndef DOGDB_DOG_H
#define DOGDB_DOG_H 

#include <iostream>
#include <cstring>
#include <fstream>
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

class DogTypes {
    dogBreed breeds[ARR_SIZE];
    int countAndIndex;
    char fileName[STR_SIZE];
    fstream file;
public:
    DogTypes();
    int loadBreeds();
    void writeBreeds();
    bool searchBreeds();
    void addABreed();
    void listBreeds();
};

#endif