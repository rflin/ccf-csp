#include <bits/stdc++.h>
using namespace std;
int a[10000000];
void rd(int n){
	for(int i = 0; i < n; ++i){
		int l, r;
		scanf("%d %d", &l, &r);
		while(l < r) a[l++]++; 
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	rd(n);
	rd(n);
	int sum;
	for(int i = 1; i < 1000000; ++i){
		if(a[i] == 2) ++sum;
	}
	printf("%d\n", sum);
	return 0;
}
