#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
int n,m,wcnt,bcnt;
bool flag=1;
pair<int,int> w[300500],b[300500];
int pre[300500];
void build(){
    pre[0]=1e18;
    for(int i=1;i<=wcnt;i++){
        pre[i]=min(w[i].y,pre[i-1]);
    }
}
signed main(){
    cin>>n>>m;
    int x,y;char op;
    for(int i=0;i<m;i++){
        cin>>x>>y>>op;
        if(op=='B') b[++bcnt].x=x,b[bcnt].y=y;
        else w[++wcnt].x=x,w[wcnt].y=y;
    }
    if(wcnt&&bcnt){
        sort(w+1,w+1+wcnt);
        build();
        for(int i=1;i<=bcnt;i++){
            int pos=upper_bound(w+1,w+1+wcnt,pair<int,int>{b[i].x,-1})-(w+1);
            if(pre[pos]<=b[i].y) flag=0;
        }
        for(int i=1;i<=wcnt;i++) swap(w[i].x,w[i].y);
        sort(w+1,w+1+wcnt);
        build();
        for(int i=1;i<=bcnt;i++){
            int pos=upper_bound(w+1,w+1+wcnt,pair<int,int>{b[i].y,-1})-(w+1);
            if(pre[pos]<=b[i].x) flag=0;
        }
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
}