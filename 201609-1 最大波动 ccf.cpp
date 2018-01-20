#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,maxval=0;
	vector<int> v;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	for(int i=1;i<n;++i)
		maxval=max(maxval,abs(v[i]-v[i-1]));
	cout<<maxval<<endl;
	return 0;
}
