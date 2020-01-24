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

bool comparator(pair <string, int> a, pair <string, int> b)
{
    return a.second < b.second;
}
int main()
{
    // collect inputs
    // int m;
    // cin >> m;
    // vector<pair <string, int>> players;
    // string str;
    // cin.ignore();
    // while (getline(cin, str))
    // {
    //     if (str.empty()) {
    //         break;
    //     }
    //     str = trim(str);

    //     // parse input
    //     int score = parseScore(str);
    //     string name = trim(parseName(str));
    //     pair <string, int> temp(name, score);
    //     players.push_back(temp);
    // }

    // sort(players.begin(),players.end(),comparator);

    // for (int i=0;i<players.size();i++){
    //     cout<< "Player Name: " << players[i].first << " | " << "Score: " << players[i].second << '\n';
    // }
    int n = players.size();

	int arr[] = {1, 2, 3, 4};

	int n = sizeof(arr)/sizeof(arr[0]);

    int numberOfTeams = nCr(n,m);
    teams = new int*[numberOfTeams];
    for(int i = 0; i < numberOfTeams; i++){
        teams[i] = new int[m];
    }

	startCombination(arr, n, m);
    printTeams(numberOfTeams, m);
}
