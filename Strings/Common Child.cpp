/*
****************************************************************
****************************************************************
-> Coded by Stavros Chryselis				   
-> Visit my github for more solved problems over multiple sites 
-> https://github.com/StavrosChryselis			  
-> Feel free to email me at stavrikios@gmail.com	
****************************************************************
****************************************************************
*/

#include <stdio.h>
#include <string>
#define max(a, b) ((a>b)?a:b)

using namespace std;

int DP[2][250000];
string A, B;

void init()
{
	char c;

	A.push_back('0');
	B.push_back('0');

	c=fgetc(stdin);
	while(isalpha(c))
	{
		A.push_back(c);
		c=fgetc(stdin);
	}

	c=fgetc(stdin);
	while(isalpha(c))
	{
		B.push_back(c);
		c=fgetc(stdin);
	}
}

void filldp()
{
	int i, j;
	char c, cc;

	for(i=1; i<A.size(); i++)
		for(j=1; j<B.size(); j++)
		{
			c=A[i];
			cc=B[j];
			if(A[i]==B[j])
				DP[i%2][j]=DP[(i-1)%2][j-1]+1;
			else
				DP[i%2][j]=max(DP[(i-1)%2][j], DP[i%2][j-1]);
		}
}

int main()
{
//	freopen("input.txt","r",stdin);

	init();
	filldp();
	printf("%d\n", DP[(A.size()-1)%2][B.size()-1]);

	return 0;
}
