#include "matchmake.h"
#include "trimmer.h"
#include "compare_teams.h"
#include <sstream>

int main()
{
    // collect inputs
    int m;
    cin >> m; // team size
    vector< TEAM> teams;
    string str;
    cin.ignore();
    while (getline(cin, str))
    {
        if (str.empty()) {
            break;
        }
        TEAM tempTeam;
        str = trim(str);

        // parse input
        string playerName, scoreString;
        stringstream s(str);
        while (s >> playerName && s >> scoreString) {
            string name = trim(playerName);
            int score = parseScore(scoreString);
            PLAYER tempPlayer(name, score);
            tempTeam.push_back(tempPlayer);
        }
        teams.push_back(tempTeam);
    }

    vector< TEAM> finalTeams;
    makeTeams(teams, finalTeams, m);

    int numberOfTeams = finalTeams.size();

    vector< MATCH> matches;
    for (int i = 0; i < numberOfTeams-1; i++) {
        for (int j = i+1; j < numberOfTeams; j++) {
            if(areDisjoint(finalTeams[i], finalTeams[j])) {
                MATCH match;
                match[0].first = finalTeams[i];
                match[1].first = finalTeams[j];
                matches.push_back(match);
            }
        }
    }
    printMatches(matches);
}
