#include <bits/stdc++.h>
using namespace std;
int A[10010], B[10010];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", A + i);
    }
    B[0] = (A[0] + A[1]) / 2;
    B[n - 1] = (A[n - 1] + A[n - 2]) / 2;
    for(int i = 1; i <= n -2; ++i){
        B[i] = (A[i - 1] + A[i] + A[i + 1]) / 3;
    }
    for(int i = 0; i < n; ++i){
        printf("%d ", B[i]);
    }
    return 0;
}
