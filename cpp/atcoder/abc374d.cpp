#include<bits/stdc++.h>
using namespace std;
int n;
int x,y,s,t;
double ans=1e18;
struct ln{
        int x1,y1,x2,y2;
        bool operator < (ln o)const{
                if(x1==o.x1){
                        if(x2==o.x2){
                                if(y1==o.y1) return y2<o.y2;
                                return y1<o.y1;
                        }
                        return x2<o.x2;
                }
                return x1<o.x1;
        }
} a[10];
void dfs(int i,double ret){
        if(i>n){
                ans=min(ans,ret);
                return;
        }
        int orx=x,ory=y;
        double d1=0,d2=0;
        d1+=sqrt((a[i].x1-x)*(a[i].x1-x)+(a[i].y1-y)*(a[i].y1-y))/s;
        d1+=sqrt((a[i].x1-a[i].x2)*(a[i].x1-a[i].x2)+(a[i].y1-a[i].y2)*(a[i].y1-a[i].y2))/t;
        x=a[i].x2,y=a[i].y2;
        dfs(i+1,ret+d1);
        x=orx,y=ory;
        d2+=sqrt((a[i].x2-x)*(a[i].x2-x)+(a[i].y2-y)*(a[i].y2-y))/s;
        d2+=sqrt((a[i].x1-a[i].x2)*(a[i].x1-a[i].x2)+(a[i].y1-a[i].y2)*(a[i].y1-a[i].y2))/t;
        x=a[i].x1,y=a[i].y1;
        dfs(i+1,ret+d2);
        x=orx,y=ory;

}
signed main(){
        cin>>n>>s>>t;
        for(int i=1;i<=n;i++) cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
        sort(a+1,a+1+n);
        do{
                x=0,y=0;
                dfs(1,0);
        }while(next_permutation(a+1,a+1+n));
        cout<<fixed<<setprecision(9)<<ans<<'\n';
}
