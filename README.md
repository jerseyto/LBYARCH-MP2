ARIAGA, MARIAN RICCI N.

TO, JERSEY K.

LBYARCH-MP2


# COMPARISON AND ANALYSIS OF EXECUTION TIME AND PERFORMANCE OF KERNELS


Link to our demo video: https://drive.google.com/file/d/1Nfdyk_XDHr0D4k_hOYcx9kw28qGkrkG4/view?usp=sharing

This program evaluates and compares the execution times of kernel operations that compute the dot product of two vectors using C and x86-64 assembly language. The program measures performance across varying vector sizes (2²⁰, 2²⁴, and 2²⁸), with the largest size reduced from the initial target of 2³⁰ due to system limitations. Each kernel is executed 20 times per vector size, amounting to 60 test cases in total. The results highlight key differences between the two implementations, with average execution times computed to emphasize performance trends.

In debug mode, the assembly implementation consistently outperforms the C implementation. For a vector size of 2²⁰, the C implementation averages 4.65 ms, while assembly achieves a significantly faster 1.30 ms. As the vector size increases, the difference becomes more pronounced. For 2²⁴, C has an average execution 78.55 ms, while assembly runs at an average of 20.10 ms. For 2²⁸, C averages 983.35 ms, while assembly reduces this to 247.90 ms. These results reflect the inherent efficiency of assembly, which minimizes overhead by directly leveraging hardware capabilities. In contrast, C suffers from runtime checks and additional abstractions in debug mode, which diminish its performance.

In release mode, where the compiler automatically optimizes the code resulting in faster and smaller code, the performance gap between the two implementations narrows. For small vector sizes, the execution times of C and assembly are nearly identical, with C averaging 1.25 ms and assembly averaging 1.20 ms for 2²⁰. As vector sizes increase, the results show a slight performance advantage for C.  For 2²⁴, C has an average execution 19.90 ms, while assembly runs at a slightly slower average time of 20.85 ms. With the largest vector size,  2²⁸, C is slightly faster in execution time with 249.30 ms compared to assembly's 251.55 ms average execution time. This trend reflects the power of modern compilers to produce highly efficient machine code, often rivaling or surpassing hand-tuned assembly in well-optimized environments.

Overall, the results suggest distinct use cases for each implementation. In debug scenarios or non-optimized environments, assembly has better performance, particularly for larger workloads. However, in release mode, modern compiler optimizations make C code just as efficient as assembly code. For most applications, C in release mode provides the best balance of speed and maintainability. However, for critical performance scenarios or niche applications requiring maximum efficiency, coding in assembly would be a good option because of its faster performance.


# DEBUG MODE SCREENSHOT WITH CORRECTNESS CHECKS:
![DEBUG SCREENSHOT](https://github.com/user-attachments/assets/4be7fe5b-c3f8-48d7-bceb-8ec26881a725)


# RELEASE MODE SCREENSHOT WITH CORRECTNESS CHECKS:
<img width="947" alt="RELEASE SCREENSHOT" src="https://github.com/user-attachments/assets/f3153ae1-fda6-4241-9352-e40a7d11f610">

