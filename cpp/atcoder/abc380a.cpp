#include<bits/stdc++.h>
using namespace std;
char c[6];
map<char,int> mp;
signed main(){
        for(int i=0;i<6;i++) cin>>c[i],mp[c[i]]++;
        if(mp['1']==1&&mp['2']==2&&mp['3']==3) cout<<"Yes\n";
        else cout<<"No\n";
}
