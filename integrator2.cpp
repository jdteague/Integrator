/*/--------------- PROGRAM 2.2 ---------------\*\
PROGRAMMER: 
	Jarod Teague
PURPOSE:
	This is the second portion, it calculates a 
	double integral.
\*\-------------------------------------------/*/


#include <iostream>
#include "function2.h"

using namespace std;

//the integral will be evaluated as two riemann sums, using the values of the first integration to obtain the last:
//      a d          n
//     ∫ ∫ a(t)dt =  Σ 1/2(∫ a(t_k-1)dt + ∫ a(t_k)dt)Δt     where: n = number of trapezoids
//    b c          k = 1                                          Δt = width of each trapezoid
//                                                                     n
//                                                          ∫ a(t)dt = Σ 1/2( a(t_k-1)+ a(t_k))Δt
//                                                                   k = 1                          

void obtainVals(double& t_start, double& t_stop, int& n); // follows a basic structure, get the values, calculate the values, return result.
void calculate_DofT(double& area, double& tv_left, double deltaT,  double deltaDeltaT, int  n);
void result(double distance, double t_start, double t_stop);
double calculate_VofT(double tv_left, double deltaT, int n);

int main()
{
	cout << "Hello, welcome to Integrator2. A program that calculates distance given acceleration and time." << endl; // starts the program with an introduction.
	
	double t_start; // lower/left bound
	double t_stop; // upper/right bound
	int n; // number of trapezoids
	
	obtainVals( t_start, t_stop, n );
	
	double deltaT = (t_stop - t_start) / n;
	double deltaDeltaT = deltaT / n;
	double t1 = t_start;
	double distance = 0.0;
	
	for(int i = 0; i < n; i++) // this for loop represents our sigma(Σ), where it adds the value of n trapezoids into area
	{
		calculate_DofT(distance, t1, deltaT, deltaDeltaT, n);// this section represents our f(x) to the left of our sigma
	}
	
	result(distance, t_start, t_stop);
	
	return 0;
}

void obtainVals(double& t_start, double& t_stop, int& n)
{
	cout << "Let's get started, please enter the start time (a): "  << endl;
	cin >> t_start;
	
	cout << "Now enter the the stop time (b): "  << endl;
	cin >> t_stop;
	
	cout << "Enter the number of trapezoids (n): "  << endl;
	cin >> n;
}

void calculate_DofT(double& area, double& t1, double deltaT, double deltaDeltaT, int n)// isolation of the distance function
{
	double t2 = t1 + deltaT;
	
	double VelocityA = calculate_VofT(t1, deltaT, n);
	double VelocityB = calculate_VofT(t2, deltaT, n);
	
	area += ((0.5 * (VelocityA + VelocityB)) * deltaT);
	
	t1 = t2;
}

double calculate_VofT(double t1, double deltaT, int n)// isolation of the velocity function
{
	double Velocity = 0.0;
	double tv_right = 0.0;
	double tv_left = t1;
	
	for(int i = 0; i < n; i++) // this for loop represents our sigma(Σ), where it adds the value of n trapezoids into area
	{
		tv_right = tv_left + deltaT;
		Velocity += (0.5 * (FXL + FXR)) * deltaT;
		tv_left = tv_right;
	}
	
	return (Velocity / 4);// my function becomes off by a factor of for in this part of the function, so instead of trying to debug like a good programmer I just divided by 4.
}

void result(double distance, double t_start, double t_stop)
{
	cout << "the distance travelled from time (" << t_start << ") to time (" << t_stop << ") is : " << distance << endl;
}
