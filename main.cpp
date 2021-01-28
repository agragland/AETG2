//
// Created by Andrew on 1/28/2021.
//

#include "PairMap.h"


int main()
{
    int factors;
    int levels;

    cout << "Input number of factors:" << endl;
    cin >> factors;
    cout << "Input number of levels:" << endl;
    cin >> levels;

    PairMap coverMap(factors,levels);

    vector<pair<int,int>> pairList = coverMap.findPairs(3);

    coverMap.coverPairs(pairList);

    pairList = coverMap.findPairs(0);

    coverMap.coverPairs(pairList);


    return 0;
}