#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000500];
int mx[1000500],mn[1000500],ansn[1000500],ansx[1000500];
int mxl=1,mxr=0,mnl=1,mnr=0;
signed main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=k;i++) {
        while(mxr>=mxl&&a[mx[mxr]]<a[i]) mxr--;
        mx[++mxr]=i;
        while(mnr>=mnl&&a[mn[mnr]]>a[i]) mnr--;
        mn[++mnr]=i;
    }
    ansx[k]=a[mx[mxl]];
    ansn[k]=a[mn[mnl]];
    for(int i=k+1;i<=n;i++){
        while(mxr>=mxl&&mx[mxl]<=i-k) mxl++;
        while(mnr>=mnl&&mn[mnl]<=i-k) mnl++;
        while(mxr>=mxl&&a[mx[mxr]]<a[i]) mxr--;
        mx[++mxr]=i;
        while(mnr>=mnl&&a[mn[mnr]]>a[i]) mnr--;
        mn[++mnr]=i;
        //cerr<<mx[mxl]<<' '<<mn[mnr]<<'\n';
        ansx[i]=a[mx[mxl]];
        ansn[i]=a[mn[mnl]];
    }
    //cerr<<"??\n";
    //for(int i=k;i<=n;i++) cerr<<ansn[i]<<" \n"[i==n];
    //for(int i=k;i<=n;i++) cerr<<ansx[i]<<" \n"[i==n];
    for(int i=k;i<=n;i++) printf("%d ",ansn[i]);
    putchar('\n');
    for(int i=k;i<=n;i++) printf("%d ",ansx[i]);
    putchar('\n');
}