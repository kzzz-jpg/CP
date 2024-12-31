#include<bits/stdc++.h>
using namespace std;
int n,m,k,t;
int x[31],rlx[31];
int y[31],rly[31];
string op[31];
bool inRange(int x1,int y1){
    return x1>=1&&x1<=n&&y1>=1&&y1<=m;
}
int mxx=0,mxy=0,mnx=0,mny=0;
signed main(){
    cin>>n>>m>>k>>t;
    for(int i=1;i<=k;i++) {
        cin>>x[i]>>y[i],rlx[i]=x[i],rly[i]=y[i];
        if(t) cin>>op[i];
    }
    sort(x+1,x+1+k);
    sort(y+1,y+1+k);
    for(int i=1;i<=k;i++){
        if((k&1)&&i==k/2+1) continue;
        if(i<=k/2) mnx+=x[i],mny+=y[i];
        else mxx+=x[i],mxy+=y[i];
    }
    cerr<<mxx<<' '<<mnx<<' '<<mxy<<' '<<mny<<'\n';
    for(int i=1;i<=k;i++) cerr<<x[i]<<" \n"[i==k];
    for(int i=1;i<=k;i++) cerr<<y[i]<<" \n"[i==k]; 
    cout<<(mxx-mnx)+(mxy-mny)<<'\n';
    for(int i=0;i<t;i++){
        for(int j=1;j<=k;j++){
            int nx,ny;
            if(op[j][i]=='L') nx=rlx[j],ny=rly[j]-1;
            else if(op[j][i]=='R') nx=rlx[j],ny=rly[j]+1;
            else if(op[j][i]=='U') nx=rlx[j]-1,ny=rly[j];
            else nx=rlx[j]+1,ny=rly[j];
            if(!inRange(nx,ny)) continue;  
            if(op[j][i]=='L') {
                int pos=lower_bound(y+1,y+k+1,rly[j])-y;
                if(!((k&1)&&pos==k/2+1)) {
                    if(pos<=k/2) mny-=y[pos];
                    else mxy-=y[pos];
                }
                rly[j]--;
                y[pos]--;
                if(!((k&1)&&pos==k/2+1)) {
                    if(pos<=k/2) mny+=y[pos];
                    else mxy+=y[pos];
                }
            }
            else if(op[j][i]=='R') {
                int pos=upper_bound(y+1,y+k+1,rly[j])-y-1;
                if(!((k&1)&&pos==k/2+1)) {
                    if(pos<=k/2) mny-=y[pos];
                    else mxy-=y[pos];
                }
                rly[j]++;
                y[pos]++;
                if(!((k&1)&&pos==k/2+1)) {
                    if(pos<=k/2) mny+=y[pos];
                    else mxy+=y[pos];
                }
            }
            else if(op[j][i]=='U') {
                int pos=lower_bound(x+1,x+k+1,rlx[j])-x;
                if(!((k&1)&&pos==k/2+1)) {
                    if(pos<=k/2) mnx-=x[pos];
                    else mxx-=x[pos];
                }
                rlx[j]--;
                x[pos]--;
                if(!((k&1)&&pos==k/2+1)) {
                    if(pos<=k/2) mnx+=x[pos];
                    else mxx+=x[pos];
                }
            }
            else {
                int pos=upper_bound(x+1,x+k+1,rlx[j])-x-1;
                if(!((k&1)&&pos==k/2+1)) {
                    if(pos<=k/2) mnx-=x[pos];
                    else mxx-=x[pos];
                }
                rlx[j]++;
                x[pos]++;
                if(!((k&1)&&pos==k/2+1)) {
                    if(pos<=k/2) mnx+=x[pos];
                    else mxx+=x[pos];
                }
            }
        }
        cout<<(mxx-mnx)+(mxy-mny)<<'\n';
    }
}