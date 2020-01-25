#include "matchmake.h"
#include "trimmer.cpp"
#include "compare_teams.cpp"
#include<bits/stdc++.h>
#include<string>
using namespace std;

string convertToString(char* a)
{
    int i;
    string s = "";
    for (i = 0; a[i] != '\0'; i++) {
        s = s + a[i];
    }
    return s;
}

int parseScore(string &str)
{
    int i = 1;
    while(str[str.length()-i] != ' ') {
        i++;
    }
    return stoi(str.substr(str.length()-i));

}

string parseName(string str)
{
    int i = 1;
    while(str[str.length()-i] != ' ') {
        i++;
    }
    return str.substr(0, str.length()-i);
}

bool comparator(pair< string, int> a, pair< string, int> b)
{
    return a.second > b.second;
}
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
