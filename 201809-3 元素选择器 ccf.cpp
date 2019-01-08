#include <bits/stdc++.h>
using namespace std;
struct node{
    int r, lev;//r:行索引，唯一标识；lev:层次序，用于建树
    string label, id;
};
int n, m;
vector<node> v;//输入节点数据
vector<int> vx[128];//邻接表
void convert(string &s){
    if(s[0] == '#') return;
    for(char &x : s) x = tolower(x);
}
void mk(string &s, int i){//创建节点
    int dotnums = 0;
    while(s[dotnums] == '.') ++dotnums;
    v[i].lev = dotnums / 2;
    v[i].r = i;
    size_t p = s.find(" ");
    if(p != string::npos){//包含属性id
        v[i].label = s.substr(dotnums, p - dotnums);
        v[i].id = s.substr(p + 1);
    }else{//不包含
        v[i].label = s.substr(dotnums);
        v[i].id = "";
    }
    convert(v[i].label);
}
vector<string> split(string &s){
    vector<string> vs;
    s += " ";
    size_t p;
    while((p = s.find(" ", 0)) != string::npos){
        vs.push_back(s.substr(0, p));
        s = s.substr(p + 1);
        convert(vs.back());
    }
    return vs;
}
void dfs(int i, string &s, map<int, int> &res){//找到以i为根，后代节点中label或者id等于s的行索引
    for(int k : vx[i]){
        if(v[k].label == s || v[k].id == s) res[k] = 1;
        dfs(k, s, res);
    }
}
int main()
{
    //freopen("1.txt", "r", stdin);
    cin >> n >> m;
    getchar();
    v.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        string s;
        getline(cin, s);
        mk(s, i);
    }
    int i = n;
    while(i >= 1){//建树
        int j = i - 1;
        while(j >= 1 && v[j].lev >= v[i].lev) --j;
        vx[j].push_back(i);
        --i;
    }
    while(m--){
        string s;
        getline(cin, s);
        vector<string> vs = split(s);
        map<int, int> res;
        dfs(0, vs[0], res);
        int L = vs.size(), i = 1;
        while(i < L){
            map<int, int> temp = res, vsum;
            for(auto x : temp){
                res.clear();
                dfs(x.first, vs[i], res);
                for(auto y : res) vsum[y.first] = 1;
            }
            res = vsum;++i;
        }
        cout << res.size();
        for(auto x : res) cout << " " << x.first;
        cout << endl;
    }
    return 0;
}
