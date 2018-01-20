#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v(20,5);
	for(int i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		for(int r=0;r<20&&x>0;++r)
		{
			if(v[r]>=x)//当前行空余座位大于需求x
			{
				int seat=r*5+5-v[r]+1;//开始空闲座位编号
				v[r]-=x;//x个订购，更新空余座位
				while(x--)
				{
					cout<<seat++;
					if(x>0) cout<<" ";
					else cout<<endl;
				}
			}
		}
		if(x>0)//没有连续座位
		{
			for(int r=0;r<20&&x>0;++r)
			{
				while(v[r]>0&&x>0)
				{
					int seat=r*5+5-v[r]+1;
					cout<<seat++;
					--v[r];
					--x;
					if(x>0)cout<<" ";
					else cout<<endl;
				}
			}
		}
	}
	return 0;
}
