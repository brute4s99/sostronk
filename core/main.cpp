#include "matchmake.h"
#include "trimmer.h"
#include "compare_teams.h"
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    // collect inputs
    int m;
    cin >> m;
    vector< PLAYER> players;
    string str;
    cin.ignore();
    while (getline(cin, str))
    {
        if (str.empty()) {
            break;
        }
        str = trim(str);

        // parse input
        int score = parseScore(str);
        string name = trim(parseName(str));
        PLAYER temp(name, score);
        players.push_back(temp);
    }
    int numberOfPlayers = players.size();

    // sort(players.begin(),players.end(),comparator);
    // printPlayers(players);

    vector< TEAM> teams;
    makeTeams(players, teams, m);
    int numberOfTeams = teams.size();
    // printTeams(teams);

    vector< MATCH> matches;
    for (int i = 0; i < numberOfTeams-1; i++) {
        for (int j = i+1; j < numberOfTeams; j++) {
            if(areDisjoint(teams[i], teams[j])) {
                MATCH match;
                match[0].first = teams[i];
                match[1].first = teams[j];
                matches.push_back(match);
            }
        }
    }
    printMatches(matches);
}
