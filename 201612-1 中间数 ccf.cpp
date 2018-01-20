#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	vector<int> v;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int j=v.size()/2,i=(v.size()%2==0)?j-1:j;
	int e=v[j];
	while(i>=0&&j<n&&v[i]==v[j]&&v[i]==e)--i,++j;
	if(i>=0&&(v[i]==e||v[j]==e))
		cout<<-1;
	else cout<<e;
	return 0;
}
