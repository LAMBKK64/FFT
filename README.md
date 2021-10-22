## About:
This is the C programming for the FFT algorithm.  We give the basic divide-and-conquer method that leads to the FFT. We need to assume that N is a power of two.
## Steps:
## System Model :
![bc3](https://user-images.githubusercontent.com/92636271/137636463-c0e9d5f9-decd-4fdd-ac9f-cb4b98565d9a.png)

## Code Function :
**Input**
- Signal x[n].
- N.
  
**Implement**
-	Compare N with 4.
-	DFT can be decomposed into four N/4-point DFTs. 
-	Compute N/4-point DFTs.

![bc4](https://user-images.githubusercontent.com/92636271/137636774-95252f02-c440-4a2d-ae9b-eb2202498943.PNG)

**Output**
- Signal X[k].

## Evaluate:
-	When using C code, we get the same results when using the function available on Matlab.

*Results when using C programming:*
![bc1](https://user-images.githubusercontent.com/92636271/137636886-66e60bab-5baf-4ae9-82f0-d863a1e6f944.PNG)

*Results when using Matlab:*

![bc2](https://user-images.githubusercontent.com/92636271/137636948-b18ab686-00f4-4c81-ae12-89085cc3a71b.PNG)

*Compare numbers of calculations when using DFT with FFT*


![bc13](https://user-images.githubusercontent.com/92636271/138508937-8736c0d6-7774-49e7-826b-4b927c346aa3.PNG)


