#include "matchmake.h"

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

bool compareMatches(MATCH &a, MATCH &b)
{
    int qualityA = -abs(a[0].second-a[1].second);
    int qualityB = -abs(b[0].second-b[1].second);

    return qualityA > qualityB;
}


bool comparePlayers(PLAYER p1, PLAYER p2)
{
    return p1.second > p2.second;
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
        if(i == 0) {
            cout << " vs ";
        } else {
            cout <<'\n';
        }
    }
}

void printMatches (vector< MATCH> &matches)
{
    calculateTotalScore(matches);
    sort(matches.begin(), matches.end(), compareMatches);
    for (auto match : matches) {
        printMatch(match);
    }
}

void makeTeams(	vector< TEAM> const &teams,
                vector< TEAM> &finalTeams,
                int m)
{
    TEAM team;
	makeTeamsUtil(teams, finalTeams, team, 0, teams.size()-1, 0, m);
}


void makeTeamsUtil (vector< TEAM> const &teams,
                    vector< TEAM> &finalTeams,
                    TEAM &team,
					int start, int end,
					int index, int m)
{
	if (index == m) {
        finalTeams.push_back(team);
	} else if (index > m) {
        return;
    }

	for (int i = start; i <= end &&
		end - i + 1 >= m - index; i++) {
		for (auto player : teams[i]) {
            team.push_back(player);
        }
		makeTeamsUtil(teams, finalTeams, team, i+1,
						end, index+(teams[i].size()), m);
        for (auto player : teams[i]) {
            team.erase(std::remove(team.begin(), team.end(), player), team.end());
        }
	}
}

int parseScore(string &str)
{
    return stoi(str);
}
