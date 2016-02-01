#ifndef CUMALL_H
#define CUMALL_H

#define INF 200000000

template <class T>
class cuMall{
private:
	T *data;
	size_t size;
	
public:
	cuMall(int size);
	~cuMall();
	T *getData();
	size_t getSize();
	void HostToDevice(T *src);
	void DeviceToHost(T *dst);
};

template <class T>
cuMall<T>::cuMall(int size){
	this->size = sizeof(T) * size;
	cudaMalloc((void **)&data, this->size);
}

template <class T>
cuMall<T>::~cuMall(){
	cudaFree(data);
}

template <class T>
T *cuMall<T>::getData(){
	return data;	
}

template <class T>
size_t cuMall<T>::getSize(){
	return size;
}

template <class T>
void cuMall<T>::HostToDevice(T *src){
	cudaMemcpy(data, src, size, cudaMemcpyHostToDevice);
}

template <class T>
void cuMall<T>::DeviceToHost(T *dst){
	cudaMemcpy(dst, data, size, cudaMemcpyDeviceToHost);
}

#endif