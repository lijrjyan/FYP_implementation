#include <bits/stdc++.h>
#include "../header/Instance.h"
#include "../header/Case.h"
#ifndef _homo_SCC_
#define _homo_SCC_

class homo_SCC:public Case
{
private:
	bool isSolved;
	Instance ins;
public:
	homo_SCC();
	bool solve(Instance I) override;
	int** backtrack() override;
	std::string getCase() override;
};

#endif
