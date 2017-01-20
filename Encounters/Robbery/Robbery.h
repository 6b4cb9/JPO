#include "klasy.h"

class Element {
public:
	virtual bool Proceed(Postac * Character) = 0;
};

class Robbery : Element
{
public:
	bool Proceed(Postac * ch);
};

