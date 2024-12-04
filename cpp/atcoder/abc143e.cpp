#include<bits/stdc++.h>
using namespace std;
int n,m,l,q;
int hd[100500],nxt[200500],to[200500],w[200500];
int cnt=1;
void addE(int a,int b,int c){
        nxt[cnt]=hd[a];
        to[cnt]=b;
        w[cnt]=c;
        hd[a]=cnt++;
}
int dis[100500],ans[100500];
bool vs[305];
struct nd{
        int x,v,l,t;
        bool operator<(nd o)const{
                return v<o.v;
        }
        nd(int xx,int vv,int ll,int tt):x(xx),v(vv),l(ll),t(tt){}
};
void dij(int x){
        for(int i=0;i<305;i++)vs[i]=0;
        priority_queue<nd> pq;
        pq.push(nd(x,0,l,0));
        while(pq.size()){
                auto tp=pq.top();pq.pop();
                if(vs[tp.x])continue;
                vs[tp.x]=1;
                dis[tp.x]=tp.v;
                ans[tp.x]=tp.t;
         //       cerr<<tp.x<<' '<<tp.v<<' '<<tp.l<<' '<<tp.t<<'\n';
                for(int e=hd[tp.x];e;e=nxt[e]){
                        if(w[e]<=l&&!vs[to[e]]){
                                if(tp.l<w[e])pq.push(nd(to[e],tp.v+w[e],l-w[e],tp.t+1));
                                else pq.push(nd(to[e],tp.v+w[e],tp.l-w[e],tp.t));
                        }
                }
        }
}
struct query{
        int x,y,id;
        bool operator<(query o) const{
                return x<o.x;
        }
} qry[100500];
int Ans[100500];
signed main(){
        cin>>n>>m>>l;
        int x,y,v;
        for(int i=1;i<=m;i++)cin>>x>>y>>v,addE(y,x,v),addE(x,y,v);
        cin>>q;
        for(int i=1;i<=q;i++) cin>>qry[i].x>>qry[i].y,qry[i].id=i;
        sort(qry+1,qry+1+q);
        for(int i=1;i<=q;){
                dij(qry[i].x);
                do{
                        Ans[qry[i].id]=ans[qry[i].y];
        //                cerr<<qry[i].x<<' '<<qry[i].y<<' '<<ans[qry[i].y]<<'\n';
                        if(!vs[qry[i].y]) Ans[qry[i].id]=-1;
                        i++;
                }while(qry[i-1].x==qry[i].x);
        }
        for(int i=1;i<=q;i++) cout<<Ans[i]<<'\n';
}
