//
// Created by Andrew on 1/28/2021.
//

#include <random>

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
    cout << endl;
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

    vector<vector<vector<int>>> testSuites;

    for(int suite = 0; suite < 100; suite++)
    {
        cout << "Completion Progress: " << suite << "%\r";
        //generating a candidate
        vector<vector<int>> testSuite;
        vector<int> candidate;
        vector<int> bestCandidate;
        int bestCandidateCount = 0;


        while (coverMap.pairsCovered() < coverMap.getTotalPairs()) {

            for (int i = 0; i < 50; i++) {

                candidate.resize(coveringArray.size(), -1);          //set all value within candidate to -1
                bestCandidate.resize(coveringArray.size(), -1);
                //randomize the order of factors to find levels for
                unsigned seed = time(NULL);
                vector<int> factorOrder;
                for (int i = 0; i < coveringArray.size(); i++) {
                    factorOrder.push_back(i);
                }
                shuffle(factorOrder.begin(), factorOrder.end(), default_random_engine(seed));


                //looking at the first factor
                int bestCount = -1;
                int bestLevel = -1;
                int factorCount = 1;
                vector<int> potentialLevels;

                for (auto it: coveringArray.at(factorOrder.at(0))) {
                    if (coverMap.countPairs(it) >= bestCount) {
                        bestCount = coverMap.countPairs(it);
                        bestLevel = it;
                        potentialLevels.push_back(it);
                    }
                }
                if (potentialLevels.size() == 1) {
                    candidate.at(factorOrder.at(0)) = potentialLevels.at(0);
                } else {
                    //break a tie
                    random_device tieSeed;
                    mt19937 gen(tieSeed());
                    uniform_int_distribution<> distr(0,potentialLevels.size());
                    unsigned int tieBreaker = distr(gen);
                    candidate.at(factorOrder.at(0)) = potentialLevels.at(tieBreaker);
                }

                //repeat with rest of the factors
                while (factorCount < factorOrder.size()) {
                    bestCount = -1;
                    potentialLevels.clear();

                    for (auto it: coveringArray.at(factorOrder.at(factorCount))) {
                        candidate.at(factorOrder.at(factorCount)) = it;
                        if (coverMap.countPairs(candidate) >= bestCount) {
                            bestCount = coverMap.countPairs(candidate);
                            bestLevel = it;
                            potentialLevels.push_back(it);
                        }
                    }
                    if (potentialLevels.size() == 1) {
                        candidate.at(factorOrder.at(factorCount)) = potentialLevels.at(0);
                    } else {
                        //break a tie
                        random_device tieSeed;
                        mt19937 gen(tieSeed());
                        uniform_int_distribution<> distr(0,potentialLevels.size());
                        unsigned int tieBreaker = distr(gen);
                        candidate.at(factorOrder.at(factorCount)) = potentialLevels.at(tieBreaker);
                    }

                    factorCount++;
                }

                if (coverMap.countPairs(candidate) > coverMap.countPairs(bestCandidate)) {
                    bestCandidate = candidate;
                }
            }

            coverMap.coverPairs(bestCandidate);
            testSuite.push_back(bestCandidate);
            candidate.clear();
            bestCandidate.clear();
        }

        testSuites.push_back(testSuite);
        coverMap.resetPairs();
    }

    int lowest = testSuites.at(0).size();
    int highest = 0;
    int average = 0;
    int sum = 0;

    for(auto t:testSuites)
    {
        if(t.size() > highest)
        {
            highest = t.size();
        }
        if(t.size() < lowest)
        {
            lowest = t.size();
        }
        sum += t.size();
    }

    average = sum/100;

    cout << "Results: " << endl;
    cout << "Lowest mAETG: " << lowest << endl;
    cout << "Highest mAETG: " << highest << endl;
    cout << "Average mAETG: " << average << endl;

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