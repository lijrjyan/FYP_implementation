#include <bits/stdc++.h> 
#include "../header/Instance.h"
#ifndef _Case_
#define _Case_

class Case
{
public:
	Case(){};
	virtual bool solve(Instance I){return false;};
	virtual int** backtrack(){};
	virtual std::string getCase(){};
};

#endif
