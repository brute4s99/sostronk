#include "main.h"

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

void save_team(int data[], int m) 
{
    for (int i = 0; i < m; i++) {
        teams[teamNumber][i] = data[i];
    }
    teamNumber++;
}

void print_teams(int numberOfTeams, int m)
{
    for (int i = 0; i < numberOfTeams; i++) {
        for (int j = 0; j < m; j++) {
            cout << teams[i][j] << ' ';
        }
        cout << '\n';
    }
}

// Driver code
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

	printCombination(arr, n, m);
    print_teams(numberOfTeams, m);
}


// The driver function
void printCombination(int arr[], int n, int m)
{
	// A temporary array to store
	// all combination one by one
	int data[m];

	// Print all combination using
	// temporary array 'data[]'
	combinationUtil(arr, data, 0, n-1, 0, m);
}


/* arr[] ---> Input Array
data[] ---> Temporary array to
store current combination
start & end ---> Staring and
Ending indexes in arr[]
index ---> Current index in data[]
m ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[],
					int start, int end,
					int index, int m)
{
	// Current combination is ready to be printed; print it
	if (index == m)
	{
        save_team(data, m);
		// for (int j = 0; j < m; j++)
		// 	cout << data[j] << " ";
		// cout << endl;
		// return;
	}

	// replace index with all possible
	// elements. The condition "end-i+1 >= m-index"
	// makes sure that including one element
	// at index will make a combination with
	// remaining elements at remaining positions
	for (int i = start; i <= end &&
		end - i + 1 >= m - index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i+1,
						end, index+1, m);
	}
}

