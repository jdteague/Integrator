//PROGRAMMED BY JAROD TEAGUE

#if !defined FUNCTION_H
#define FUNCTION_H

#include <cmath>

#define FXL (0.8*pow(x_left, 4) - 6.3*pow(x_left, 3) + 4.1)
#define FXR (0.8*pow(x_right, 4) - 6.3*pow(x_right, 3) + 4.1)

//both of these represnt the polynomial:
//   
//     f(x) = .8x^4 - 6.3x^3 + 4.1


//f(x) is to be plugged into the integral:
//
//     ∫ f(x)dx    from: (x_left) to (x_right)


//the integral will be evaluated as a riemann sum, following the trapezoidal rule:
//                  n
//     ∫ f(x)dx =   Σ 1/2(f(x_k-1) + f(x_k))Δx     where: n = number of trapezoids & Δx = width of each trapezoid
//                k = 1
#endif