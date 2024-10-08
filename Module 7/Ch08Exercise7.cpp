#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

// Source for vector documentation: https://www.geeksforgeeks.org/vectorpush_back-vectorpop_back-c-stl/

using namespace std;

int main() {

    const int Number_of_Candidates = 5;

    // Initializing arrays of size Number_of_Candidates
    string Candidates[Number_of_Candidates];
    int Votes[Number_of_Candidates];

    // variables used in the for-loop below
    string Candidate_Name;
    float Votes_Received;
    float Total_Votes = 0;


    // Filling out the Candidates and Votes arrays simultaneously to make them parallel
    for (int i = 0; i < Number_of_Candidates; i++) {
        cout << "Enter the name of candidate " << i+1 << ": " << endl;
        cin >> Candidate_Name;
        Candidates[i] = Candidate_Name;

        cout << "How many votes did this candidate receive? " << endl;
        cin >> Votes_Received;
        Votes[i] = Votes_Received;
        Total_Votes += Votes[i];
    }


    // Finding the Highest Vote and the corresponding index, Winners vector is used to keep track of ties
    float Highest_Vote = 0;
    int Highest_Vote_Index;
    vector<string> Winners {};

    for (int i = 0; i < Number_of_Candidates; i++) {
        if (Votes[i] > Highest_Vote) {
            // Clearing Winners vector of candidates with lesser votes
            while (Winners.size() > 0) {
                Winners.pop_back();
            }
            Highest_Vote_Index = i;
            Highest_Vote = Votes[i];
            Winners.push_back(Candidates[i]);
        }
        else if (Votes[i] == Highest_Vote) {
            Winners.push_back(Candidates[i]);
        }
    }


    // Outputting Results
    string Winner = Candidates[Highest_Vote_Index];
    float Percentage_of_Votes;

    cout << " " << endl;
    cout << setw(25) << left << "Candidate";
    cout << setw(25) << left << "Votes Received";
    cout << setw(25) << left << "Percentage of Total Votes" << endl;

    for (int i = 0; i < Number_of_Candidates; i++) {
        Percentage_of_Votes = 100 * (Votes[i] / Total_Votes);

        cout << setw(25) << left << Candidates[i];
        cout << setw(25) << left << Votes[i];
        cout << setw(25) << left << setprecision(2) << fixed << Percentage_of_Votes << endl;
    }

    cout << setw(25) << left << "Total";
    cout << setw(25) << left << setprecision(0) << fixed << Total_Votes << endl;
    cout << " " << endl;


    // Check to see if there was a tie or not
    if (Winners.size() == 1) {
        cout << "The winner of the Election is " << Winner << "." << endl;
    }
    else {
        cout << "There was a tie in this Election between these candidates: " << endl;
        for (int i = 0; i < Winners.size(); i++) {
            cout << Winners[i] << endl;
        }
    }

    cout << " " << endl;
    return 0;
}