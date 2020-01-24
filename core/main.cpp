#include "matchmake.h"

int main()
{

	int arr[] = {1, 2, 3, 4};
	int m = 2;

	int n = sizeof(arr)/sizeof(arr[0]);

    int numberOfTeams = nCr(n,m);
    teams = new int*[numberOfTeams];
    for(int i = 0; i < numberOfTeams; i++){
        teams[i] = new int[m];
    }

	startCombination(arr, n, m);
    printTeams(numberOfTeams, m);
}
