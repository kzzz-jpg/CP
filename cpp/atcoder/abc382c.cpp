#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200500];
signed main(){
        cin>>n>>m;
        a[0]=9999999;
        for(int i=1;i<=n;i++){
                cin>>a[i];
                a[i]=min(a[i],a[i-1]);
        }
        int t;
        while(m--){
                cin>>t;
                int ans=0;
                if(t<a[n]){
                        cout<<-1<<'\n';
                        continue;
                }
                for(int j=n;j;j>>=1){
                        while(ans+j<=n&&a[ans+j]>t) ans+=j;
                }
                cout<<ans+1<<'\n';
        }
}
