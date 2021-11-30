/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Luis Hernandez
 */

#include "std_lib_facilities.h"
using namespace std;

//class Name_value that stores a string and an integer
class Name_value {
    public:
        string names;
        int scores;
};

int main() {
    //creating Objects
    vector<Name_value> info;
    //create an Object pointer
    Name_value *n = new Name_value;
    //necessary variables
    string name;
    int score;
    //while loop
    cout << "Please enter a name and a score: \n";
    do {
        cin >> name;
        cin >> score;
        n->names = name;
        n->scores = score;
        //iterate through the vector, and see if the name given is the same as one already given
        vector<Name_value>::iterator read;
        //make a for loop
        for(read = info.begin(); read != info.end(); read++) {
            //now check if the new name given is equal to an existant name already in the vector
            if(n->names == read->names) {
                cout << "Duplicate names are not allowed.";
                return 0;
            }
        }
        //add to the vector
        info.push_back(*n);
    } while(name != "NoName" || score != 0);
    //delete the last element of the vector (which is NoName 0)
    info.pop_back();
    //print the names and their scores
    cout << "The list printed: \n";
    vector<Name_value>::iterator read;
    for(read = info.begin(); read != info.end(); read++) {
        cout << read->names << " " << read->scores;
        cout << "\n";
    }
    
    return 0;
}