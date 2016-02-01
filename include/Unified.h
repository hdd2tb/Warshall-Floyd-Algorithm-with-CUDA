#ifndef UNIFIED_H
#define UNIFIED_H

#include "Adjacency.h"
#include <cmath>
#include <algorithm>
#include <cstring>

#define INF 200000000
using namespace std;

template <class T>
class Unified : public Adjacency<T>{
public:
	Unified(int size);
	~Unified();
	Unified &operator=(Adjacency &adj);
};

template <class T>
Unified<T>::Unified(int size) : Adjacency(){
	this->size = sizeof(T) * size;
	cudaMallocManaged((void **)&data, this->size);
	vertex = int(sqrt(size));
	fill(data, data+size, INF);
	for (int i = 0; i < vertex; ++i) {
		data[i*vertex+i] = 0;	
	}
}

template <class T>
Unified<T>::~Unified(){
	cudaFree(data);
}

template <class T>
Unified<T> &Unified<T>::operator=(Adjacency<T> &adj){
	memcpy(data, adj.GetData(), this->size);
	return *this;
}

#endif