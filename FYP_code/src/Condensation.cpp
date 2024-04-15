#include <bits/stdc++.h>
#include "../header/Condensation.h"

Condensation::Condensation(int* belong,int scc,int* cnt_edge_ori,int** edge_ori,int m)
{
	
	_m=scc;
	
	cnt=new int[scc];
	for(int i=0;i<scc;i++)
		cnt[i]=0; 
	for(int i=0;i<m;i++)
		cnt[belong[i]]++;
	
	edge=new int*[scc];
	for(int i=0;i<scc;i++)
	{
		edge[i]=new int[scc];
		for(int j=0;j<scc;j++)
			edge[i][j]=0;
	}
	
	for(int u=0;u<m;u++)
	{
		for(int j=0;j<cnt_edge_ori[u];j++)
		{
			int v=edge_ori[u][j];
			if(belong[u]!=belong[v])
				edge[belong[u]][belong[v]]=1;
		}
	}
}

void Condensation::write()
{
	std::cout<<"The condensation contains the following edges:"<<std::endl;
	for(int i=0;i<_m;i++)
		for(int j=0;j<_m;j++)
			if(edge[i][j])
				std::cout<<"c_"<<i<<",c_"<<j<<std::endl;
	for(int i=0;i<_m;i++)
		std::cout<<"c_"<<i<<" contains "<<cnt[i]<<" vertices."<<std::endl;
}

int Condensation::get_M(){return _m;}
int* Condensation::getCnt(){return cnt;}
int** Condensation::getEdge(){return edge;}
