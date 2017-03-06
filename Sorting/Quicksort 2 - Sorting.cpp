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
#include <vector>
#include <iostream>

using namespace std;

void quickSort(vector <int> &arr)
{
	vector<int> left, right;
	int pivot, i;

	if (arr.size() <= 1)
		return;

	pivot = arr[0];

	for (i = 1; i < arr.size(); i++)
	{
		if (arr[i] < pivot)
			left.push_back(arr[i]);
		else
			right.push_back(arr[i]);
	}

	quickSort(left);
	quickSort(right);

	int curr = 0;

	for (i = 0; i < left.size(); i++)
	{
		arr[curr++] = left[i];
		printf("%d ", arr[curr - 1]);
	}

	arr[curr++] = pivot;
	printf("%d ", pivot);

	for (i = 0; i < right.size(); i++)
	{
		arr[curr++] = right[i];
		printf("%d ", arr[curr - 1]);
	}

	puts("");
}

int main()
{
	int n;
	
	cin >> n;

	vector <int> arr(n);
	for (int i = 0; i < (int)n; ++i) {
		cin >> arr[i];
	}

	quickSort(arr);

	return 0;
}
