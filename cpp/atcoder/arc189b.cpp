#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200500];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i+3<=n;i++){
        int mid=a[i]+a[i+3];
        int o1,o2;
        o1=a[i+2]-(a[i+2]*2-mid);
        o2=a[i+1]-(a[i+1]*2-mid);
        if(o1+o2<a[i+1]+a[i+2]){
            a[i+1]=o1,a[i+2]=o2;
        }else if(o1+o2==a[i+1]+a[i+2]&&o1<a[i+1]){
            a[i+1]=o1,a[i+2]=o2;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=a[i];
    cout<<ans<<'\n';
}