#ifndef ADJACENCY_H
#define ADJACENCY_H

#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iomanip>

#define INF 200000000
using namespace std;

template <class T>
class Adjacency{
protected:
	T *data;
	int vertex;
	size_t size;

private:
	bool flag = false;

public:
	Adjacency();
	Adjacency(int size);
	virtual ~Adjacency();
	void showArray();
	T *getData();
	void setData();
	int getVertex();
	void showCost();
	bool operator==(Adjacency adj);
	Adjacency<T> &operator=(Adjacency<T> &adj);
};

template <class T>
Adjacency<T>::Adjacency(){}

template <class T>
Adjacency<T>::Adjacency(int size){
	vertex = int(sqrt(size));
	this->size = sizeof(T) * size;
	data = new T [size];
	fill(data, data+size, INF);
	for (int i = 0; i < vertex; ++i) {
		data[i*vertex+i] = 0;	
	}
	flag = true;
}

template <class T>
Adjacency<T>::~Adjacency(){
		if(flag) delete [] data;
}

template <class T>
void Adjacency<T>::showArray(){
	for (int i = 0; i < vertex; i++) {
		for (int j = 0; j < vertex; j++) {
			cout << setw(10) << data[i*vertex+j] << " ";
		}
		cout << endl;
	}
}

template <class T>
T *Adjacency<T>::getData(){
	return data;
}

template <class T>
void Adjacency<T>::setData(){
	for (int i = 0; i < vertex; ++i) {
		for (int j = 0; j < vertex; ++j) {
			cin >> data[i*vertex+j];	
		}
	}
}

template <class T>
int Adjacency<T>::getVertex(){
	return vertex;
}

template <class T>
void Adjacency<T>::showCost(){
	for (int i = 0; i < vertex; i++) {
		for (int j = 0; j < vertex; j++) {
			if (i != j && data[i*vertex + j] != INF)
				cout << "the cost from " << i << " to " << j << ": " 
				     << data[i*vertex + j] << endl;
		}
	}
}

template <class T>
bool Adjacency<T>::operator==(Adjacency<T> adj){
	if(memcmp(data, adj.data, size) == 0) 
		return true;
	else return false;
}

template <class T>
Adjacency<T> &Adjacency<T>::operator=(Adjacency<T> &adj){
	if(this != &adj){
		memcpy(data, adj.GetData(), size);
	}
	return *this;
}

#endif