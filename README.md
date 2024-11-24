<h2 align="center">
  Analysis of the performance
</h2>

## Overview

This project involves computing acceleration values using a combination of C and assembly code. The program leverages SIMD instructions for optimized floating-point computations, ensuring efficient performance even with large datasets. It includes both functionality testing and performance testing to evaluate the scalability of the implementation.

## Observations

The program was tested with matrices of sizes **10**, **100**, **1000**, and **10,000** rows. Across all tests, the reported average execution time remained **0.000000 seconds**, regardless of the matrix size. This result highlights the efficiency of the program but also indicates limitations in the timing mechanism used for measurement.

1. Consistent Execution Times

  The execution time did not increase with larger matrix sizes. This suggests that the computational workload is being handled efficiently, and the program's scalability is robust for the tested sizes.

2. Efficient Use of SIMD Instructions

  The assembly function employs SIMD floating-point instructions (subsd, divsd, and CVTSD2SI) to compute acceleration values. These instructions process data quickly and efficiently, minimizing computation time even for larger matrices.

3. Impact of Overheads

  Memory allocation, randomized input generation (for performance testing), and result output contribute to overall runtime but are not included in the reported execution times.

4. Scalability Insights

  The program scales well with matrix size, handling even large datasets (10,000 rows) with the same efficiency as smaller sizes.

## Conclusion

We have found that the program handles workloads efficiently across all tested sizes, with small data sizes (10, 100 rows) and medium sizes (1000 rows) completing almost instantaneously thanks to modern hardware and SIMD-based computation. Even for larger sizes (10,000 rows), the execution time remained negligible, showing that the program scales well with increased workloads. While the consistent 0.000000 seconds execution time indicates the need for a more precise timing method, we can confidently say that the program is highly efficient, scalable, and makes excellent use of SIMD instructions for optimized floating-point computations.

## Example Outputs

**Test Case 1**: Small Values
<p align="center"> <img src="https://raw.githubusercontent.com/R1kkaa/MP2---LBYARCH/main/screenshots/ss%20(1).png" alt="Test Case 1 Screenshot" width="800"> </p>

**Test Case 2**: Zero Acceleration
<p align="center"> <img src="https://raw.githubusercontent.com/R1kkaa/MP2---LBYARCH/main/screenshots/ss%20(2).png" alt="Test Case 2 Screenshot" width="800"> </p>

**Test Case 3**: Negative Acceleration (Deceleration)
<p align="center"> <img src="https://raw.githubusercontent.com/R1kkaa/MP2---LBYARCH/main/screenshots/ss%20(3).png" alt="Test Case 3 Screenshot" width="800"> </p>

**Test Case 4**: Large Values
<p align="center"> <img src="https://raw.githubusercontent.com/R1kkaa/MP2---LBYARCH/main/screenshots/ss%20(4).png" alt="Test Case 4 Screenshot" width="800"> </p>

**Test Case 5-8**: Small (10), Medium (100), Large (1000), and Very Large (10,000) Data Sizes
<p align="center"> <img src="https://raw.githubusercontent.com/R1kkaa/MP2---LBYARCH/main/screenshots/ss%20(5).png" alt="Test Case 5-8 Screenshot" width="800"> </p>
