//calculate with cudaMalloc() and cudaMemcpy()

#include "include/gpgpu.h"
#include "include/Adjacency.h"
#include "include/cuMall.h"
#include "include/Elapsed.h"

int main(){
	int n, m;
	Elapsed timer;
	cin >> n >> m;
	const int N = n * n;
	dim3 grid(n/128, n, 1), block(128, 1, 1);
	Adjacency<int> adj(N);
	cuMall<int> cu(N);

	executeDummy();

	adj.setData();
	cu.HostToDevice(adj.getData());

	timer.start();

	for (int k = 0; k < n; ++k)
		WarshallFloyd <<< grid, block >>> (n, k, cu.getData());

	cudaDeviceSynchronize();

	cu.DeviceToHost(adj.getData());

	timer.stop();

	timer.showElapsed();

	return 0;	
}