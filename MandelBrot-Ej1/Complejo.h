#ifndef Complejo_h
#define Complejo_h

#include <math.h>

class Complejo
{
public:
	Complejo() {

	}
	Complejo(float real, float im)
	{
		_real = real;
		_im = im;
	}
	~Complejo()
	{

	}
	Complejo operator+(Complejo com)
	{
		float real = _real + com._real;
		float im = com._im + _im;
		Complejo num(real,im);
		return num;
	}
	Complejo operator*(Complejo com)
	{
		float real = (_real * com._real) - (_im * com._im);
		float im = (_real * com._im) + (_im * com._real);
		Complejo num(real, im);
		return num;
	}
	float modulo()
	{
		float num = sqrt(_real * _real + _im * _im);
		return num;
	}
private:
	float _real, _im;
};

#endif