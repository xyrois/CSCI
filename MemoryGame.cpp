//
/*
Author: Brinta Kundu
Course: CSCI-135
Instructor: Professor Yi
Assignment: Project 2 Task D



*/
//

#include "MemoryGame.hpp"
#include <iostream> 
#include <iomanip>
using namespace std;

MemoryGame::MemoryGame() : MemoryGame(3, 8) {

}

MemoryGame::MemoryGame(int numPairs, int numSlots) {
    if (numSlots <= 0 || numSlots < 2 * numPairs) {
        numPairs = 3;
        numSlots = 8;
    }

    this->numPairs = numPairs;
    this->numSlots = numSlots;

    values = new string[numSlots];
    bShown = new bool[numSlots];

    for (int i = 0; i < numSlots; ++i) {
        bShown[i] = false;
    }

    for (int i = 0; i < numPairs; ++i) {
        int randomInt = rand() % 1000;
        string str = to_string(randomInt);
        values[i * 2] = str;
        values[i * 2 + 1] = str;
    }

    for (int i = numPairs * 2; i < numSlots; ++i) {
        values[i] = "";
    }
}

MemoryGame::MemoryGame(string* words, int size, int numSlots) {
    if (size <= 0 || numSlots <= 0 || numSlots < 2 * size) {
        size = 3; 
        numSlots = 2 * size;
    }

    this->numPairs = size;
    this->numSlots = numSlots;

    values = new string[numSlots];
    bShown = new bool[numSlots];

    for (int i = 0; i < numSlots; ++i) {
        bShown[i] = false;
    }

    for (int i = 0; i < size; ++i) {
        values[i * 2] = words[i];
        values[i * 2 + 1] = words[i];
    }
    
    for (int i = size * 2; i < numSlots; ++i) {
        values[i] = "";
    }
}

MemoryGame::~MemoryGame() {
    delete[] values;
    values = 0; 
    delete[] bShown;
    bShown = 0;
}

void printSeparatedLine(int size) {
    cout <<'\n'<<'+'; 
    for (int i = 0; i < size; i++){
        cout << "-----+";
    }
}
void MemoryGame::randomize() {
    int size = numSlots; 

    while (size > 1) {
        int randomIndex = rand()%size;

        swap(values[randomIndex], values[size - 1]);
        size--;
    }
}

void MemoryGame::display() const {
    string dis;
    cout << " ";
    for (int i = 0; i < numSlots; i++){
        cout << setw(3) << i << setw(3) << " ";
    }
    printSeparatedLine(numSlots);
    cout << "\n";
    for (int i = 0; i < numSlots; i++){
        if (bShown[i]==false){
            dis="";
        }else if (bShown[i]==true){
            dis=values[i];
        }
        cout <<"|"<< "  "<< setw(3) << dis;
    }
    cout <<"|";
    printSeparatedLine(numSlots);
    cout<<endl;
}

int MemoryGame::input() const{
    int last_index=numSlots - 1;
    int flip;
    cout<<"Enter a unflipped card in [0,"<<last_index<<"]: "<<'\n';
    cin>>flip;
    while (bShown[flip]==true or flip < 0 or flip > last_index ){
        if (bShown[flip]==true){
            cout<<"The card is flipped already. Re-enter: "<<'\n';
            cin>>flip;
        }else if (flip < 0 or flip > last_index){
            cout<< "input is not in [0,"<<last_index<<"]. Re-enter: "<<'\n';
            cin>>flip;
        } 
    }
    return flip;
}
void MemoryGame::play() {
    randomize();
    int rounds = 0;
    int matchedPairs = 0;
    display();
    while (matchedPairs < numPairs) {
        rounds++;
        cout<< "round: "<<rounds<<endl;
        int index = input();
        bShown[index] = true;
        display();
        rounds++;
        cout<< "round: "<<rounds<<endl;
        int secondIndex = input();
        bShown[index]=false;
        bShown[secondIndex] = true;

        if (values[index] == values[secondIndex]) {
             matchedPairs++;
             bShown[index]=true;
             bShown[secondIndex]=true;
        }else{
            bShown[index]=false;
            bShown[secondIndex]=false;
        }
        display();
    }
    cout << "Congratulations! Found all the pairs in "<< rounds << " rounds!\n";
}