#include<bits/stdc++.h>
using namespace std;
int n,a[200500],ans;
int neg;
int tw1,pos1,tw2,pos2;
void solve(){
    cin>>n;
    neg=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]<0) neg++; 
    }
    if(neg%2==0) return cout<<0<<' '<<0<<'\n',void();
    tw1=0;
    for(int i=1;i<=n;i++){
        if(a[i]==2) tw1++;
        if(a[i]==-1){
            pos1=i;
            break;
        }
        if(a[i]==-2){
            tw1++;
            pos1=i;
            break;
        }
    }
    tw2=0;
    for(int i=n;i;i--){
        if(a[i]==2) tw2++;
        if(a[i]==-1){
            pos2=n-i+1;
            break;
        }
        if(a[i]==-2){
            tw2++;
            pos2=n-i+1;
            break;
        }
    }
    if(tw1>tw2||(tw1==tw2&&pos2<pos1)) cout<<0<<' '<<pos2<<'\n';
    else cout<<pos1<<' '<<0<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}