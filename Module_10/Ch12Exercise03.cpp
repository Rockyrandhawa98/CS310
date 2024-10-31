#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


using std::cout;
using std::cin;

using std::endl;
using std::setw;
using std::fixed;
using std::setprecision;
using std::left;

using std::string;
using std::set;
using std::vector;


bool isUnique(string candidateName, set<string> duplicateChecker);
vector<string> determineWinners(string *pCandidates, int *pVotes, int numberOfCandidates);
void printResults(vector<string> Winners, string *pCandidates, int *pVotes, int numberOfCandidates, int totalVotes);


int main() { 
    int numberOfCandidates;
    cout << "Enter the number of candidates: " << endl;
    cin >> numberOfCandidates;

    // two pointers
    string *pCandidates;
    int *pVotes;

    // assigning the pointers to point to the memory addresses of new arrays of size numberOfCandidates
    pCandidates = new string[numberOfCandidates];
    pVotes = new int[numberOfCandidates];

    // set data structure used to check if there are duplicates, variables declared to use in the For loop below
    set<string> duplicateChecker;
    string candidateName;
    int numberOfVotes = 0;
    int totalVotes = 0;

    // iterate over range(numberOfCandidates) to populate arrays in memory, adding to the set as we go
    for (int i = 0; i < numberOfCandidates; i++) {
        cout << "\nEnter the name of candidate " << i+1 << ": " << endl;
        cin >> candidateName;

        if (isUnique(candidateName, duplicateChecker)) {
            duplicateChecker.insert(candidateName);
            pCandidates[i] = candidateName;

            cout << "Enter the number of votes they received: " << endl;
            cin >> numberOfVotes;
            pVotes[i] = numberOfVotes;
            totalVotes += numberOfVotes;
        }
        else {
            cout << "\nError: duplicate candidate name entered, terminating program. " << endl;
            return 0;
        }

    }

    // determine and output winners
    vector<string> Winners = determineWinners(pCandidates, pVotes, numberOfCandidates);
    printResults(Winners, pCandidates, pVotes, numberOfCandidates, totalVotes);

    // clean up allocated memory
    delete [] pCandidates;
    delete [] pVotes;
    pCandidates = nullptr;
    pVotes = nullptr;

    return 0;

}


// uses a set for O(1) lookups. source: https://stackoverflow.com/questions/1701067/how-to-check-that-an-element-is-in-a-stdset
bool isUnique(string candidateName, set<string> duplicateChecker) {
    if (duplicateChecker.count(candidateName) == 1) {
        return false;
    }
    else {
        return true;
    }
}

vector<string> determineWinners(string *pCandidates, int *pVotes, int numberOfCandidates) {
    vector<string> Winners;
    int highestVote = 0;

    for (int i = 0; i < numberOfCandidates; i++) {
        if (pVotes[i] > highestVote) {
            while (Winners.size() > 0) {
                Winners.pop_back();
            }
            highestVote = pVotes[i];
            Winners.push_back(pCandidates[i]);
        }
        else if (pVotes[i] == highestVote) {
            Winners.push_back(pCandidates[i]);
        }
    }
    return Winners;
}

void printResults(vector<string> Winners, string *pCandidates, int *pVotes, int numberOfCandidates, int totalVotes) {

    cout << "---------------------------------------------------------------------------" << endl;
    cout << setw(25) << left << "Candidate";
    cout << setw(25) << left << "Votes Received";
    cout << setw(25) << left << "Percentage of Total Votes" << endl;

    for (int i = 0; i < numberOfCandidates; i++) {
        float percentageOfVotes = static_cast<float>(pVotes[i]) / totalVotes * 100;

        cout << setw(25) << left << pCandidates[i];
        cout << setw(25) << left << pVotes[i];
        cout << setw(25) << left << setprecision(2) << fixed << percentageOfVotes << endl;
    }

    cout << setw(25) << left << "Total";
    cout << setw(25) << left << setprecision(0) << fixed << totalVotes << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << " " << endl;

    // Check to see if there was a tie or not
    if (Winners.size() == 1) {
        cout << "The winner of the Election is " << Winners[0] << "." << endl;
    }
    else {
        cout << "There was a tie in this Election between these candidates: " << endl;
        for (int i = 0; i < Winners.size(); i++) {
            cout << Winners[i] << endl;
        }
    }
    cout << " " << endl;
}