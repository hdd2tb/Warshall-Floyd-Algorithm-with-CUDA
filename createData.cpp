/*
create adjacency matrix
隣接行列を生成する. 
頂点数2**nとなる整数nを与える. 
辺数mは適宜変更する. 
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <math.h>
#define INF 200000000
using namespace std;
typedef vector<vector<int> > Matrix;
Matrix d;

void createData(int n, int m){
	srand((unsigned int)time(NULL));
	for (int i = 0; i < m; i++){
		int from, to;
		while (true){
			from = rand() % n;
			to = rand() % n;
			if (from != to && d[from][to] == INF && d[from][to] > 100)
				break;
		}
		d[from][to] = rand() % 100 + 1;
	}
}

void initArray(int n){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
}

void showArray(int n){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << setw(10) << d[i][j] << " ";
			if (j == n - 1) cout << endl;
		}
}

int main(){
	int n, m;
	//n: 2**n
	cin >> n;
	n = pow(2, n);
	m = n * (n - 1);

	d = Matrix(n, vector<int>(n, INF));
 	for (int i = 0; i < n; i++) d[i][i] = 0;

	initArray(n);
	createData(n, m);

	cout << n << " " << m << endl;
  	for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        cout << setw(10) << d[i][j] << " ";
        if (j == n - 1) cout << endl;
    }
	
	//showArray(n);

	return 0;
}