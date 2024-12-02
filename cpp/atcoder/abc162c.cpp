#include<bits/stdc++.h>
using namespace std;
int k,ans=0;
signed main(){
        cin>>k;
        for(int i=1;i<=k;i++){
                for(int j=1;j<=k;j++){
                        for(int a=1;a<=k;a++){
                                ans+=__gcd(a,__gcd(i,j));
                        }
                }
        }
        cout<<ans<<'\n';
}
