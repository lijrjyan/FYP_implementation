#include <bits/stdc++.h>
#include "../header/Condensation.h"
#ifndef _INSTANCE_
#define _INSTANCE_

class Instance
{
private:
	//The number of items n, the number of agents m
	int n,m;
	//The utility function u, where the entry u[i][j] refers to u_i(j)
	double **u;
	//The entry edge[i][j] stores a vertex such that the edge from i to
	//u[i][j] exists in the relationship network.
	//The entry cnt_edge[i] is the number of adjacent vertices of i
	int **edge,*cnt_edge;
	//The maximal and minimal utility among each item toward each agent
	double u_min,u_max;
	int *type;
	Condensation c;

public:
	Instance();
	void read();
	void write();
	bool checkNormalization();
	void normalize();
	int* countType();
	
	int getN();
	int getM();
	double** getU();
	int** getEdge();
	int* getCntEdge();
	double getUmin();
	double getUmax();
	Condensation getCondensation();
	
	void obtainCondensation();
	
	bool findEdge(int u,int v);
};

#endif
