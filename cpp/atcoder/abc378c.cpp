#include<bits/stdc++.h>
using namespace std;
int n,a;
map<int,int> mp;
signed main(){
    cin>>n;
    for(int i=2;i<=n+1;i++){
        cin>>a;
        cout<<mp[a]-1<<' ';
        mp[a]=i;
    }
}