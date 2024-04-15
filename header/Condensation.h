#include <bits/stdc++.h>

#ifndef _CONDENSATION_
#define _CONDENSATION_

class Condensation
{
private:
	int _m;
	int* cnt;
	int** edge;
public:
	Condensation(){};
	Condensation(int* belong,int scc,int* cnt_edge_ori,int** edge_ori,int m);
	
	void write();
	int get_M();
	int* getCnt();
	int** getEdge();
};

#endif
