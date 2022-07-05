#include <iostream>
#include "Fraction.cpp"
using namespace std;




int main()
{
	Complex<float> c1(1,2);
	Complex<float> c2(3,-1);
	Complex<float> c3 = c1 / c2;
	c3.print();

}
