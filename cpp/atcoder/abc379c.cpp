#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum,ans;
struct pt{
    int pos,v;
    bool operator<(pt o) const{
        return pos<o.pos;
    }
} a[200500];
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i].pos;
    for(int i=1;i<=m;i++) cin>>a[i].v,sum+=a[i].v;
    sort(a+1,a+1+m);
    if(a[1].pos!=1||sum!=n) return cout<<-1<<'\n',0;
    for(int i=2;i<=m;i++){
        int len=a[i].pos-a[i-1].pos;
        if(a[i-1].v<len) return cout<<-1<<'\n',0;
        ans+=(a[i-1].v-1)*len-len*(len-1)/2;
        a[i].v+=a[i-1].v-len;
    }
    if(a[m].pos==n) cout<<ans<<'\n';
    else{
        int len=n-a[m].pos;
        if(a[m].v-1<len) return cout<<-1<<'\n',0;
        ans+=(a[m].v-1)*len-len*(len-1)/2;
        cout<<ans<<'\n';
    }
}