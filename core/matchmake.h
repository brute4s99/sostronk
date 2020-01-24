#ifndef MATCHMAKE_H
#define MATCHMAKE_H


extern int **teams;
extern int teamNumber;

#include<bits/stdc++.h>
using namespace std;

void startCombination(int arr[], int n, int m);
void combinationUtil(int arr[], int data[],
					int start, int end,
					int index, int m);
int nCr(int n, int r);
int fact(int n);

void printTeams(int numberOfTeams, int m);
void save_team(int i, int m);

#endif