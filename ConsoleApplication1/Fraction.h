#pragma once
template <typename T>
class Fraction
{
private:
	T numerator;
	T denominator;
	T integer;
public:
	Fraction()
	{

	}
	Fraction(T numerator, T denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}

	void setNumerator(T numerator)
	{
		this->numerator = numerator;
	}
	void setDenominator(T denominator)
	{
		this->denominator = denominator;
	}
	void print()
	{
		if (integer > 0) cout << integer << " " << numerator << "/" << denominator;
		else if (numerator == 0 && denominator == 0) cout << integer;
		else cout << numerator << "/" << denominator;
	}

	Fraction operator +(Fraction d2)
	{
		Fraction d3;
		d3.numerator = numerator*d2.denominator + d2.numerator*denominator;
		d3.denominator = denominator * d2.denominator;
		if (d3.numerator > d3.denominator)
		{
			d3.integer = d3.numerator / d3.denominator;
			d3.numerator -= d3.denominator;
		}
		else if (d3.numerator == d3.denominator)
		{
			d3.integer = d3.numerator / d3.denominator;
			d3.numerator %= d3.numerator;
			d3.denominator %= d3.denominator;
		}
		return d3;
	}

	Fraction operator -(Fraction d2)
	{
		Fraction d3;
		d3.numerator = numerator * d2.denominator - d2.numerator * denominator;
		d3.denominator = denominator * d2.denominator;
		if (d3.numerator > d3.denominator)
		{
			d3.integer = d3.numerator / d3.denominator;
			d3.numerator -= d3.denominator;
		}
		else if (d3.numerator == d3.denominator)
		{
			d3.integer = d3.numerator / d3.denominator;
			d3.numerator %= d3.numerator;
			d3.denominator %= d3.denominator;
		}
		return d3;
	}

	Fraction operator *(Fraction d2)
	{
		Fraction d3;
		d3.numerator = numerator * d2.numerator;
		d3.denominator = denominator * d2.denominator;
		if (d3.numerator > d3.denominator)
		{
			d3.integer = d3.numerator / d3.denominator;
			d3.numerator -= d3.denominator;
		}
		else if (d3.numerator == d3.denominator)
		{
			d3.integer = d3.numerator / d3.denominator;
			d3.numerator %= d3.numerator;
			d3.denominator %= d3.denominator;
		}
		return d3;
	}

	Fraction operator /(Fraction d2)
	{
		Fraction d3;
		d3.numerator = numerator * d2.denominator;
		d3.denominator = denominator * d2.numerator;
		if (d3.numerator > d3.denominator)
		{
			d3.integer = d3.numerator / d3.denominator;
			d3.numerator -= d3.denominator;
		}
		else if (d3.numerator == d3.denominator)
		{
			d3.integer = d3.numerator / d3.denominator;
			d3.numerator %= d3.numerator;
			d3.denominator %= d3.denominator;
		}
		return d3;
	}
};

template <typename T>
class Complex
{
	T integer;
	T imaginary;
	string operat;
public:
	Complex()
	{}
	Complex(T integer, T imaginary)
	{
		this->integer = integer;
		this->imaginary = imaginary;
	}

	Complex operator+(Complex c2)
	{
		Complex c3;
		c3.integer = integer + c2.integer;
		c3.imaginary = imaginary + c2.imaginary;
		if (c3.imaginary > 0) c3.operat = "+";
		else c3.operat = "";
		return c3;
	}

	Complex operator-(Complex c2)
	{
		Complex c3;
		c3.integer = integer - c2.integer;
		c3.imaginary = imaginary - c2.imaginary;
		if (c3.imaginary > 0) c3.operat = "+";
		else c3.operat = "";
		return c3;
	}

	Complex operator*(Complex c2)
	{
		Complex c3;
		T a1 = 0, b1 = 0, a2 = 0, b2 = 0;
		a1 = integer * c2.integer;
		b1 = integer * c2.imaginary;
		a2 = imaginary * c2.integer;
		b2 = imaginary * c2.imaginary * -1;
		c3.integer = a1 + b2;
		c3.imaginary = b1 + a2;
		if (c3.imaginary > 0) c3.operat = "+";
		else c3.operat = "";
		return c3;
	}

	Complex operator/(Complex c2)
	{
		Complex c3, c4, c5;
		c4.integer = c2.integer;
		c4.imaginary = c2.imaginary * -1;
		c3 = *this * c4;
		c4 = c2 * c4;
		c3.imaginary = c3.imaginary / c4.integer;
		c3.integer = c3.integer / c4.integer;
		if (c3.imaginary > 0) c3.operat = "+";
		else c3.operat = "";
		return c3;
	}

	void print()
	{
		if (integer != 0)cout << integer << operat;
		if (imaginary == 1 || imaginary == 0) cout << "i" << endl;
		else cout << imaginary << "i" << endl;
	}
};