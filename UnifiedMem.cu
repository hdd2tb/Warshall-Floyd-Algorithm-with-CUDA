//calculate with Unified Memory

#include "include/gpgpu.h"
#include "include/Unified.h"
#include "include/Elapsed.h"

int main(){
	int n, m;
	Elapsed timer;
	cin >> n >> m;
	const int N = n * n;
	dim3 grid(n/128, n, 1), block(128, 1, 1);
	Unified<int> uni(N);

	executeDummy();

	uni.setData();

	timer.start();

	for (int k = 0; k < n; ++k)
		WarshallFloyd <<< grid, block >>> (n, k, uni.getData());

	cudaDeviceSynchronize();

	timer.stop();

	timer.showElapsed();
	
	return 0;
}