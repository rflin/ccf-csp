#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
    if(n<50)
        return n<30?n/10:4+(n-30)/10;
    return max(4+solve(n-30),7+solve(n-50));
}
int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}
