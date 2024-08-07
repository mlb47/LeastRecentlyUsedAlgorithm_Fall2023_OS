#ifndef LRU_H
#define LRU_H
#include <iostream>
#include <cmath>
#include <vector>

class lru{
    public:
        lru();
        ~lru();
        void AddReferenceString(int address, int length);
        void PrintReferenceString();
        void CreateSet(int frameSize);
        void lruAlgorithm();
        void PrintAllocations();
        void PrintSet();

    private:
    int frame;
    int pos;
    std::vector<int> frames;
    std::vector<int> set;
};
#endif