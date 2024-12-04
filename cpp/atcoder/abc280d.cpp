#include<bits/stdc++.h>
#define int long long
using namespace std;
int k;
int clac(int x,int y){
        int tmp=x*x;
        for(int i=1;tmp<x*y;y-=i,i++,tmp*=x);
        return x*y;
}
signed main(){
        cin>>k;
        int ans=0;
        int t=k;
        for(int i=2;i<sqrt(t)+10;i++){
                if(k%i==0){
                        int cnt=0;
                        while(k%i==0) cnt++,k/=i;
                        ans=max(ans,clac(i,cnt));
                }
        }
        if(ans==0) cout<<t<<'\n';
        else cout<<ans<<'\n';
}
