#include <bits/stdc++.h>
#include "../header/Instance.h"
#include "../header/Case.h"
#ifndef _Sys_
#define _Sys_

class Sys
{
private:
	//The input instance.
	Instance ins;
	Case *solver;
public:
	Sys();
	Sys(Instance Ins);
	bool solve();
	int** backtrack();
};

#endif
