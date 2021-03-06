///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name: Kimisha Singh
// Student No: 213545959
// Date: 19 April 2015
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// ***** QUESTION 3 ******
// Question 3 has 3 parts
// 3.1 Using the MINIMAL "Fraction" class provided, overload the greater than operator to work with
//     objects of class Fraction as a NON-MEMBER FUNCTION.   You may modify the Fraction class to 
//     demonstrate friendship.  DO NOT USE FLOATING POINT MATH!!!
// 3.2 Overload two functions called "add" which take two arguements, an integer and a fraction (in 
//     either order) and return a fraction.  
// 3.3 create a driver program to test your overloaded > operators and your overloaded 

class Fraction {
private:
	int num;				// numerator;
	int denom;				// denominator;
public:
	Fraction(int n, int d) : num(n), denom(d) { };
	void print() { cout << num << "/" << denom; };
	
	friend bool operator > (Fraction one, Fraction two);
	Fraction add(int num, Fraction frac);
	Fraction add(Fraction frac, int num);
};

bool operator >(Fraction one, Fraction two)
{
	if (one.num * two.denom > two.num * one.denom)
	{
		return true;
	}
	else
		return false;
}

Fraction Fraction::add(int num, Fraction frac)
{
	Fraction ans = frac;
	ans.num = num * frac.denom + frac.num;
	return ans;
}

Fraction Fraction::add(Fraction frac, int num)
{
	Fraction ans = frac;
	ans.num = num * frac.denom + frac.num;
	return ans;
}

int main()
{
	Fraction a(1, 2), b(9, 10);

	if (a > b)
	{
		a.print();
		cout << " is greater than ";
		b.print();
	}
	else
	{
		b.print();
		cout << " is greater than ";
		a.print();
	}
	cout << endl;
	
	cout << "1 + ";
	a.print();
	Fraction ans = a.add(1, a);
	cout << " = ";
	ans.print();
	cout << endl;

	b.print();
	cout << " + 2 = ";
	ans = b.add(b, 2);
	ans.print();
	cout << endl;

	system("pause");
	return 0;	
}