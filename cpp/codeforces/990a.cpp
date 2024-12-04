#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isp(int x){
        for(int i=1;i<=201;i+=2) if(i*i==x) return 1;
        return 0;
}
void solve(){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int nw=0,ans=0;
        for(int i=0;i<n;i++){
                nw+=a[i];
                if(isp(nw)){
                        ans++;
                }
        }
        cout<<ans<<'\n';

}
signed main(){
        int t;
        cin>>t;
        while(t--)solve();
}
