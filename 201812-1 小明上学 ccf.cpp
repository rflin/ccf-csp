#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, y, g, n;
    cin >> r >> y >> g;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int k, t;
        cin >> k >> t;
        if(k == 0) sum += t;
        else if(k == 1) sum += t;
        else if(k == 2) sum += t + r;
        else if(k == 3) sum += 0;
    }
    cout << sum;
    return 0;
}
