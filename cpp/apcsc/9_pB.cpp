#include<bits/stdc++.h>
#include<random>
using namespace std;
#define int long long
#define bnc(x) (x)*(x+1)/2
random_device rd;
mt19937 rg(rd());
vector<pair<int,int>> ht;
int lsx=1e15,lsy=1e15;
int n,m,k,q,op,l,r;
int g[18][20],bn[18][20];
int mns=0;
int cunt(){
    int ret=0;
    for(auto u:ht) {
        int x=u.first,y=u.second;
        ret+=g[x][y]*bnc(bn[x][y]);
    }
    ret-=mns;
    return ret;
}
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            bn[i][j]=1;
        }
    }
}
bool inR(int x,int y){
    return x>=1&&y>=1&&x<=n&&y<=m;
}
int fndot(int x,int y){
    int ret=1e15;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ret=min(ret,abs(x-i)+abs(y-j));
        }
    }
    return ret;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    init();
    cin>>k>>q;
    for(int i=1;i<=k+q;i++){
        cin>>op;
        if(op==1){
            cin>>l>>r;
            if(inR(l,r)){
                if(l==lsx&&r==lsy){
                    bn[l][r]++;
                }else{
                    bn[l][r]=1;
                }
                ht.push_back({l,r});
            }else{
                mns+=fndot(l,r);
                init();
            }
            lsx=l,lsy=r;
        }else{
            cout<<cunt()<<'\n';
        }
    }
}
signed main(){
    int t=1;
    while(t--) solve();
}