#include<bits/stdc++.h>
using namespace std;
int n,m,a[13];
vector<vector<int>> ans;
void dfs(int i,int s){
        if(s+(n-i)*10>m) return;
        if(i>n){
                ans.push_back({});
                for(int j=1;j<=n;j++) ans.back().push_back(a[j]);
                return;
        }
        for(int j=s;j<=10*n;j++){
                a[i]=j;
                dfs(i+1,j+10);
        }
}
signed main(){
        cin>>n>>m;
        dfs(1,1);
        cout<<ans.size()<<'\n';
        for(auto x:ans){
                for(auto y:x) cout<<y<<' ';
                cout<<'\n';
        }
}
