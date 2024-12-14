#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[100500];
int pre[100500];
int ans=0;
signed main(){
        cin>>n>>m; 
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n,greater<int>());
        for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
        for(int i=1;i<=n;i++){
                if(m>=2*(n-i+1)-1){
                        ans+=2*(pre[n]-pre[i-1])-a[i];
                        ans+=2*a[i]*(n-i+1)-a[i];
                        m-=2*(n-i+1)-1;
                }else{
                        for(int j=i;j<=n;j++){
                                if(m==0) break;
                                if(j==i){
                                        ans+=a[i]+a[i];
                                        m--;
                                }
                                else if(m>=2){
                                        ans+=a[i]+a[j]+a[i]+a[j];
                                        m-=2;
                                }
                                else if(m==1){
                                        ans+=a[i]+a[j];
                                        m-=1;
                                }
                        }
                }
        }
        cout<<ans<<'\n';
}
