#include<bits/stdc++.h>
using namespace std;
int cnt=0;
vector<vector<int>> trie(2005000,vector<int> (26,0)),g(2000500);
vector<int> ed(2005000),fail(2000500,0),ti(2000500,0);
void insrt(int i,string s){
    int u=0;
    for(auto x:s){
        if(trie[u][x-'a']==0){
            trie[u][x-'a']=++cnt;
        }
        u=trie[u][x-'a'];
    }
    ed[i]=u;
    return;
}
void setF(){
    queue<int> q;
    for(int i=0;i<26;i++){
        if(trie[0][i]) q.push(trie[0][i]);
    }
    while(q.size()){
        auto tp=q.front();q.pop();
        for(int i=0;i<26;i++){
            if(trie[tp][i]==0){
                trie[tp][i]=trie[fail[tp]][i];
            }else{
                fail[trie[tp][i]]=trie[fail[tp]][i];
                q.push(trie[tp][i]);
            }
        }
    }
}
void dfs(int x,int par){
    for(auto u:g[x]){
        if(u!=par){
            dfs(u,x);
            ti[x]+=ti[u];
        }
    }
}
int main(){
    string a,b;
    cin>>a>>b;
    insrt(1,b);
    setF();
    int nw=0;
    for(auto x:a){
        nw=trie[nw][x-'a'];
        ti[nw]++;
    }
    for(int i=1;i<=cnt;i++){
        g[fail[i]].push_back(i);
    }
    dfs(0,0);
    cout<<ti[ed[1]]<<'\n';
}
