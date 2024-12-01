#include<bits/stdc++.h>
#define int long long
using namespace std;

random_device rd;
mt19937 rg(rd());
struct game{
    int op,mmr;
} a[3050];
int ls[3050];
int cnt;
int n,mmr;
int anspos=1,ans;
int calc(int gt){
    if(ls[gt]==0) gt=0;
    else gt=ls[gt];
    int ret=mmr;
    for(int i=1;i<=n;i++){
        if(a[i].op==1||i==gt){
            ret+=max((int)((a[i].mmr-ret)*5/100)+25,1LL);
        }else{
            ret+=min(0LL,(int)((a[i].mmr-ret)*5/100)-25);
        }
    }
    return ret;
}
void sa(){
    double T=3000,ed=1e-6,low=0.9812;
    for(;T>ed;T*=low){
        int tmp=anspos;
        anspos=((int)(anspos+(rg()%6000000*T)))%cnt+1;
        int nw=calc(anspos);
        if(nw>ans) ans=nw;
        else if(exp((nw-ans)/T)>(double(rg()))/(rg.max())){
            anspos=tmp;
        }
    }
}
signed main(){
    cin>>n>>mmr;
    for(int i=1;i<=n;i++){
        cin>>a[i].op>>a[i].mmr;
        if(a[i].op==0) ls[++cnt]=i;
    }
    cnt++;
    while(double(clock())/CLOCKS_PER_SEC<0.8) sa();
    cout<<ans<<'\n';
}