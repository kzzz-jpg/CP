#include<bits/stdc++.h>
using namespace std;
struct nd{
    string s;
    int scr;
    nd(string S,int sc):s(S),scr(sc){}
    bool operator<(nd o) const{
        if(scr==o.scr) return s<o.s;
        return scr>o.scr;
    }
};
vector<nd> ans;
int a[6];
void dfs(int i,string &s,int scr){
    if(i>5){
        ans.emplace_back(s,scr);
        return;
    }
    s.push_back('A'+i-1);
    dfs(i+1,s,scr+a[i]);
    s.pop_back();
    dfs(i+1,s,scr);
}
signed main(){
    cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
    string s;
    dfs(1,s,0);
    sort(ans.begin(),ans.end());
    for(auto x:ans) cout<<x.s<<'\n';
}