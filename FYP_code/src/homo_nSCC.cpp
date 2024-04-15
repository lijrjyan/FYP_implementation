#include <bits/stdc++.h>
#include "../header/Instance.h"
#include "../header/Case.h"
#include "../header/homo_nSCC.h"

homo_nSCC::homo_nSCC(){Case();this->isSolved=false;breakpoint=NULL;}

bool homo_nSCC::solve(Instance I)
{
	this->isSolved=true;
	this->ins=I;
	std::vector<double>u;
	double* sum=new double[I.getN()+1];
	sum[0]=0;
	for(int i=0;i<I.getN();i++)
		sum[i+1]=sum[i]+I.getU()[0][i];
	for(int i=1;i<=I.getN();i++)
		for(int j=1;j<=i+1;j++)
			u.push_back(sum[i]-sum[j-1]);
	delete sum;
	std::sort(u.begin(),u.end());
	u.erase(unique(u.begin(),u.end()),u.end());
	int _m=I.getCondensation().get_M();
	std::vector<double>cur;
	std::vector<int>cnt(_m);
	for(int i=0;i<_m;i++)
		cnt[i]=I.getCondensation().getCnt()[i];
	breakpoint=new int[I.getM()];
	for(int i=0;i<I.getM();i++)
		breakpoint[i]=-1;
//	std::cout<<"*"<<std::endl;
	const auto& dp=[&](int n,std::vector<double>cur,int _m,std::vector<int>cnt,int ind)
	{
		std::function<bool(int,std::vector<double>,int,std::vector<int>,int)> s;
		s=[&](int n,std::vector<double>cur,int _m,std::vector<int>cnt,int ind)
		{
			if(!n)
			{
				for(int i=0;i<_m;i++)
					if(cnt[i]!=0)
						return false;
				return true;
			}
			for(int i=0;i<_m;i++)
			{
				if(cnt[i]!=0)
				{
					double sum=0;
					if(fabs(cur[i]-sum)<1e-9)
					{
						cnt[i]--;
						breakpoint[ind]=n;
						if(s(n,cur,_m,cnt,ind-1))
							return true;
						cnt[i]++;
						breakpoint[ind]=-1;
					}
					for(int j=n-1;j>=0;j--)
					{
						sum+=I.getU()[0][j];
//						std::cout<<j<<" "<<n<<"-¡·"<<I.getU()[0][j]<<" "<<sum<<std::endl;
						if(cur[i]==sum)
						{
							cnt[i]--;
							breakpoint[ind]=j;
							if(s(j,cur,_m,cnt,ind-1))
								return true;
							cnt[i]++;
							breakpoint[ind]=-1;
						}
					}
				}
			}
			return false;
		};
		return s(n,cur,_m,cnt,ind);
	};
	
	const auto& find=[&]()
	{
		std::function<bool()>s;
		s=[&](){
			if(cur.size()==_m)
			{
				for(int i=0;i<_m;i++)
					for(int j=0;j<_m;j++)
						if(I.getCondensation().getEdge()[i][j]&&u[i]<u[j])
							return false;
//				for(int i=0;i<_m;i++) std::cout<<cur[i]<<" ";
//				std::cout<<std::endl;
				bool fl=dp(I.getN(),cur,_m,cnt,I.getM()-1);
//				std::cout<<fl<<std::endl;
				return fl;
			}
			for(int i=0;i<u.size();i++)
			{
				cur.push_back(u[i]);
				if(s()==true) return true;
				cur.pop_back();
			}
			return false;
		};
		return s();
	};
	return find();
}

int** homo_nSCC::backtrack()
{
	int** a=new int*[ins.getM()];
	for(int i=0;i<ins.getM();i++)
		a[i]=new int[2];
	for(int i=0;i<ins.getM()-1;i++)
		a[i][0]=breakpoint[i],
		a[i][1]=breakpoint[i+1]-1;
	a[ins.getM()-1][0]=breakpoint[ins.getM()-1];
	a[ins.getM()-1][1]=ins.getN()-1;
	return a;
}

std::string homo_nSCC::getCase()
{
	return "Homogeneous agent and other relationship network";
}
