#include <bits/stdc++.h>
#include "../header/Instance.h"
#include "../header/Case.h"
#ifndef _homo_nSCC_
#define _homo_nSCC_

class homo_nSCC:public Case
{
private:
	bool isSolved;
	Instance ins;
	int* breakpoint;
public:
	homo_nSCC();
	bool solve(Instance I) override;
	int** backtrack() override;
	std::string getCase() override;
};

#endif
