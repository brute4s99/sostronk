#include "matchmake.h"

bool compare_matches(MATCH &a, MATCH &b)
{
    int qualityA = -abs(a[0].second-a[1].second);
    int qualityB = -abs(b[0].second-b[1].second);

    return qualityA > qualityB;
}

void calculateTotalScore(vector< MATCH> &matches)
{
    for (auto &match : matches) {
        int size = ((match[0]).first).size();
        for (int i=0;i<2;i++) {
            match[i].second=0;
            for (int j=0;j<size; j++) {
                match[i].second += (match[i].first)[j].second;
            }
        }
    }
}

void printTeam (TEAM const &team)
{
    for (int i = 0; i < team.size(); i++) {
        cout<< team[i].first;
        if(i != team.size()-1) {
            cout << ',';
        }
    }
}

void printMatch (MATCH const &match)
{
    for (int i = 0; i < 2; i++) {
        printTeam(match[i].first);
        int size = (match[i].first).size();
        cout << " (" << float(match[i].second)/size << ')';
        if(i != size-1) {
            cout << " vs ";
        } else {
            cout <<'\n';
        }
    }
}

void printMatches (vector< MATCH> &matches)
{
    calculateTotalScore(matches);
    sort(matches.begin(), matches.end(), compare_matches);
    for (auto match : matches) {
        printMatch(match);
    }
}

// The driver function
void makeTeams (vector< PLAYER > const &players,
                vector< TEAM > &teams,
                int m)
{
    TEAM team;
	makeTeamsUtil(players, teams, team, 0, players.size()-1, 0, m);
}


void makeTeamsUtil (vector< PLAYER> const &players,
                    vector< TEAM> &teams,
                    TEAM &team,
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
		team.push_back(players[i]);
		makeTeamsUtil(players, teams, team, i+1,
						end, index+1, m);
        team.erase(std::remove(team.begin(), team.end(), players[i]), team.end());
        
	}
}

