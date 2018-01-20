#include <bits/stdc++.h>
using namespace std;
int main()
{
	char x;
	int sum=0;
	while((x=getchar())!='\n')
		sum+=x-'0';
	cout<<sum;
	return 0;
}
