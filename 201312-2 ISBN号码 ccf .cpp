#include <bits/stdc++.h>
using namespace std;
char val(int x)
{
    return x%11==10?'X':'0'+x%11;
}
int main()
{
    char ch,ibsn[16];
    int k=0,sum=0,cnt;
    while((ch=cin.get())!='\n')
    {
        ibsn[k++]=ch;
        if(isdigit(ch))
        {
            ++cnt;
            if(cnt<=9) sum+=(ch-'0')*cnt;
        }
    }
    ibsn[k]='\0';
    char x=val(sum);
    if(ibsn[k-1]==x)
        printf("Right\n");
    else
    {
        ibsn[k-1]=x;
        printf("%s\n",ibsn);
    }
    return 0;
}
