#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int n,h,w;
int g[11][11];
pair<int,int> a[8];
bool test(int k){
        if(k>n) {
                /*
                for(int i=1;i<=h;i++) {
                        for(int j=1;j<=w;j++) {
                                cout<<g[i][j]<<' ';
                        }
                        cout<<'\n';
                }
                cout<<'\n';
                */
                for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) if(g[i][j]==0) return 0;
                return 1;
        }
        int x=h+1,y=w+1;
        for(int i=1;i<=h;i++){
                bool flag=0;
                for(int j=1;j<=w;j++) {
                        if(g[i][j]==0) {flag=1,x=i,y=j;break;}
                }
                if(flag) break;
        }
        if(x==h+1&&y==w+1) return 1;
        //cerr<<x<<' '<<y<<'\n';
        bool flag;
        if(x+a[k].f-1<=h&&y+a[k].s-1<=w){
                flag=1;
                for(int i=0;i<a[k].f;i++){
                        for(int j=0;j<a[k].s;j++) if(g[i+x][j+y]==1) flag=0;
                }
                if(flag){
                        for(int i=0;i<a[k].f;i++){
                                for(int j=0;j<a[k].s;j++) g[i+x][j+y]=1;
                        }
                        if(test(k+1)) return 1;
                        for(int i=0;i<a[k].f;i++){
                                for(int j=0;j<a[k].s;j++) g[i+x][j+y]=0;
                        }
                }
        }
        if(x+a[k].s-1<=h&&y+a[k].f-1<=w){
                flag=1;
                for(int i=0;i<a[k].s;i++){
                        for(int j=0;j<a[k].f;j++) if(g[i+x][j+y]==1) flag=0;
                }
                if(flag){
                        for(int i=0;i<a[k].s;i++){
                                for(int j=0;j<a[k].f;j++) g[x+i][y+j]=1;
                        }
                        if( test(k+1)) return 1;
                        for(int i=0;i<a[k].s;i++){
                                for(int j=0;j<a[k].f;j++) g[i+x][j+y]=0;
                        }
                }
        }
        return 0;
}
signed main(){
        cin>>n>>h>>w;
        for(int i=1;i<=n;i++) cin>>a[i].f>>a[i].s;
        sort(a+1,a+1+n);
        do{
                if(test(1)) return cout<<"Yes\n",0;
        }while(next_permutation(a+1,a+1+n));
        cout<<"No\n";
}
