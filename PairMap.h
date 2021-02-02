//
// Created by Andrew on 1/28/2021.
//
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <regex>

using namespace std;


class PairMap {
private:
    map<pair<int,int>,bool> coverMap;
    map<pair<int,int>,bool>::iterator it;
    int factors;
    int levels;

public:
    PairMap(int,int);
    vector<pair<int,int>> findPairs(int);
    void coverPairs(vector<pair<int,int>>);


};


