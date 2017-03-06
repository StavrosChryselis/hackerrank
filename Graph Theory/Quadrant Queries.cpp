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
#include <algorithm>

using namespace std;

typedef struct
{
	int q1, q2, q3, q4;
	bool lazyx, lazyy;

	inline void flipx()
	{
		swap(q1, q4);
		swap(q2, q3);
	}

	inline void flipy()
	{
		swap(q1, q2);
		swap(q3, q4);
	}

}seg;

typedef struct
{
	int q1, q2, q3, q4;
}q_s;

inline q_s merge(const q_s &a, const q_s &b)
{
	q_s ans;

	ans.q1 = a.q1 + b.q1;
	ans.q2 = a.q2 + b.q2;
	ans.q3 = a.q3 + b.q3;
	ans.q4 = a.q4 + b.q4;

	return ans;
}

seg tree[4 * 100007];
int N, Q;
int A[100007];

void init_tree(int node, int a, int b)
{
	if (a == b)
	{
		switch (A[a])
		{
		case 1:
			tree[node].q1++;
			break;
		case 2:
			tree[node].q2++;
			break;
		case 3:
			tree[node].q3++;
			break;
		case 4:
			tree[node].q4++;
			break;
		}

		return;
	}

	init_tree(node * 2, a, (a + b) / 2);
	init_tree(node * 2 + 1, (a + b) / 2 + 1, b);

	tree[node].q1 = tree[node * 2].q1 + tree[node * 2 + 1].q1;
	tree[node].q2 = tree[node * 2].q2 + tree[node * 2 + 1].q2;
	tree[node].q3 = tree[node * 2].q3 + tree[node * 2 + 1].q3;
	tree[node].q4 = tree[node * 2].q4 + tree[node * 2 + 1].q4;
}

void refX(int node, int a, int b, int i, int j)
{
	if (tree[node].lazyx)
	{
		tree[node].flipx();
		if (a != b)
		{
			tree[node * 2].lazyx = !tree[node * 2].lazyx;
			tree[node * 2 + 1].lazyx = !tree[node * 2 + 1].lazyx;
		}

		tree[node].lazyx = 0;
	}

	if (tree[node].lazyy)
	{
		tree[node].flipy();
		if (a != b)
		{
			tree[node * 2].lazyy = !tree[node * 2].lazyy;
			tree[node * 2 + 1].lazyy = !tree[node * 2 + 1].lazyy;
		}

		tree[node].lazyy = 0;
	}

	if (a == i && b == j)
	{
		tree[node].flipx();

		if (a != b)
		{
			tree[node * 2].lazyx = !tree[node * 2].lazyx;
			tree[node * 2 + 1].lazyx = !tree[node * 2 + 1].lazyx;
		}

		return;
	}

	if (j <= (a + b) / 2)
		refX(2 * node, a, (a + b) / 2, i, j);
	else if (i > (a + b) / 2)
		refX(2 * node + 1, (a + b) / 2 + 1, b, i, j);
	else
	{
		refX(2 * node, a, (a + b) / 2, i, (a + b) / 2);
		refX(2 * node + 1, (a + b) / 2 + 1, b, (a + b) / 2 + 1, j);
	}

	int mid = (a + b) / 2;

	tree[node].q1 = tree[node].q2 = tree[node].q3 = tree[node].q4 = 0;

	//LEFT
	if (tree[node * 2].lazyx && tree[node * 2].lazyy)
	{
		tree[node].q1 += tree[node * 2].q3;
		tree[node].q2 += tree[node * 2].q4;
		tree[node].q3 += tree[node * 2].q1;
		tree[node].q4 += tree[node * 2].q2;
	}

	else if (tree[node * 2].lazyx)
	{
		tree[node].q1 += tree[node * 2].q4;
		tree[node].q2 += tree[node * 2].q3;
		tree[node].q3 += tree[node * 2].q2;
		tree[node].q4 += tree[node * 2].q1;
	}

	else if (tree[node * 2].lazyy)
	{
		tree[node].q1 += tree[node * 2].q2;
		tree[node].q2 += tree[node * 2].q1;
		tree[node].q3 += tree[node * 2].q4;
		tree[node].q4 += tree[node * 2].q3;
	}

	else
	{
		tree[node].q1 += tree[node * 2].q1;
		tree[node].q2 += tree[node * 2].q2;
		tree[node].q3 += tree[node * 2].q3;
		tree[node].q4 += tree[node * 2].q4;
	}

	//RIGHT

	if (tree[node * 2 + 1].lazyx && tree[node * 2 + 1].lazyy)
	{
		tree[node].q1 += tree[node * 2 + 1].q3;
		tree[node].q2 += tree[node * 2 + 1].q4;
		tree[node].q3 += tree[node * 2 + 1].q1;
		tree[node].q4 += tree[node * 2 + 1].q2;
	}

	else if (tree[node * 2 + 1].lazyx)
	{
		tree[node].q1 += tree[node * 2 + 1].q4;
		tree[node].q2 += tree[node * 2 + 1].q3;
		tree[node].q3 += tree[node * 2 + 1].q2;
		tree[node].q4 += tree[node * 2 + 1].q1;
	}

	else if (tree[node * 2 + 1].lazyy)
	{
		tree[node].q1 += tree[node * 2 + 1].q2;
		tree[node].q2 += tree[node * 2 + 1].q1;
		tree[node].q3 += tree[node * 2 + 1].q4;
		tree[node].q4 += tree[node * 2 + 1].q3;
	}

	else
	{
		tree[node].q1 += tree[node * 2 + 1].q1;
		tree[node].q2 += tree[node * 2 + 1].q2;
		tree[node].q3 += tree[node * 2 + 1].q3;
		tree[node].q4 += tree[node * 2 + 1].q4;
	}

}

void refY(int node, int a, int b, int i, int j)
{
	if (tree[node].lazyx)
	{
		tree[node].flipx();
		if (a != b)
		{
			tree[node * 2].lazyx = !tree[node * 2].lazyx;
			tree[node * 2 + 1].lazyx = !tree[node * 2 + 1].lazyx;
		}

		tree[node].lazyx = 0;
	}

	if (tree[node].lazyy)
	{
		tree[node].flipy();
		if (a != b)
		{
			tree[node * 2].lazyy = !tree[node * 2].lazyy;
			tree[node * 2 + 1].lazyy = !tree[node * 2 + 1].lazyy;
		}

		tree[node].lazyy = 0;
	}

	if (a == i && b == j)
	{
		tree[node].flipy();

		if (a != b)
		{
			tree[node * 2].lazyy = !tree[node * 2].lazyy;
			tree[node * 2 + 1].lazyy = !tree[node * 2 + 1].lazyy;
		}

		return;
	}

	if (j <= (a + b) / 2)
		refY(2 * node, a, (a + b) / 2, i, j);
	else if (i > (a + b) / 2)
		refY(2 * node + 1, (a + b) / 2 + 1, b, i, j);
	else
	{
		refY(2 * node, a, (a + b) / 2, i, (a + b) / 2);
		refY(2 * node + 1, (a + b) / 2 + 1, b, (a + b) / 2 + 1, j);
	}

	tree[node].q1 = tree[node].q2 = tree[node].q3 = tree[node].q4 = 0;

	//LEFT
	if (tree[node * 2].lazyx && tree[node * 2].lazyy)
	{
		tree[node].q1 += tree[node * 2].q3;
		tree[node].q2 += tree[node * 2].q4;
		tree[node].q3 += tree[node * 2].q1;
		tree[node].q4 += tree[node * 2].q2;
	}

	else if (tree[node * 2].lazyx)
	{
		tree[node].q1 += tree[node * 2].q4;
		tree[node].q2 += tree[node * 2].q3;
		tree[node].q3 += tree[node * 2].q2;
		tree[node].q4 += tree[node * 2].q1;
	}

	else if (tree[node * 2].lazyy)
	{
		tree[node].q1 += tree[node * 2].q2;
		tree[node].q2 += tree[node * 2].q1;
		tree[node].q3 += tree[node * 2].q4;
		tree[node].q4 += tree[node * 2].q3;
	}

	else
	{
		tree[node].q1 += tree[node * 2].q1;
		tree[node].q2 += tree[node * 2].q2;
		tree[node].q3 += tree[node * 2].q3;
		tree[node].q4 += tree[node * 2].q4;
	}

	//RIGHT

	if (tree[node * 2 + 1].lazyx && tree[node * 2 + 1].lazyy)
	{
		tree[node].q1 += tree[node * 2 + 1].q3;
		tree[node].q2 += tree[node * 2 + 1].q4;
		tree[node].q3 += tree[node * 2 + 1].q1;
		tree[node].q4 += tree[node * 2 + 1].q2;
	}

	else if (tree[node * 2 + 1].lazyx)
	{
		tree[node].q1 += tree[node * 2 + 1].q4;
		tree[node].q2 += tree[node * 2 + 1].q3;
		tree[node].q3 += tree[node * 2 + 1].q2;
		tree[node].q4 += tree[node * 2 + 1].q1;
	}

	else if (tree[node * 2 + 1].lazyy)
	{
		tree[node].q1 += tree[node * 2 + 1].q2;
		tree[node].q2 += tree[node * 2 + 1].q1;
		tree[node].q3 += tree[node * 2 + 1].q4;
		tree[node].q4 += tree[node * 2 + 1].q3;
	}

	else
	{
		tree[node].q1 += tree[node * 2 + 1].q1;
		tree[node].q2 += tree[node * 2 + 1].q2;
		tree[node].q3 += tree[node * 2 + 1].q3;
		tree[node].q4 += tree[node * 2 + 1].q4;
	}

}

q_s query(int node, int a, int b, int i, int j)
{
	if (tree[node].lazyx)
	{
		tree[node].flipx();
		if (a != b)
		{
			tree[node * 2].lazyx = !tree[node * 2].lazyx;
			tree[node * 2 + 1].lazyx = !tree[node * 2 + 1].lazyx;
		}

		tree[node].lazyx = 0;
	}

	if (tree[node].lazyy)
	{
		tree[node].flipy();
		if (a != b)
		{
			tree[node * 2].lazyy = !tree[node * 2].lazyy;
			tree[node * 2 + 1].lazyy = !tree[node * 2 + 1].lazyy;
		}

		tree[node].lazyy = 0;
	}

	if (a == i && b == j)
	{
		q_s ans;

		ans.q1 = tree[node].q1;
		ans.q2 = tree[node].q2;
		ans.q3 = tree[node].q3;
		ans.q4 = tree[node].q4;

		return ans;
	}

	if (j <= (a + b) / 2)
		return query(node * 2, a, (a + b) / 2, i, j);

	if (i >= (a + b) / 2 + 1)
		return query(node * 2 + 1, (a + b) / 2 + 1, b, i, j);

	return merge(query(2 * node, a, (a + b) / 2, i, (a + b) / 2), query(2 * node + 1, (a + b) / 2 + 1, b, (a + b) / 2 + 1, j));
}

inline void init()
{
	int i;
	int x, y;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &x, &y);

		if (x < 0)
		{
			if (y < 0)
				A[i] = 3;
			else
				A[i] = 2;
		}

		else
		{
			if (y < 0)
				A[i] = 4;
			else
				A[i] = 1;
		}
	}

	init_tree(1, 1, N);

	scanf("%d\n", &Q);
}

inline void print_query(const q_s &a)
{
	printf("%d %d %d %d\n", a.q1, a.q2, a.q3, a.q4);
}

inline void command()
{
	char c;
	int i, j;

	scanf("%c %d %d\n", &c, &i, &j);

	switch (c)
	{
	case 'X':
		refX(1, 1, N, i, j);
		break;
	case 'Y':
		refY(1, 1, N, i, j);
		break;
	case 'C':
		print_query(query(1, 1, N, i, j));
		break;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	while (Q--)
		command();

	return 0;
}
