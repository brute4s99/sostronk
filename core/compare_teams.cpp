// A Simple C++ program to check if two sets are disjoint
#include<iostream>
#include<algorithm>
using namespace std;


bool operator<(PLAYER const &player1, PLAYER const &player2)
{
    return player1.second < player2.second;
}
bool compare(PLAYER const &player1, PLAYER const &player2)
{
    return player1.second < player2.second;
}
bool areDisjoint(TEAM &team1, TEAM &team2)
{
    int size = team1.size();

    sort(team1.begin(), team1.end(), compare);
    sort(team2.begin(), team2.end(), compare);

    // Check for same elements using merge like process
    int i = 0, j = 0;
    while (i < size && j < size)
    {
        if (team1[i] < team2[j]) {
            i++;
        } else if (team2[j] < team1[i]) {
            j++;
        } else {/* if team1[i] == team2[j] */
            return false;
        }
    }

    return true;
}