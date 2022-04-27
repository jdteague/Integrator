//PROGRAMMED BY JAROD TEAGUE

#if !defined FUNCTION2_H
#define FUNCTION2_H

#include <cmath>

#define FXL (4 + 6*tv_left)
#define FXR (4 + 6*tv_right)

//both of these represnt the acceleration function:
//   
//     a(t) = 4 + 6t


//a(t) is to be integrated twice in order to extract position data:
//      b d
//     ∫ ∫ a(t)dt = d(t)
//    a c

//the integral will be evaluated as two riemann sums, using the values of the first integration to obtain the last:
//                   n
//     ∫∫ a(t)dt =   Σ 1/2(∫ a(t_k-1)dt + ∫ a(t_k)dt)Δt     where: n = number of trapezoids
//                 k = 1                                          Δt = width of each trapezoid
//                                                                     n
//                                                          ∫ a(t)dt = Σ 1/2( a(t_k-1)+ a(t_k))Δt
//                                                                   k = 1
#endif