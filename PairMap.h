//
// Created by Andrew on 1/28/2021.
//
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
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
    unordered_map<pair<int,int>,bool,PairHash>::iterator it;
    int factors = 0;
    int levels = 0;

public:
    PairMap(vector<vector<int>> coverArray);
    vector<pair<int,int>> findPairs(int);
    int countPairs(int);
    int countPairs(vector<int>,int);
    void coverPairs(vector<int>);
    int pairsCovered();
    int getTotalPairs();
    void resetPairs();
    bool checkExist(pair<int,int>);


};


