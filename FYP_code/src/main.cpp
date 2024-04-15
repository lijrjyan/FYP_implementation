#include <bits/stdc++.h>
#include "../header/Instance.h"
#include "../header/Sys.h"
#include "../header/Condensation.h"
using namespace std;
int main()
{
	Instance I;
	I.read();
//	Condensation c=I.getCondensation();
//	c.write();
	Sys s=Sys(I);
	if(s.solve())
	{
		int **a=s.backtrack();
		cout<<"There is an EF contiguous allocation"<<endl;
		for(int i=0;i<I.getM();i++)
			if(a[i][1]<a[i][0])
				cout<<"F_"<<i<<" get nothing"<<endl;
			else
				cout<<"F_"<<i<<" get ["<<a[i][0]<<","<<a[i][1]<<"]"<<endl;
	}
	else
		cout<<"There is no EF contiguous allocation"<<endl;
	return 0;
}
/*
First line has two number representing the number of items and the number of agents

Next is a m*n matrix representing the utility function, where the i-th row and j-th column is u_i(j)

Next m rows descibe the relationship network.
In i-th row, the input start with a number adj_i, which is the number of vertex F_i's adjacent vertices. The following 
adj_i numbers are F_i's adjacent vertices.

Here is two example:
7 6
0.1 0.1 0.2 0.2 0.4 0.4 0.4
0.1 0.1 0.2 0.2 0.4 0.4 0.4
0.1 0.1 0.2 0.2 0.4 0.4 0.4
0.1 0.1 0.2 0.2 0.4 0.4 0.4
0.1 0.1 0.2 0.2 0.4 0.4 0.4
0.1 0.1 0.2 0.2 0.4 0.4 0.4
1 1
1 2
1 0
2 4 0
1 5
1 3

4 4
1 1 1 1
0.2 0.2 0.2 0.2
0.2 0.2 0.2 0.2
0.2 0.2 0.2 0.2
1 1
1 2
1 0
1 0

5 4
1 1 1 1 1
0.2 0.2 0.2 0.2 0.2
0.2 0.2 0.2 0.2 0.2
0.2 0.2 0.2 0.2 0.2
1 1
1 2
1 3
1 0
*/
