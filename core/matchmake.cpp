#include "matchmake.h"


int nCr(int n, int r)
{
    if (n<r || n < 0 || r < 0) {
        return 0;
    }
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
int fact(int n)
{
    if (n <= 1) {
        return 1;
    }
    return fact(n-1) * n;
}


void printPlayers(set< pair< string, int> > const &team)
{
    for (auto player : team){
        cout<< "Player Name: " << player.first << " | " << "Score: " << player.second << '\n';
    }
}

void printTeams(vector< set< pair< string, int> > > const &teams)
{
    for (auto team : teams) {
        cout << "New Team\n";
        printPlayers(team);
        cout << '\n';
    }
}

// The driver function
void makeTeams(vector< pair< string, int>> const &players,
                    vector< set< pair< string, int> > > &teams,
                    int m)
{
    set< pair< string, int> > team;
	makeTeamsUtil(players, teams, team, 0, players.size()-1, 0, m);
}


void makeTeamsUtil(vector< pair< string, int>>const &players,
                    vector< set< pair< string, int> > > &teams,
                    set< pair< string, int> > &team,
					int start, int end,
					int index, int m)
{
	if (index == m)
	{
        teams.push_back(team);
	}

	for (int i = start; i <= end &&
		end - i + 1 >= m - index; i++)
	{
		team.insert(players[i]);
		makeTeamsUtil(players, teams, team, i+1,
						end, index+1, m);
        team.erase(players[i]);
	}
}

