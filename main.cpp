//Written by Miles Brown
#include<fstream>
#include "lru.hpp"
using namespace std;

int main(){
    lru LRU;
    ifstream input;
    int length;
    int address;
    int count = 0;

    cout << "\nWelcome to the LRU program!\n";
    cout << "This program simulates the Least Recently Used Algorithm,\n"
         << "which allocates frames in memory by removing the frame\n"
         << "that was least recently accessed.\n"
         << "Along with displaying the allocated frames, this program\n"
         << "will also give the number of page faults experienced.\n";
    cout << endl;
    
    cout << "Receiving user input...\n\n";
    input.open("23F_COP4610_Project3_InputFile.txt");
    if(!input.is_open())
        cout << "Failed to open file" << endl;
    input >> length;
    LRU.CreateSet(length);
    cout << "Number of frames allocated to the process: " << length;
    cout <<"\n\nThe address sequence in the file is: \n";
    while(input >> address)
    {
        LRU.AddReferenceString(address, length);
        cout << address << " ";
        count++;
        if(count==10){
            count=0;
            cout << endl;
        }
    }

    cout << "\nThe reference string is: \n";
    LRU.PrintReferenceString();
    cout << "\nRunning the LRU Fit algorithm...\n";
    cout << "\nPage allocations to the frame:\n";
    LRU.lruAlgorithm();
    return 0;
}