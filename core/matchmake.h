#ifndef MATCHMAKE_H
#define MATCHMAKE_H

#include<bits/stdc++.h>
using namespace std;

typedef pair< string, int>			PLAYER;
typedef vector< PLAYER>     		TEAM;
typedef array< pair< TEAM, int>, 2>	MATCH;


void makeTeams(	vector< PLAYER > const &players,
                vector< TEAM > &teams,
                int m);
void makeTeamsUtil(	vector< PLAYER> const &players,
                    vector< TEAM> &teams,
                    TEAM &team,
					int start, int end,
					int index, int m);

void printTeam		(TEAM 					const 	&team);
void printMatch		(MATCH 					const 	&match);
void printMatches (vector< MATCH> &matches);

#endif