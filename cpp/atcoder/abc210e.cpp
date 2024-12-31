#include<bits/stdc++.h>
using namespace std;
struct rd{
    int a,v;
    bool operator < (rd o) const {
        return v<o.v;
    }
} r[200500];
int n,m,ans;
int mna=1e18,mnb=1e18;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>r[i].a>>r[i].v;
    }
    for(int i=1;i<=m;i++){
        if(r[i].a&1) mna=min(mna,r[i].v);
        else mnb=min(mnb,r[i].v);
    }
    if(n&1){
        cout<<min(mna,mnb)*(n-1);
    }else{
        if(mna==1e18) cout<<-1<<'\n';
        else{
            if(mna<mnb) cout<<mna*(n-1)<<'\n';
            else cout<<(mnb*(n-2)+mna)<<'\n';
        }
    }
}