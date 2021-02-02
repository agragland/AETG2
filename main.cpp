//
// Created by Andrew on 1/28/2021.
//

#include "PairMap.h"


int main()
{
    vector<vector<int>> coveringArray;
    vector<string> toRegex;
    string coveringInput;
    int factors = 0;
    int levels = 0;
    int currFactor = 0;

    cout << "Input as follows - \"Levels^Factors\" - for as many factors and levels as desired: ";
    getline(cin, coveringInput);

    regex fctLvl ("(\\d+)\\^(\\d+)");
    smatch m;

    int lvlStep = 0;
    while(regex_search(coveringInput,m,fctLvl))
    {
        levels = stoi(m[1]);
        factors = stoi(m[2]);
        coveringArray.resize(factors+currFactor);

        for(int i = 0; i < factors; i++)
        {
            for(int j = 0; j < levels; j++)
            {
                coveringArray.at(currFactor).push_back(j+lvlStep);
            }
            currFactor++;
            lvlStep+=levels;
        }
        coveringInput = m.suffix().str();
    }


    PairMap coverMap(coveringArray);

    coverMap.printContents();

    //generating a candidate
    //randomize factor order
    //for the first factor, check which level can cover the most new pairs, store result into candidate data structure
    //for the next factors, check which level will cover the most pairs when
    // paired with the level of all previous factors, store result into candida

    //randomly order factors 2,1,4,3

    //[], [], [] ,[]
    //3,4,5 can cover upto 9 pairs - randomly choose 4
    //[], 4, [], []
    //0,4 1,4 and 2,4 each cover 1 pair, randomly choose 1
    //1, 4, [], []
    //(1,9 4,9) (1,10 4,10) (1,11 4,11) each cover 2 pairs - randomly choose 11
    //1, 4, [], 11
    //(1,6 4,6 6,11) (1,7 4,7 7,11) (1,8 4,8 8,11) each cover 3 pairs - randomly choose 8
    //1,4,8,11 <- candidate 1 - can cover 6 pairs

    //generate 49 more candidates, if another candidate can cover more pairs, replace

    //repeat until out of pairs - candidates generated


    //repeat 100 times



    //function to cover pairs takes a candidate and covers according to n, n-1, n-2, etc

    //functions to count pairs can take either single digit or candidate vector to count pairs associated with values
    //vector resize -1 system, find two positive nums in candidate, check if they are covered, if not move on horizontally
    //take old num and use it as first num


//    vector<pair<int,int>> pairList = coverMap.findPairs(3);
//
//    coverMap.coverPairs(pairList);
//
//    pairList = coverMap.findPairs(0);
//
//    coverMap.coverPairs(pairList);


    return 0;
}