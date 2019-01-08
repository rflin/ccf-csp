#include <bits/stdc++.h>
using namespace std;

int day2[400], day1[400], n;
bool isfind = 0, isvis[400][400][400];
void dfs(int i, int cur, int pre){
	if(isvis[i][cur][pre]) return;//当前状态已经搜索过，进行剪枝
	isvis[i][cur][pre] = 1;
	day1[i] = cur;
	if(i == n){
		if((day1[n - 1] + day1[n]) / 2 == day2[n]) isfind = 1;//核对最后一天
		return;
	}
	int next = 3*day2[i] - pre - cur;//对第i天，如果该天cur，以及昨天pre确定，那么下一天有3种情况
	for(int k = 0; k < 3; ++k){//0, 1, 2
		if(next + k > 0 && !isfind){//注意next必须为正整数
			dfs(i + 1, next + k, cur);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", day2 + i);
	}
	for(int e = 1; e <= 2*day2[1]; ++e){
		day1[1] = e;//第一天确定，那么第二天也能确定，有两种情况
		dfs(2, 2*day2[1] - e, day1[1]);
		if(!isfind) dfs(2, 2*day2[1] - e + 1, e);
		else break;
	}
	for(int i = 1; i <= n; ++i){
		printf("%d ", day1[i]);
	}
	return 0;
}
