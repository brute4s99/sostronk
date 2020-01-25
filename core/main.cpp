#include "matchmake.h"
#include "trimmer.cpp"
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
    vector<pair< string, int> > players;
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
        pair< string, int> temp(name, score);
        players.push_back(temp);
    }
    int numberOfPlayers = players.size();

    // sort(players.begin(),players.end(),comparator);
    // printPlayers(players);

    vector< set< pair< string, int> > > teams;
    // int numberOfTeams = nCr(n,m);
    // teams.resize(numberOfTeams);
	makeTeams(players, teams, m);
    // printTeams(teams);
}
