# CUDAによるWarshall-Floyd法の実装

Warshall-Floyd法をCUDAを用いて並列処理します. 

## 実装方法

- cudaMalloc()とcudaMemcpy()を用いた実装

- Unified Memoryを用いた実装

- Zero-Copy Memoryを用いた実装

- ArrayFireを用いた実装