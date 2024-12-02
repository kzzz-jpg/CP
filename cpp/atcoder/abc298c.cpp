#include<bits/stdc++.h>
using namespace std;
int n,q;
set<pair<int,int>> s[200500];
set<int> chk[200500];
signed main(){
    cin>>n>>q;
    vector<set<pair<int,int>>> s(n+1);
    int op,x,y;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>x>>y;
            auto it=s[y].lower_bound({x,0});
            if(it==s[y].end()||it->first!=x) s[y].insert({x,1}),chk[x].insert(y);
            else{
                int tm=it->second;
                s[y].erase(it);
                s[y].insert({x,tm+1});
            }
        }else if(op==2){
            cin>>y;
            for(auto xx:s[y]){
                for(int i=0;i<xx.second;i++) cout<<xx.first<<' ';
            }
            cout<<'\n';
        }else{
            cin>>y;
            for(auto xx:chk[y]){
                cout<<xx<<' ';
            }
            cout<<'\n';
        }
    }
}
