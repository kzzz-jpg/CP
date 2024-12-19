#include<bits/stdc++.h>
using namespace std;
int a[2000];
int n,k,q;
signed main(){
        cin>>n>>k>>q;
        for(int i=1;i<=k;i++) cin>>a[i];
        int l;
        while(q--){
                cin>>l;
                if(a[l]<n&&(l==k||a[l]+1<a[l+1])) a[l]++;
        }
        for(int i=1;i<=k;i++) cout<<a[i]<<' ';
}
