#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define chungAC ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MI 1<<30
int n,m;
int p[1000001];
bool cansuc(int a){
    int blod=a;
    int mm=m;
    for(int i=0;i<n;i++){
        if(blod<p[i]){
            if(mm<=0||a<p[i]) return false;
            blod=a;
            mm--;
        }
        blod-=p[i];
    }
    return true;
}
signed main(){
    chungAC
    cin>>n>>m;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>p[i];
        sum+=p[i];
    }
    int ans=0;
    for(int j=sum;j>0;j>>=1){
        while(ans+j<=sum&&!cansuc(ans+j)){
            ans+=j;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}