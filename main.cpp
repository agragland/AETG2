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

//    cout << "Input number of factors:" << endl;
    cin >> factors;
//    cout << "Input number of levels:" << endl;
  cin >> levels;

    PairMap coverMap(factors,levels);

    vector<pair<int,int>> pairList = coverMap.findPairs(3);

    coverMap.coverPairs(pairList);

    pairList = coverMap.findPairs(0);

    coverMap.coverPairs(pairList);


    return 0;
}