#include<bits/stdc++.h>
using namespace std;

void combinationUtil(int arr[], int data[],
					int start, int end,
					int index, int m);
int fact(int n);
void save_team(int i, int m);
void printCombination(int arr[], int n, int m);
int **teams;
int teamNumber = 0;