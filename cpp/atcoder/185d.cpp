#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200500];
int b[200500];
int mn=1e15;
int ans;
signed main(){
        cin>>n>>m;
        for(int i=1;i<=m;i++) cin>>a[i];
        sort(a+1,a+1+m);
        a[0]=0,a[m+1]=n+1;
        for(int i=1;i<=m+1;i++){
                b[i]=a[i]-a[i-1]-1;
                if(b[i]) mn=min(mn,b[i]);
        }
        for(int i=1;i<=m+1;i++){
                ans+=b[i]/mn+(b[i]%mn!=0);
        }
        cout<<ans<<'\n';
}
