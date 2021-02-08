//
// Created by Andrew on 1/28/2021.
//

#include "PairMap.h"

PairMap::PairMap(vector<vector<int>> coverArray) {
    int currFactor = 0;
    for(const auto& fct:coverArray)
    {
        for(auto lvl:fct)
        {
            for(unsigned int pairFct = currFactor+1; pairFct < coverArray.size(); pairFct++)
            {
                for(int & pairLvl : coverArray.at(pairFct))
                {
                    pair<int,int> toEmp = make_pair(lvl,pairLvl);
                    coverMap.emplace(toEmp,false);
                }
            }
        }
        currFactor++;
    }

    copyMap = coverMap;
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
void PairMap::coverPairs(vector<int> candidate) {
    for(int i = 0; i < candidate.size()-1; i++)
    {
        for(int j = i; j < candidate.size(); j++)
        {
            pair<int,int> toCover = make_pair(candidate[i],candidate[j]);
            coverMap.erase(toCover);
        }
    }
}

int PairMap::getTotalPairs() {

    return coverMap.size();

}

int PairMap::countPairs(int pairVal) {
    int count = 0;
    for(it = coverMap.begin(); it != coverMap.end(); it++)
    {
        if((it->first.first == pairVal || it -> first.second == pairVal) && !it->second)
        {
            count++;
        }
    }
    return count;
}

int PairMap::countPairs(vector<int> candidate,int index) {
    int count = 0;
    for(int i = 0; i < index; i++)
    {
        pair<int,int> toFind = make_pair(candidate.at(i),candidate.at(index));
        if(coverMap.find(toFind) != coverMap.end())
            count++;

    }
    for(int i = index+1; i < candidate.size(); i++)
    {
        pair<int,int> toFind = make_pair(candidate.at(index),candidate.at(i));
        if(coverMap.find(toFind) != coverMap.end())
            count++;

    }

    return count;
}

int PairMap::pairsCovered() {
    int count = 0;
    for(it = coverMap.begin(); it != coverMap.end(); it++)
    {
        if(it->second)
        {
            count++;
        }
    }
    return count;
}

void PairMap::resetPairs() {
    coverMap = copyMap;
}

bool PairMap::checkExist(pair<int,int> p) {
    return coverMap.find(p) != coverMap.end();
}

