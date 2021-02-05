//
// Created by Andrew on 1/28/2021.
//
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <random>
#include <vector>
#include <regex>
#include <ctime>

using namespace std;


class PairMap {
private:
    map<pair<int,int>,bool> coverMap;
    map<pair<int,int>,bool>::iterator it;
    int factors = 0;
    int levels = 0;

public:
    PairMap(vector<vector<int>> coverArray);
    vector<pair<int,int>> findPairs(int);
    int countPairs(int);
    int countPairs(vector<int>);
    void coverPairs(vector<int>);
    int pairsCovered();
    int getTotalPairs();
    void resetPairs();


};


