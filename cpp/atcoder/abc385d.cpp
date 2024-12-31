#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,y;
struct ndx{
    int x,y;
    bool operator < (ndx o) const{
        if(x==o.x) return y<o.y;
        return x<o.x;
    }
};
struct ndy{
    int x,y;
    bool operator < (ndy o) const{
        if(y==o.y) return x<o.x;
        return y<o.y;
    }
};
set<ndx> hr;
set<ndy> vr;
int ans;
signed main(){
    cin>>n>>m>>x>>y;
    int tx,ty;
    for(int i=1;i<=n;i++) {
        cin>>tx>>ty;
        vr.insert({tx,ty});
        hr.insert({tx,ty});
    }
    char d;
    int c;
    //cerr<<"hello"<<'\n';
    while(m--){
        cin>>d>>c;
        if(d=='L'){
            auto it=vr.upper_bound({x,y});
            x-=c;
            if(it!=vr.begin()){
                for(it=prev(it);it->y==y&&it->x>=x;it--){
                    ans++,hr.erase(hr.lower_bound(*it));
                    if(it==vr.begin()) break;
                }
                if(it!=vr.begin()||(it->y!=y||it->x<x)) it--;
                vr.erase(it,vr.upper_bound({x+c,y}));
            }
        }
        if(d=='R'){
            auto it=vr.lower_bound({x,y});
            x+=c;
            if(it!=vr.end()){
                for(;it->y==y&&it->x<=x;it++){
                    if(it==vr.end()) break;
                    ans++,hr.erase(hr.lower_bound(*it));
                }
            }
            vr.erase(vr.lower_bound({x-c,y}),it);
        }
        if(d=='U'){
            auto it=hr.lower_bound({x,y});
            y+=c;
            if(it!=hr.end()){
                for(;it->x==x&&it->y<=y;it++){
                    if(it==hr.end()) break;
                    ans++,vr.erase(vr.lower_bound(*it));
                    
                }
            }
            hr.erase(hr.lower_bound({x,y-c}),it);
        }
        if(d=='D'){
            auto it=hr.upper_bound({x,y});
            y-=c;
            if(it!=hr.begin()){
                for(it=prev(it);it->x==x&&it->y>=y;it--){
                    ans++,vr.erase(vr.lower_bound(*it));
                    if(it==hr.begin()) break;
                }
                if(it!=hr.begin()||(it->x!=x||*it<y)) it--;
                hr.erase(it,hr.upper_bound({x,y+c}));
            }
        }
        //cerr<<x<<' '<<y<<'\n';
    }
    cout<<x<<' '<<y<<' '<<ans<<'\n';
}