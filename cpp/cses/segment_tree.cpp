#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> vis;
void bfs(){
    stack<int> q;
    vector<int> dis;
    q.push(s);
    while(!q.empty()){
        int tp=q.top();
        q.pop();
        for(auto x:g[tp]){
           if(!dis[ x]){
                q.push(x);
                dis[x]=dis[tp]+1;
            }
        }
    }
}
void dfs(int x){
    vis[x]=true;
    for(auto y:g[x]){
        if(!vis[x]) dfs(y);
    }
}