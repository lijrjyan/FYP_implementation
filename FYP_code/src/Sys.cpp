#include <bits/stdc++.h>
#include "../header/Instance.h"
#include "../header/Sys.h"
#include "../header/Case.h"
#include "../header/homo_SCC.h"
#include "../header/homo_nSCC.h"
#include "../header/Condensation.h"

Sys::Sys(){this->ins=Instance();this->solver=new Case();}
Sys::Sys(Instance Ins){this->ins=Ins;this->solver=new Case();}

bool Sys::solve()
{
	if(!this->ins.checkNormalization())
	{
		std::cout<<"The input has not been normalized. After normalization, the instance becomes:"<<std::endl;
		this->ins.normalize();
		this->ins.write(); 
	}
	int* type=this->ins.countType();
//	std::cout<<type[ins.getM()]<<std::endl;
	if(type[ins.getM()]==1)
	{
//		std::cout<<1<<std::endl;
		this->ins.obtainCondensation();
		if(ins.getCondensation().get_M()==1)
			this->solver=new homo_SCC();
		else
			this->solver=new homo_nSCC();
		delete type;
	}
	return this->solver->solve(this->ins);
}

int** Sys::backtrack()
{
	return this->solver->backtrack();
}
