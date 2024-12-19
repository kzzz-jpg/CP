#include<bits/stdc++.h>
using namespace std;
int fp(int x,int y,int p){
        if(x==0) return 0;
        int ret=1;
        while(y){
                if(y&1)ret=(ret*x)%p;
                x=(x*x)%p;
                y>>=1;
        }
        return ret;
}
int ans=0;
map<pair<int,int>,int> mp;
signed main(){
        int p;
        cin>>p;
        for(int i=0;i<p;i++){
                for(int j=0;j<p;j++){
                        int ret=fp(i,j,p);
                        if(mp[make_pair(i,ret)]==0) cerr<<i<<' '<<ret<<'\n',ans++,mp[make_pair(i,ret)]=1;
                }
        }
        cout<<ans<<'\n';
}
