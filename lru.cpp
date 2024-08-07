#include "lru.hpp"
#include<iostream>
#include <iomanip>
#include<list>
using namespace std;

lru::lru(){
    frame = 0;
    pos = 0;
    frames.push_back(frame);
}

lru::~lru(){
    for(auto& e : frames)
        frames.pop_back();
}

void lru::AddReferenceString(int address, int frameLength){
    frame = address / pow(10,frameLength-1);
    if(frame == frames.at(pos))
        return;
    frames.push_back(frame);
    pos++;
}

void lru::CreateSet(int frameSize){
    for(int i = 0; i < frameSize; ++i)
        set.push_back(-1);
}

void lru::PrintReferenceString(){
    for(int i = 1; i < frames.size(); ++i)
        cout << frames.at(i) << " ";
    cout << endl;
}

void lru::lruAlgorithm(){
    int pageFaults = 0;
    list<int> lruList;
    cout << setfill('.') << setw(40) << ".\n" << setfill(' ');
    //Loop through list of frames
    for(int i = 1; i < frames.size(); ++i){
        bool hasPage = false;

        //Page is in set
        for(int j = 0; j < set.size(); ++j){
            if(set.at(j) == frames.at(i)){
                hasPage = true;
                //Remove previous instance of page
                //And put the page at the front of the list
                lruList.remove(frames.at(i));
                lruList.push_front(frames.at(i));
                break;
            }
        }

        //Page is not in set
        if(!hasPage){
            pageFaults++;
            bool pageInserted = false;

            //Set is not full
            for(int j = 0; j < set.size(); ++j){
                if(set.at(j) == -1){
                    set.at(j) = frames.at(i);
                    lruList.push_front(frames.at(i)); //Push page to front of list
                    pageInserted = true;
                    PrintSet();
                    break;
                }
            }
            //Set is full
            if(!pageInserted){
                if(!lruList.empty()){
                    int lruPage = lruList.back();
                    lruList.pop_back();
                    for(int j = 0; j < set.size(); ++j){
                        if(set.at(j) == lruPage){
                            set.at(j) = frames.at(i);
                            lruList.push_front(frames.at(i)); //Push page to front of list
                            PrintSet();
                            break;
                        }
                    }
                }
            }

        }
    }
    cout << setfill('.') << setw(40) << ".\n";
    cout << "Total number of page faults: " << pageFaults << endl;
    return;
}

void lru::PrintSet(){
    for(int i = 0; i < set.size(); ++i)
        cout << setw(3) <<  set.at(i);
    cout << endl;
}
