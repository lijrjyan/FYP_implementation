#include <bits/stdc++.h>
#include "../header/Instance.h"
#include "../header/Case.h"
#include "../header/homo_SCC.h"

homo_SCC::homo_SCC(){Case();this->isSolved=false;}

bool homo_SCC::solve(Instance I)
{
	this->isSolved=true;
	this->ins=I;
	double sum=0,tar=1.0/I.getM();
	double **u=I.getU();
	for(int j=0;j<I.getN();j++)
	{
		sum+=u[0][j];
		if(std::fabs(sum-tar)<=1e-9)
			sum=0;
		else if(tar<sum+1e-9)
		{
			return false;
		}
	}
	return true;
}

int** homo_SCC::backtrack()
{
	int m=this->ins.getM();
	int **a=new int*[m];
	for(int i=0;i<m;i++)
		a[i]=new int[2];
	a[0][0]=0,a[m-1][1]=this->ins.getN()-1;
	int nw=0;
	double sum=0,tar=1.0/this->ins.getM();
	for(int j=0;j<this->ins.getN();j++)
	{
		sum+=this->ins.getU()[0][j];
		if(std::fabs(sum-tar)<=1e-9)
		{
			a[nw][1]=j;
			if(nw<m-1)
				a[nw+1][0]=j+1;
			nw++;
			sum=0;
		}
	}
	return a;
}

std::string homo_SCC::getCase()
{
	return "Homogeneous agent and strongly connected relationship network";
}
