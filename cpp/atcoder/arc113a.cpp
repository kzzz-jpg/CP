#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0;
int n;
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++){
                for(int j=1;i*j<=n;j++){
                        ans+=max(1LL,n/(i*j));
                }
        }
        cout<<ans<<'\n';
}
