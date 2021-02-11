//
// Created by Andrew on 1/28/2021.
//
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <random>
#include <vector>
#include <regex>
#include <ctime>

using namespace std;

class PairHash{
public:

    size_t operator()(const pair<int,int>& p) const
    {
        return (hash<int>()(p.first)) ^ (hash<int>()(p.second));
    }
};


class PairMap {
private:
    unordered_map<pair<int,int>,bool,PairHash> coverMap;
    unordered_map<pair<int,int>, bool,PairHash> copyMap;
    vector<vector<int>> coveringArray;
    int covered = 0;
    int totalPairs;

public:
    PairMap(vector<vector<int>> coverArray);
    int countPairs(int, int);
    int countPairs(vector<int>,int);
    void coverPairs(vector<int>);
    int getTotalPairs();
    void resetPairs();


    int getCovered();
};


