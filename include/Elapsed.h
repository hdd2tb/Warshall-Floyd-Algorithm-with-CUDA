#ifndef ELAPSED_H
#define ELAPSED_H

#include <iostream>
#include <iomanip>

using namespace std;


struct Elapsed{
private:
	cudaEvent_t begin, end;
	float elapsed = 0.0;

public:
	Elapsed();
	~Elapsed();
	void start();
	void stop();
	void showElapsed();
};

Elapsed::Elapsed(){
	cudaEventCreate(&begin);
	cudaEventCreate(&end);
}

Elapsed::~Elapsed(){
	cudaEventDestroy(begin);
	cudaEventDestroy(end);
}

void Elapsed::start(){
	cudaEventRecord(begin, 0);
}
	
void Elapsed::stop(){
	cudaEventRecord(end, 0);
}

void Elapsed::showElapsed(){
	cudaEventSynchronize(end);
	cudaEventElapsedTime(&elapsed, begin, end);
	cout << "GPU time: " << fixed << setprecision(5) << elapsed << " ms" << endl;
}

#endif