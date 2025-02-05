#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m;
vector<string> a;
int trie[1000010][10];
int cnt=1;
int tr[1000010];
void insrt(string &s){
    int nw=0;
    for(int i=0;i<m;i++){
        if(trie[nw][s[i]-'0']==0){
            trie[nw][s[i]-'0']=cnt++;
        }
        nw=trie[nw][s[i]-'0'];
        tr[nw]++;
    }
}
int qry(string &s){
    int ret=0,nw=0;
    for(int i=0;i<m;i++){
        ret=max(tr[nw]+i,ret);
        nw=trie[nw][s[i]-'0'];
    }
    ret=max(tr[nw]+m,ret);
    return ret;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        insrt(a[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<qry(a[i])<<'\n';
    }
}