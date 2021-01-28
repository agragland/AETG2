//
// Created by Andrew on 1/28/2021.
//

#include "PairMap.h"

map<pair<int,int>,bool> coverMap;
map<pair<int,int>,bool>::iterator it;

int main()
{
   // PairMap coverMap;

    int factors;
    int levels;

    cout << "Input number of factors:" << endl;
    cin >> factors;
    cout << "Input number of levels:" << endl;
    cin >> levels;

    for(int i = 0; i < factors; i++)
    {
        for(int j = 0; j < levels; j++)
        {
            for(int k = levels*(i+1); k < factors*levels; k++)
            {
                pair<int,int> toEmp = make_pair(j+(levels*i),k);
                coverMap.emplace(toEmp,false);
                //j+(levels*i) and k
            }
        }
    }

    //count all pairs that contain 3 -- CONVERT INTO FUNCTION!!!!
    int count = 0;
    vector<pair<int,int>> toCover;
    for(it = coverMap.begin(); it != coverMap.end(); it++)
    {
        if((it->first.first == 0 || it -> first.second == 0) && !it->second)
        {
            count++;
            toCover.push_back(it->first);
        }
    }
    cout <<  count << " pairs contain 9" << endl;

    cout << "covering all pairs that contain 0" << endl;

    //CONVERT INTO FUNCTION
    for(int i = 0; i < toCover.size(); i++)
    {
        coverMap.at(toCover.at(i)) = true;
    }


    return 0;
}