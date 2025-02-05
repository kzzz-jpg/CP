#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,L,K,a[200500],b[200500];
bool chk(int x){
    int sum=0;
    for(int i=1,r=0;r<=n;sum-=b[i]*x+a[i],i++){
        while(r-i+1<L) sum+=b[r+1]*x+a[++r];
        if(r>n) break;
        if(sum<K) {
            return 0;
        }
    }
    return 1;
}
bool chk2(int x){
    for(int i=1;i+L-1<=n;i++){
        int sum=0;
        for(int j=i;j-i+1<=L;j++){
            sum+=a[j]+b[j]*x;
        }
        if(sum<K) return 0;
    }
    return 1;
}
signed main(){
    //cin>>n>>L>>K;
    //for(int i=1;i<=n;i++) cin>>a[i];
    //for(int i=1;i<=n;i++) cin>>b[i];
    //int l=0,r=1e12+10;
    //while(l<r){
    //    int mid=(l+r)>>1;
    //    if(chk2(mid)) r=mid;
    //    else l=mid+1;
    //}
    //if(l==1e12+10) cout<<"No Solution\n";
    //else cout<<l<<'\n';
    if(!chk2(1e12+10)) {
        cout<<"No Solution\n";
        return 0;
    }
    for(int i=0;i<=1e12;i++){
        if(chk2(i)) {
            cout<<i<<'\n';
            return 0;
        }
    }
}