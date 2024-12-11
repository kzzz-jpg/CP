#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int vs[4000000];
int pr[800000];
int cnt=0;
void era(){
        for(int i=2;i<=3005000;i++){
                if(vs[i]) continue;
                pr[++cnt]=i;
                for(int j=i*i;j<=3005000;j+=i){
                        vs[j]=1;
                }
        }
}
int n;
int ans=0;
signed main(){
        era();
        cin>>n;
        for(int i=1;i<=cnt;i++){
                if(pr[i]*pr[i]>n) break;
                for(int j=i+1;j<=cnt;j++){
                        if(pr[i]*pr[i]*pr[j]*pr[j]<=n) ans++;
                        else break;
                }
        }
        for(int i=1;i<=80;i++){
                if(pr[i]>=100)break;
                if(pr[i]*pr[i]*pr[i]*pr[i]*pr[i]*pr[i]*pr[i]*pr[i]<=n) ans++;
                else break;
        }
        cout<<ans<<'\n';
}
