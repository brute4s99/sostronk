#ifndef MATCHMAKE_H
#define MATCHMAKE_H

#include<bits/stdc++.h>
using namespace std;

typedef pair< string, int>			PLAYER;
typedef vector< PLAYER>     		TEAM;
typedef array< pair< TEAM, int>, 2>	MATCH;
// The two pairs of MATCH contain one TEAM and an integer (each) to store the total score of the team.

void makeTeams(	vector< PLAYER > const &players,
                vector< TEAM > &teams,
                int m);
void makeTeamsUtil(	vector< PLAYER> const &players,
                    vector< TEAM> &teams,
                    TEAM &team,
					int start, int end,
					int index, int m);

void calculateTotalScore(vector< MATCH> &matches);
bool compareMatches(MATCH &a, MATCH &b);
string convertToString(char* a);
int parseScore(string &str);
string parseName(string str);


void printTeam		(TEAM 					const 	&team);
void printMatch		(MATCH 					const 	&match);
void printMatches (vector< MATCH> &matches);

#endif