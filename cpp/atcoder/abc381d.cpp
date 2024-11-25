#include<bits/stdc++.h>
using namespace std;
int a[200500];
int n;
int ans;
int vs[200500];
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int l=1,r=1;l<n;l++,r=max(l,r)){
                if(r==l+1&&a[l]==a[r]) r++;
                else if(l<r) vs[l++]=0;
                while(r+1<=n&&a[r]>=1&&a[r]==a[r+1]&&!vs[a[r]]) vs[a[r]]=1,r+=2;
                ans=max(ans,r-l);
        }
        cout<<ans<<'\n';
}
