/*/--------------- PROGRAM 2.1 ---------------\*\
PROGRAMMER: 
	Jarod Teague
PURPOSE:
	This is the first portion, it calculates a 
	single integral.
\*\-------------------------------------------/*/

#include <iostream>
#include "function.h"

using namespace std;

//the following function is used as a basis for the program's structure:
//      b           n
//     ∫ f(x)dx =   Σ g(x_k)     where: g(x_k) = 1/2(f(x_k-1) + f(x_k))Δx
//    a           k = 1                      n = number of trapezoids
//                                          Δx = width of each trapezoid
//                                   

void obtainVals(double& a, double& b, int& n); // follows a basic structure, get the values, calculate the values, return result.
void calculate_GofX(double& area, double& a, double deltaX);
void result(double area, double a, double b);

int main()
{
	cout << "Hello, welcome to Integrator. A program that solves integrals." << endl; // starts the program with an introduction.
	
	double a; // lower/left bound
	double b; // upper/right bound
	int n; // number of trapezoids
	
	obtainVals( a, b, n );
	
	double deltaX = (b - a) / n;
	double x_left = a;
	double area = 0.0;
	
	for(int i = 0; i < n; i++) // this for loop represents our sigma(Σ), where it adds the value of n trapezoids into area
	{
		calculate_GofX(area, x_left, deltaX);// this section represents our f(x) to the left of our sigma
	}
	
	result(area, a, b);
	
	return 0;
}

void obtainVals(double& a, double& b, int& n)
{
	cout << "Let's get started, please enter the value of the leftmost bound (a): "  << endl;
	cin >> a;
	
	cout << "Now enter the value of the Rightmost bound (b): "  << endl;
	cin >> b;
	
	cout << "Enter the number of trapezoids (n): "  << endl;
	cin >> n;
}

void calculate_GofX(double& area, double& x_left, double deltaX)
{
	double x_right = x_left + deltaX;
	
	area += (0.5 * (FXL + FXR)) * deltaX;// FXL and FXR are the polynomial functions defined in our header file.
	
	x_left = x_right;
}

void result(double area, double a, double b)
{
	cout << "the area under the curve from a (" << a << ") to b (" << b << ") is : " << area << endl;
}
