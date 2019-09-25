#include "bst.h"
#include <iostream>

using namespace std;

int main()
{
	int in;
	int start = 0;
	char c;
	int n;
	cin >> in;
	int *arr = new int[in];
	BST A;
	while (start < in)
	{
		cin >> c >> n;
		if (c == 'i')
		{
			A.insert(n);
		}
		else if (c == 'd')
		{
			A.remove(n);
			arr[start] = n;
		}
		start++;
	}
	A.level();


}
