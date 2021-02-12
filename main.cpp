//CSCE 3444 - ATEG Algorithm - Main File - Andrew Ragland

#include "PairSet.h"


int main()
{
    vector<vector<int>> coveringArray;
    vector<string> toRegex;
    string coveringInput;

    //Take input from user for creating covering array of all values - supports multilevel factors through regex
    cout << "Input as follows - \"#Levels^#Factors\" - put a space between each for multi-level covering:";
    getline(cin, coveringInput);
    cout << endl;
    regex fctLvl ("(\\d+)\\^(\\d+)");
    smatch m;

    //Generate vector of vector of int to add each level to its factor for as many different levels/factors specified
    int lvlStep = 0;
    int inputFactor = 0;
    while(regex_search(coveringInput,m,fctLvl))
    {
        int levels = stoi(m[1]);
        int factors = stoi(m[2]);
        coveringArray.resize(factors+inputFactor);

        for(int i = 0; i < factors; i++)
        {
            for(int j = 0; j < levels; j++)
            {
                coveringArray.at(inputFactor).push_back(j+lvlStep);
            }
            inputFactor++;
            lvlStep+=levels;
        }
        coveringInput = m.suffix().str();
    }

    clock_t start, end;
    unsigned seed = time(NULL);
    srand(seed);

    PairSet coverMap(coveringArray); //Declare PairSet object

    vector<vector<vector<int>>> testSuites(100); //Instantiate vector to store all test suites

    //Set up factor randomization
    vector<int> factorOrder (coveringArray.size());
    for (int i = 0; i < coveringArray.size(); i++) {
        factorOrder[i] = i;
    }

    //Begin timer and generate 100 test suites
    start = clock();
    for(int suite = 0; suite < 100; suite++)
    {
        //Instantiate a test suite, a candidate, and the best candidate
        vector<vector<int>> testSuite;
        vector<int> candidate(coveringArray.size());
        vector<int> bestCandidate(coveringArray.size());

        //Used to store the values for which candidate can cover the most pairs
        int bestTotal;
        int count;

        //Generate a test suite
        while (coverMap.getCovered() < coverMap.getTotalPairs()){

            bestTotal = -1;

            //Generate 50 candidates
            for (int i = 0; i < 50; i++) {

                fill(candidate.begin(),candidate.end(), -1);

                //Randomize the order of factors to choose from
                shuffle(factorOrder.begin(), factorOrder.end(), default_random_engine(rand()));

                vector<int> potentialLevels; //Store the levels that can cover the most
                int runningTotal = 0; //Store the number of pairs the current candidate can cover
                int bestCount = -1; //Store the number of pairs the best level can cover
                int currentFactor = 0; //The current factor

                //The first factor
                for (auto it: coveringArray[factorOrder[currentFactor]]) {
                    if ((count = coverMap.countPairs(it,factorOrder[currentFactor])) > bestCount) {
                        bestCount = count;
                        potentialLevels.clear();
                        potentialLevels.push_back(it);
                    }
                    else if(count == bestCount)
                    {
                        potentialLevels.push_back(it);
                    }
                }

                //Break a tie if there is more than one level that can cover the most pairs
                unsigned int tieBreaker = rand() % potentialLevels.size();
                candidate[factorOrder[currentFactor]] = potentialLevels[tieBreaker];

                currentFactor++;

                //Repeat with rest of the factors
                while (currentFactor < factorOrder.size()) {
                    bestCount = -1;
                    potentialLevels.clear();

                    for (auto it: coveringArray[factorOrder[currentFactor]]) {
                        candidate[factorOrder[currentFactor]] = it;
                        if ((count = coverMap.countPairs(candidate,factorOrder[currentFactor])) > bestCount) {
                            bestCount = count;
                            potentialLevels.clear();
                            potentialLevels.push_back(it);
                        }
                        else if(count == bestCount)
                        {
                            potentialLevels.push_back(it);
                        }
                    }

                    //Break a tie if there is more than one level that can cover the most pairs
                    tieBreaker = rand() % potentialLevels.size();
                    candidate.at(factorOrder.at(currentFactor)) = potentialLevels.at(tieBreaker);
                    runningTotal += bestCount;

                    currentFactor++;
                }

                //Check if our current candidate can cover more than the best candidate
                if(runningTotal >= bestTotal)
                {
                    bestTotal = runningTotal;
                    bestCandidate = candidate;
                }
            }

            //Store the best candidate in the test suite and cover the pairs
            testSuite.push_back(bestCandidate);
            coverMap.coverPairs(bestCandidate);

        }

        //Once the test suite is finished being generated, add it to the larger vector and reset for another test
        testSuites[suite] = testSuite;
        coverMap.resetPairs();
    }
    end = clock();


    vector<vector<int>> lowestSuite = testSuites[0]; //Store the test suite which has the least candidates
    int lowest = testSuites[0].size(); //Store the value of the least number of candidates
    int highest = 0; //Store the value of the largest number of candidates
    int average; //Store the average test suite candidate value
    double avgTime = (((double) (end-start))/CLOCKS_PER_SEC)/100; //Calculate the average execution time

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
            lowestSuite = t;
        }
        sum += t.size();
    }

    average = sum/100;

    cout << "Results: " << endl;
    cout << "Lowest AETG: " << lowest << endl;
    cout << "Highest AETG: " << highest << endl;
    cout << "Average AETG: " << average << endl;
    cout << "Average Execution Time: " << avgTime << " seconds" <<  endl;

    //Send test suite with lowest candidates to output file
    ofstream output;
    output.open("aetg_output.txt");
    output << lowestSuite.size() << "\n\n";
    for(auto c: lowestSuite)
    {
        for(auto f:c)
        {
            output << f << " ";
        }
        output << "\n";
    }
    output.close();

    //Tell the user where the output is stored
    cout << "\nBest test suite output is stored in \'aetg_output.txt\'" << endl;

    return 0;
}