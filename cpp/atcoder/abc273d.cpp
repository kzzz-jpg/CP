#include<bits/stdc++.h>
#define mp(x,y) make_pair(x,y)
#define int long long
#define f first
#define s second
using namespace std;
int n,m,q,k;
int x,y;
vector<pair<int,int>> vr(200500),hr(200500); //vr y first , hr x first
signed main(){
        cin>>n>>m>>x>>y;
        cin>>k;
        int tx,ty;
        for(int i=1;i<=k;i++){
                cin>>tx>>ty;
                vr[i].f=ty,vr[i].s=tx;
                hr[i].f=tx,hr[i].s=ty;
        }
        sort(vr.begin()+1,vr.begin()+k+1);
        sort(hr.begin()+1,hr.begin()+1+k);
        cin>>q;
        char d;
        int c;
        while(q--){
                cin>>d>>c;
                if(d=='L'){
                        auto it=prev(lower_bound(hr.begin()+1,hr.begin()+1+k,mp(x,y)));
                        if(it->f==x&&it->s<y){
                                y=max(it->s+1,y-c);
                        }else{
                                y-=c;
                        }
                        y=max(y,1LL);
                }
                if(d=='R'){
                        auto it=lower_bound(hr.begin()+1,hr.begin()+1+k,mp(x,y));
                        if(it->f==x){
                                y=min(it->s-1,y+c);
                        }else{
                                y+=c;
                        }
                        y=min(y,m);
                }
                if(d=='U'){
                        auto it=prev(lower_bound(vr.begin()+1,vr.begin()+1+k,mp(y,x)));
                        //cerr<<y<<' '<<x-c<<'\n';
                        //cerr<<it->f<<' '<<it->s<<'\n';
                        if(it->f==y&&it->s<x){
                                x=max(it->s+1,x-c);
                                x=max(x,1LL);
                        }else{
                                x-=c;
                                x=max(x,1LL);
                        }
                }
                if(d=='D'){
                        auto it=lower_bound(vr.begin()+1,vr.begin()+1+k,mp(y,x));
                        if(it->f==y){
                                x=min(it->s-1,x+c);
                                x=min(x,n);
                        }else{
                                x+=c;
                                x=min(n,x);
                        }
                }
                cout<<x<<' '<<y<<'\n';
        }
}
