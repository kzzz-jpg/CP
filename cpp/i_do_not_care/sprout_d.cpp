#include<bits/stdc++.h>
using namespace std;
int h,w,n,m,k,t;
struct airPort{
    int company;
    char type;
    set<pair<int,int>> flight;
} g[105][105];
struct plane{
    int x,y;
    bool in_airPort;
} P[1050][1050];
bool inRange(int x,int y){
    return x>=1&&x<=h&&y>=1&&y<=w;
}
void repair(int x,int y){
    cout<<"depart "<<g[x][y].flight.size()<<'\n';
    for(auto _x:g[x][y].flight){
        cout<<_x.first<<' '<<_x.second<<'\n';
        P[_x.first][_x.second].x=0;
        P[_x.first][_x.second].x=0;
        P[_x.first][_x.second].in_airPort=0;
    }
    g[x][y].company=0;
    g[x][y].flight.clear();
}
void arrive(int p,int q,int x,int y){
    if(P[p][q].in_airPort){
        g[P[p][q].x][P[p][q].y].flight.erase({P[p][q].x,P[p][q].y});
        P[p][q].in_airPort=0;
    }
    if(g[x][y].type=='*'){
        g[x][y].flight.insert({p,q});
        P[p][q].x=x;
        P[p][q].y=y;
    }else{
        if(g[x][y].company!=p&&g[x][y].flight.size()>=k){
            x=P[p][q].x;
            y=P[p][q].y;
            cout<<"arrival fail\n";
        }else if(g[x][y].company!=p){
            repair(x,y);
        }else{
            cout<<"depart 0\n";
        }
        g[x][y].flight.insert({p,q});
        P[p][q].x=x;
        P[p][q].y=y;
        P[p][q].in_airPort=bool(x);
        g[x][y].company=p;
    }
}
void move(int p,int q,int x,int y,int dx,int dy){
    if(!P[p][q].in_airPort){
        cout<<"movement fail\n";
        return;
    }
    if(P[p][q].in_airPort){
        g[P[p][q].x][P[p][q].y].flight.erase({P[p][q].x,P[p][q].y});
        P[p][q].in_airPort=0;
    }
    if(!inRange(x,y)){
        move(p,q,x+dx,y+dy,dx,dy);
        return;
    }
    if(g[x][y].type=='*'){
        g[x][y].flight.insert({p,q});
        P[p][q].x=x;
        P[p][q].y=y;
        cout<<"depart 0\n";
    }else{
        if(g[x][y].company!=p&&g[x][y].flight.size()>=k){
            move(p,q,x+dx,y+dy,dx,dy);
        }else if(g[x][y].company!=p){
            repair(x,y); 
            g[x][y].flight.insert({p,q});
            P[p][q].x=x;
            P[p][q].y=y;
            P[p][q].in_airPort=bool(x);
            g[x][y].company=p;
        }else{
            cerr<<p<<' '<<q<<' '<<x<<' '<<y<<'\n';
            cout<<"depart 0\n";
            g[x][y].flight.insert({p,q});
            P[p][q].x=x;
            P[p][q].y=y;
            P[p][q].in_airPort=bool(x);
            g[x][y].company=p;
        }
    }
}
signed main(){
    cin>>h>>w>>n>>m>>k>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j].type;
        }
    }
    string op;
    int x,y,p,q,l,nx,ny;
    char dir;
    while(t--){
        cin>>op;
        if(op=="repair"){
            cin>>x>>y;
            repair(x,y);
        }else if(op=="arrive"){
            cin>>p>>q>>x>>y;
            arrive(p,q,x,y);
        }else if(op=="move"){
            cin>>p>>q>>dir>>l;
            if(dir=='N'){
                move(p,q,P[p][q].x-l,P[p][q].y,1,0);
            }else if(dir=='S'){
                move(p,q,P[p][q].x+l,P[p][q].y,-1,0);
            }else if(dir=='E'){
                move(p,q,P[p][q].x,P[p][q].y+l,0,-1);
            }else if(dir=='W'){
                move(p,q,P[p][q].x,P[p][q].y-l,0,1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(P[i][j].in_airPort){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(P[i][j].in_airPort){
                cout<<i<<' '<<j<<' '<<P[i][j].x<<' '<<P[i][j].y<<'\n';
            }
        }
    }
}