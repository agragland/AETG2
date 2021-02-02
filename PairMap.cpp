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

void PairMap::printContents() {

    cout << "Stored: " << coverMap.size() << " pairs.\n" << endl;

}

