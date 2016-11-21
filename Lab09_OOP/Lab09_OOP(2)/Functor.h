#pragma once
#include "Container.h"
template <class T, template <typename> typename funct>
class Functor 
{
public:
	Functor(funct<T> f) : funct(f) {};
	funct<T> funct;
	double operator() (const T& t1, const T& t2) { return funct(t1, t2); }
};