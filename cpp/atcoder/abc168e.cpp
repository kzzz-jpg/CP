#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int fp(int x,int y=P-2){
        int ret=1;
        while(y){
                if(y&1) ret=(ret*x)%P;
                x=(x*x)%P;
                y>>=1;
        }
        return ret;
}
map<int,vector<int>> mp;
struct nd{
        int a,b;
} a[200500];
int n;
int ans=0;
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) {
                cin>>a[i].a>>a[i].b;
                mp[-(a[i].b%P*fp(a[i].a%P)%P)].push_back(i);
        }
        for(auto x:mp){
                sort(x.second.begin(),x.second.end());
        }
        for(int i=1;i<=n;i++){
                auto &it=mp[a[i].a%P*fp(a[i].b%P)%P];
                ans=(ans+fp(2,(n-i)-(it.end()-upper_bound(it.begin(),it.end(),i))))%P;
        }
        cout<<ans<<'\n';
}
