//CSCE 3444 - ATEG Algorithm - PairSet Header - Andrew Ragland

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <random>
#include <vector>
#include <regex>
#include <ctime>

using namespace std;

//Class which returns a bitwise XOR of two ints as a hash value for an unordered map
class PairHash{
public:

    size_t operator()(const pair<int,int>& p) const
    {
        return (hash<int>()(p.first)) ^ (hash<int>()(p.second));
    }
};

//Class which acts to generate and manage the pairs associated with the ATEG algorithm
class PairSet {
private:
    unordered_set<pair<int,int> ,PairHash> coverSet; //Primary data structure for storing
    unordered_set<pair<int,int>, PairHash> copySet;  //Data structure to store a copy of coverSet, used for resetting
    vector<vector<int>> coveringArray;               //Array which holds the levels and factors as specified by a user
    int covered = 0;                                 //Stores the current number of pairs covered
    int totalPairs;                                  //Stores the total number of pairs within coverSet

public:
    PairSet(vector<vector<int>> coverArray);         //Generate pairs given the coveringArray as populated in main
    int countPairs(int, int);                        //Count the potential # of pairs that a single level could cover
    int countPairs(vector<int>,int);                 //Count the # of pairs the current candidate can cover
    void coverPairs(vector<int>);                    //Cover pairs specified by a given candidate by removal from set
    int getCovered();                                //Return the value of covered
    int getTotalPairs();                             //Return the value of totalPairs
    void resetPairs();                               //Reset the coverSet when test suite is finished being created
};


