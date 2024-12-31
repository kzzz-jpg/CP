#include<bits/stdc++.h>
using namespace std;
map<int,int> col;
int a[300500];
int n,k,ans,nw;
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<k;i++) if(col[a[i]]++==0) nw++;
    for(int l=1,r=k;r<=n;r++){
        if(col[a[r]]++==0) nw++;
        ans=max(ans,nw);
        if(--col[a[l++]]==0) nw--;
    }
    cout<<ans<<'\n';
}