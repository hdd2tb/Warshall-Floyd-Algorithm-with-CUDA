/*
calculate with Zero-Copy Memory
Zero-Copy Memoryを用いた実装
*/

#include "include/gpgpu.h"
#include "include/ZeroCopy.h"
#include "include/Elapsed.h"

int main(){
	int n, m;
	Elapsed timer;
	cin >> n >> m;
	const int N = n * n;
	dim3 grid(n/128, n, 1), block(128, 1, 1);
	ZeroCopy<int> zr(N);

	executeDummy();

	zr.setData();

	timer.start();

	for (int k = 0; k < n; ++k){
		WarshallFloyd <<< grid, block >>> (n, k, zr.getData());
		cudaDeviceSynchronize();	
	}

	timer.stop();

	timer.showElapsed();

	return 0;
}