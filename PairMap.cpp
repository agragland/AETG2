//
// Created by Andrew on 1/28/2021.
//

#include "PairMap.h"

PairMap::PairMap(int fct, int lvl) {
    factors = fct;
    levels = lvl;

    for(int i = 0; i < factors; i++)
    {
        for(int j = 0; j < levels; j++)
        {
            for(int k = levels*(i+1); k < factors*levels; k++)
            {
                pair<int,int> toEmp = make_pair(j+(levels*i),k);
                coverMap.emplace(toEmp,false);
            }
        }
    }
}

//Find all uncovered pairs that contain pairVal and store them in a vector
vector<pair<int,int>> PairMap::findPairs(int pairVal) {
    int count = 0;
    vector<pair<int,int>> toCover;
    for(it = coverMap.begin(); it != coverMap.end(); it++)
    {
        if((it->first.first == pairVal || it -> first.second == pairVal) && !it->second)
        {
            count++;
            toCover.push_back(it->first);
        }
    }
    return toCover;
}

//Cover all pairs that are in this vector
void PairMap::coverPairs(vector<pair<int, int>> toCover) {
    for(int i = 0; i < toCover.size(); i++)
    {
        coverMap.at(toCover.at(i)) = true;
    }
}

