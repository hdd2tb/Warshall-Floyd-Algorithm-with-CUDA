/*
Class to implement Zero-Copy Memory
Zero-Copy Memoryを実装するためのクラス
*/

#ifndef ZEROCOPY_H
#define ZEROCOPY_H

#include "Adjacency.h"
#include <cmath>
#include <algorithm>
#include <cstring>

#define INF 200000000
using namespace std;

template <class T>
class ZeroCopy : public Adjacency<T>{
public:
	ZeroCopy(int size);
	~ZeroCopy();
	ZeroCopy<T> &operator=(Adjacency<T> &adj);
};

template <class T>
ZeroCopy<T>::ZeroCopy(int size) : Adjacency(){
	cudaSetDeviceFlags(cudaDeviceMapHost);
	this->size = sizeof(T) * size;
	cudaHostAlloc((void **)&data, this->size, cudaHostAllocMapped);
	vertex = int(sqrt(size));
	fill(data, data+size, INF);
	for (int i = 0; i < vertex; ++i) {
		data[i*vertex+i] = 0;	
	}
}

template <class T>
ZeroCopy<T>::~ZeroCopy(){
	cudaFreeHost(data);
}

template <class T>
ZeroCopy<T> &ZeroCopy<T>::operator=(Adjacency<T> &adj){
	memcpy(data, adj.GetData(), size);
	return *this;
}

#endif