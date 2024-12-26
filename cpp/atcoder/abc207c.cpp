#include<bits/stdc++.h>
#define int long long
using namespace std;
struct ln{
        int l,r;
        bool operator<(ln o) const{
                if(l==o.l) return r<o.r;
                return l<o.l;
        }
} a[2500];
int n;
int t;
int ans=0;
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++){
                cin>>t>>a[i].l>>a[i].r;
                a[i].l*=10,a[i].r*=10;
                if(t==2) a[i].r-=5;
                else if(t==3) a[i].l+=5;
                else if(t==4) a[i].l+=5,a[i].r-=5;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                        if(a[j].l<=a[i].r) ans++;
                }
        }
        cout<<ans<<'\n';
}
