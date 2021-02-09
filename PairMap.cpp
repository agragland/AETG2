//
// Created by Andrew on 1/28/2021.
//

#include "PairMap.h"

PairMap::PairMap(vector<vector<int>> coverArray) {
    coveringArray = coverArray;
    int currFactor = 0;
    for(const auto& fct:coveringArray) {
        for (auto lvl:fct) {
            for (unsigned int pairFct = currFactor + 1; pairFct < coveringArray.size(); pairFct++) {
                for (int &pairLvl : coveringArray.at(pairFct)) {
                    pair<int, int> toEmp = make_pair(lvl, pairLvl);
                    coverMap.emplace(toEmp, false);
                }
            }
        }
        currFactor++;
    }
    copyMap = coverMap;
    totalPairs = coverMap.size();
}

void PairMap::coverPairs(vector<int> candidate) {
    for(int i = 0; i < candidate.size()-1; i++)
    {
        for(int j = i+1; j < candidate.size(); j++)
        {
            pair<int,int> toCover = make_pair(candidate[i],candidate[j]);
            if(coverMap.erase(toCover))
                covered++;
        }
    }
}

int PairMap::getTotalPairs() {

    return totalPairs;

}

int PairMap::getCovered()
{
    return covered;
}

int PairMap::countPairs(int pairVal, int index) {
    int count = 0;
    for(int i = 0; i < index; i++)
    {
        for(auto it: coveringArray.at(i))
        {
            pair<int,int> toFind = make_pair(it,pairVal);
            if(coverMap.find(toFind) != coverMap.end())
            {
                count++;
            }
        }
    }
    for(int i = index; i < coveringArray.size(); i++)
    {
        for(auto it: coveringArray.at(i))
        {
            pair<int,int> toFind = make_pair(pairVal,it);
            if(coverMap.find(toFind) != coverMap.end())
            {
                count++;
            }
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

void PairMap::resetPairs() {
    covered = 0;
    coverMap = copyMap;
}



