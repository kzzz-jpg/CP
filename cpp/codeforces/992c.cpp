#include<bits/stdc++.h>
#define int long long
using namespace std;
int fr[200500];
int bk[200500];
int cnt1,cnt2;
void solve(){
    int n,k,tmpn;
    cnt1=cnt2=1;
    cin>>n>>k;
    if(n==1&&k==1) return cout<<1<<'\n',void();
    tmpn=n;
    if(n<60&& k>(1LL<<(n-1))) return cout<<-1<<'\n',void();
    n--,k--;
    while(k){
        if(k&1) bk[cnt2++]=n--;
        else fr[cnt1++]=n--;
        k>>=1;
    }
    while(n){
        fr[cnt1++]=n--;
    }
    for(int i=cnt1-1;i;i--) cout<<fr[i]<<' ';
    cout<<tmpn<<' ';
    for(int i=1;i<cnt2;i++) cout<<bk[i]<<' ';
    cout<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve(); 
}