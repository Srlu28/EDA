#ifndef Monomio_h
#define Monomio_h
#include <iostream>

using namespace std;
typedef struct monomio
{
	int exp;
	int coc;
};

bool esValido(monomio mon)
{
	return mon.coc != 0 || mon.exp != 0;
}
#endif