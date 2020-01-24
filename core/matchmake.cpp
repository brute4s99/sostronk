#include "matchmake.h"

int **teams;
int teamNumber = 0;

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

void saveTeam(int data[], int m) 
{
    for (int i = 0; i < m; i++) {
        teams[teamNumber][i] = data[i];
    }
    teamNumber++;
}

void printTeams(int numberOfTeams, int m)
{
    for (int i = 0; i < numberOfTeams; i++) {
        for (int j = 0; j < m; j++) {
            cout << teams[i][j] << ' ';
        }
        cout << '\n';
    }
}

// The driver function
void startCombination(int arr[], int n, int m)
{
	int data[m];

	combinationUtil(arr, data, 0, n-1, 0, m);
}


void combinationUtil(int arr[], int data[],
					int start, int end,
					int index, int m)
{
	if (index == m)
	{
        saveTeam(data, m);
	}

	for (int i = start; i <= end &&
		end - i + 1 >= m - index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i+1,
						end, index+1, m);
	}
}

