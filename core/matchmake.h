#ifndef MATCHMAKE_H
#define MATCHMAKE_H


extern int **teams;
extern int teamNumber;

#include<bits/stdc++.h>
using namespace std;

void makeTeams(vector<pair <string, int>> const &players,
                    vector <set <pair <string, int> > > &teams,
                    int m);
void makeTeamsUtil(vector<pair <string, int>>const &players,
                    vector <set <pair <string, int> > > &teams,
                    set <pair <string, int> > &team,
					int start, int end,
					int index, int m);

int nCr(int n, int r);
int fact(int n);

void printTeams(vector <set <pair <string, int> > > const &teams);
void printPlayers(vector<pair <string, int>> const &players);


#endif