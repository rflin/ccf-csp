#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums;
    int x;
    while(scanf("%d",&x)==1&&x){
        nums.push_back(x);
    }
    int n=nums.size();
    for(int i=0,j=1;j<n;++i,++j){
        if(!(nums[j]&1)&&!(nums[i]&1)){
            nums[j]+=nums[i];
        }
    }
    int scores=accumulate(nums.begin(),nums.end(),0);
    printf("%d\n",scores);
    return 0;
}
