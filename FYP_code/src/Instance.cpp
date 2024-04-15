#include <bits/stdc++.h>
#include "../header/Instance.h"
#include "../header/Condensation.h"

Instance::Instance()
{
	this->n=0;
	this->m=0;
	this->u_min=this->u_max=0;
	this->u=NULL;
	this->edge=NULL;
	this->c=Condensation();
}

void Instance::read()
{
	double val;
	int u,v;
	std::cin>>this->n>>this->m;
	this->u=new double*[this->m]();
	this->u_min=1,this->u_max=0;
	for(int i=0;i<this->m;i++)
	{	this->u[i]=new double[this->n]();
		for(int j=0;j<this->n;j++)
		{
			std::cin>>val;
			this->u[i][j]=val;
			this->u_min=std::min(this->u_min,val);
			this->u_max=std::max(this->u_max,val);
		}
	}
	this->edge=new int*[this->m]();
	this->cnt_edge=new int[this->m]();
	for(int i=0;i<this->m;i++)
	{
		std::cin>>this->cnt_edge[i];
		this->edge[i]=new int[this->cnt_edge[i]]();
		for(int j=0;j<this->cnt_edge[i];j++)
			std::cin>>this->edge[i][j];
	}
}

void Instance::write()
{
	std::cout<<"There are "<<n<<" items and "<<m<<" agents."<<std::endl;
	std::cout<<"The utility function is:"<<std::endl;
	for(int i=0;i<this->m;i++)
	{
		std::cout<<"u_"<<i<<":";
		for(int j=0;j<this->n;j++)
			std::cout<<" "<<u[i][j];
		std::cout<<std::endl;
	}
	std::cout<<"The adjacency link is:"<<std::endl;
	for(int i=0;i<this->m;i++)
	{
		std::cout<<i<<"->:";
		for(int j=0;j<this->cnt_edge[i];j++)
			std::cout<<" "<<edge[i][j];
		std::cout<<std::endl;
	}
}

bool Instance::checkNormalization()
{
	bool fl=true;
	double sum=0;
	for(int i=0;i<m;i++)
	{
		sum=0;
		for(int j=0;j<n;j++)
			sum=sum+u[i][j];
		if(std::fabs(sum-1)>1e-9)
			return false;
	}
	return true;
}

void Instance::normalize()
{
	double sum=0;
	for(int i=0;i<this->m;i++)
	{
		sum=0;
		for(int j=0;j<n;j++)
			sum=sum+u[i][j];
		for(int j=0;j<n;j++)
			u[i][j]/=sum;
	}
}

int* Instance::countType()
{
	int *f=new int[this->m];
	for(int i=0;i<m;i++) f[i]=i;
	const auto& find=[&](const int& x)
	{
		std::function<int(const int&)>s;
		s=[&](const int& x){
			return x==f[x]?x:f[x]=s(f[x]);
		};
		return s(x);
	};
	for(int i=0;i<m;i++)
		for(int j=1;j<m;j++)
		{
			int fi=find(i),fj=find(j);
			if(fi!=fj)
			{
				bool fl=true;
				for(int k=0;k<this->n;k++)
					if(this->u[i][k]!=this->u[j][k])
						fl=false;
				if(fl)
					f[i]=fj;
			}
		}
	int* t=new int[m+1];
	t[m]=0;
	for(int i=0;i<m;i++) if(f[i]==i)
	{
		for(int j=0;j<m;j++)
		{
			int fi=find(i),fj=find(j);
			if(fi==fj)
				t[j]=t[m];
		}
		t[m]++;
	}
	delete f;
	return t;
}

int Instance::getN(){return this->n;}
int Instance::getM(){return this->m;}
double** Instance::getU(){return this->u;}
int** Instance::getEdge(){return this->edge;}
int* Instance::getCntEdge(){return this->cnt_edge;}
double Instance::getUmin(){return this->u_min;}
double Instance::getUmax(){return this->u_max;}
Condensation Instance::getCondensation(){return c;}

void Instance::obtainCondensation()
{
	int* low=new int[m];
	int* dfn=new int[m];
	int* stack=new int[m];
	bool* vis=new bool[m]; 
	int tot=0,top=0,scc=0;
	for(int i=0;i<m;i++)
		vis[i]=dfn[i]=0;
	int* belong=new int[m];
	
	const auto& tarjan=[&](const int& u)->void
	{
		std::function<void(const int&)>s;
		s=[&](const int& u)->void{
			int v;
			low[u]=dfn[u]=++tot;
			stack[++top]=u;
			vis[u]=1;
			for(int i=0;i<cnt_edge[u];i++)
			{
				v=edge[u][i];
				if(!dfn[v])
				{
					s(v);
					low[u]=std::min(low[u],low[v]);
				}
				else if(vis[v])
					low[u]=std::min(low[u],dfn[v]);
			}
			if(low[u]==dfn[u])
			{
				do
				{
					v=stack[top--];
					vis[v]=0;
					belong[v]=scc;
				}while(v!=u);
				scc++;
			}
		};
		s(u);
	};
	
	for(int i=0;i<m;i++)
		if(!dfn[i])
			tarjan(i);
	
	c=Condensation(belong,scc,cnt_edge,edge,m);
	
	delete low;
	delete dfn;
	delete stack;
	delete vis;
	delete belong;
}
bool Instance::findEdge(int u,int v)
{
	for(int i=0;i<cnt_edge[u];i++)
		if(edge[u][i]==v)	return true;
	return false;
}
