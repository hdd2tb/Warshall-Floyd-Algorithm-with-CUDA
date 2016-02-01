#ifndef GPGPU_H
#define GPGPU_H
 
#include <iostream>
#include <algorithm>
#include <thrust\host_vector.h>
#include <thrust\device_vector.h>

#define INF 200000000
using namespace std;

void executeDummy(){
	int *dummy;
    cudaMalloc((void **)&dummy, sizeof(int) * 1);
    cudaFree(dummy);
}

__global__ void WarshallFloyd(int n, int k, int *d){
	int x = threadIdx.x + blockIdx.x * blockDim.x;
	int y = threadIdx.y + blockIdx.y * blockDim.y;	
	int xy = x + y * blockDim.x * gridDim.x;

	if(xy < n*n)
		d[xy] = min(d[xy], d[k + y * blockDim.x * gridDim.x] + 
			d[x + k * blockDim.x * gridDim.x]);
}

void WarshallFloyd(int n, int *d){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				d[j*n+k] = min(d[j*n+k], d[j*n+i] + d[i*n+k]);
}

#endif