/*
calculate with ArrayFire
ArrayFireを用いた実装
*/

#include <arrayfire.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iomanip>

#define INF 200000000
using namespace af;
using namespace std;

template <class T>
void inputData(T *d, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> d[j*n + i];
		}
	}
}

template <class T>
void initArray(T *d){
	fill(h, h + n*n, INF);
	for (int i = 0; i < n; ++i){
		h[i*n + i] = 0;
	}
}

int main()
{
	// Select a device and display arrayfire info
	int device = argc > 1 ? atoi(argv[1]) : 0;
	setDevice(device);
	info();

	int n, m;
	cin >> n >> m;
	int *h = new int[n*n];
	
	//initArray(d);
	inputData(h, n);
			
	double elapsed;
	array A(n, n, h);

	timer::start();
		
	for (int k = 0; k < n; k++)
		gfor(seq i, n)
			A(span, span) = min(A(span, span), A(span, k) + A(k, span));
	
	elapsed = timer::stop();
	cout << "calc time: " << fixed << setprecision(5) << elapsed*1000.0 << " ms " << endl;
		
	delete[] h;
	
	return 0;
}