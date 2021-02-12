//CSCE 3444 - ATEG Algorithm - PairSet Functions - Andrew Ragland

#include "PairSet.h"

PairSet::PairSet(vector<vector<int>> coverArray) {

    coveringArray = move(coverArray); //Store the coveringArray from main within this class

    int currFactor = 0;
    for(auto fct:coveringArray) //Loop through each factor
    {
        for (auto lvl:fct) //Loop through each level for each factor
        {
            for (unsigned int pairFct = currFactor + 1; pairFct < coveringArray.size(); pairFct++) //Loop through each factor - starting one factor ahead
            {
                for (int pairLvl : coveringArray[pairFct])  //Loop through levels for each ahead factor
                {
                    //Create a pair and and store it in the set
                    pair<int, int> toEmp = make_pair(lvl, pairLvl);
                    coverSet.emplace(toEmp);
                }
            }
        }
        currFactor++;
    }

    //Make a copy of the newly generated PairSet and store its size
    copySet = coverSet;
    totalPairs = coverSet.size();
}

int PairSet::countPairs(int pairVal, int index) {
    int count = 0;

    //Loop that looks to the left of the given factor (index)
    for(int i = 0; i < index; i++)
    {
        for(auto it: coveringArray[i])
        {
            //Count all pairs that the single value can make
            pair<int,int> toFind = make_pair(it,pairVal);
            if(coverSet.find(toFind) != coverSet.end())
            {
                count++;
            }
        }
    }

    //Loop that looks to the right of the given factor (index)
    for(int i = index; i < coveringArray.size(); i++)
    {
        for(auto it: coveringArray[i])
        {
            //Count all pairs that the single value can make
            pair<int,int> toFind = make_pair(pairVal,it);
            if(coverSet.find(toFind) != coverSet.end())
            {
                count++;
            }
        }
    }
    return count;
}

int PairSet::countPairs(vector<int> candidate, int index) {
    int count = 0;

    //Loop that looks to the left of the given factor (index)
    for(int i = 0; i < index; i++)
    {
        //Check the set for a pair made out of each value in candidate compared with the given factor (0,4) -> (1,4) -> (2,4) ...
        pair<int,int> toFind = make_pair(candidate[i],candidate[index]);
        if(coverSet.find(toFind) != coverSet.end())
            count++;

    }

    //Loop that looks to the right of the given factor (index)
    for(int i = index+1; i < candidate.size(); i++)
    {
        //Check the set for a pair made out of each value in candidate compared with the given factor (4,6) -> (4,7) -> (4,8) ...
        pair<int,int> toFind = make_pair(candidate[index],candidate[i]);
        if(coverSet.find(toFind) != coverSet.end())
            count++;

    }
    return count;
}

void PairSet::coverPairs(vector<int> candidate) {

    //Loop through each pair of values within a completed candidate and remove existing pairs from set - increment covered
    for(unsigned int i = 0; i < candidate.size()-1; i++)
    {
        for(unsigned int j = i+1; j < candidate.size(); j++)
        {
            pair<int,int> toCover = make_pair(candidate[i],candidate[j]);
            if(coverSet.erase(toCover))
                covered++;
        }
    }
}

int PairSet::getCovered()
{
    return covered;
}

int PairSet::getTotalPairs() {

    return totalPairs;
}

void PairSet::resetPairs() {
    covered = 0;
    coverSet = copySet;
}



