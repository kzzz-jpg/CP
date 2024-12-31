#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200500];
int v[200500];
int len,k;
int ans[200500];
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],v[i]=a[i];
        sort(v+1,v+1+n);
        len=unique(v+1,v+1+n)-v-1;
        for(int i=1;i<=n;i++){
                int it=v+len-lower_bound(v+1,v+1+len,a[i]);
                ans[it]++;
        }
        for(int i=0;i<n;i++){
                cout<<ans[i]<<'\n';
        }
}
