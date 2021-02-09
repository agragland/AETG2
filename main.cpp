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

    unsigned seed = time(NULL);
    srand(seed);

    PairMap coverMap(coveringArray);

    vector<vector<vector<int>>> testSuites(100);

    for(int suite = 0; suite < 100; suite++)
    {
        cout << "Completion Progress: " << suite << "%" << endl;

        vector<vector<int>> testSuite;
        vector<int> candidate(coveringArray.size());
        vector<int> bestCandidate(coveringArray.size());
        vector<vector<int>> potentialCandidates;

        int bestTotal;
        int count;

        vector<int> factorOrder (coveringArray.size());
        for (int i = 0; i < coveringArray.size(); i++) {
            factorOrder[i] = i;
        }

        while (coverMap.getCovered() < coverMap.getTotalPairs()){

            bestTotal = -1;
            fill(bestCandidate.begin(),bestCandidate.end(), -1);



            for (int i = 0; i < 50; i++) {

                fill(candidate.begin(),candidate.end(), -1);
                //randomize the order of factors to find levels for

                shuffle(factorOrder.begin(), factorOrder.end(), default_random_engine(rand()));

                //looking at the first factor
                int runningTotal = 0;
                int bestCount = -1;
                int currentFactor = 0;
                vector<int> potentialLevels;

                for (auto it: coveringArray.at(factorOrder.at(currentFactor))) {
                    if ((count = coverMap.countPairs(it, factorOrder[currentFactor])) >= bestCount) {
                        bestCount = count;
                        potentialLevels.push_back(it);
                    }
                }

                //used for picking desired candidate
                unsigned int tieBreaker = rand() % potentialLevels.size();
                candidate.at(factorOrder.at(currentFactor)) = potentialLevels.at(tieBreaker);

                currentFactor++;
                //repeat with rest of the factors
                while (currentFactor < factorOrder.size()) {
                    bestCount = -1;
                    potentialLevels.clear();


                    for (auto it: coveringArray.at(factorOrder.at(currentFactor))) {
                        candidate.at(factorOrder.at(currentFactor)) = it;
                        if ((count = coverMap.countPairs(candidate,factorOrder[currentFactor])) >= bestCount) {
                            bestCount = count;
                            potentialLevels.push_back(it);
                        }
                    }

                    unsigned int tieBreaker = rand() % potentialLevels.size();
                    candidate.at(factorOrder.at(currentFactor)) = potentialLevels.at(tieBreaker);
                    runningTotal += bestCount;

                    currentFactor++;
                }

                if (runningTotal > bestTotal) {
                    potentialCandidates.clear();
                    potentialCandidates.push_back(candidate);
                    bestTotal = runningTotal;
                }

                else if(runningTotal == bestTotal)
                {
                    potentialCandidates.push_back(candidate);
                }
            }

            unsigned int tieBreaker = rand() % potentialCandidates.size();
            testSuite.push_back(potentialCandidates.at(tieBreaker));
            coverMap.coverPairs(potentialCandidates.at(tieBreaker));

        }

        testSuites[suite] = testSuite;
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