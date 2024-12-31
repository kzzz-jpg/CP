#include<bits/stdc++.h>
#define int long long
using namespace std;
int fp(int x,int y,int p){
        x%=p;
        int ret=1;
        while(y){
                if(y&1) ret=(ret*x)%p;
                x=(x*x)%p;
                y>>=1;
        }
        return ret;
}
int a,b,c;
int ba[5]={6,8,4,2};
int tw[5]={6,2,4,8};
signed main(){
        cin>>a>>b>>c;
        a%=10;
        //cout<<fp(a,fp(b,c,4),10)<<'\n';
        /*
        for(int i=1;i<10;i++){
                if(i==2||i==4||i==8) continue;
                int nw=i,ret=0;
                while(nw!=1) nw=(nw*i)%10,ret++;
                cout<<ret<<'\n';
        }
        */
        if(a==0) cout<<0<<'\n';
        else if(a==1) cout<<1<<'\n';
        else if(a==2){
                cerr<<fp(b,c,4)<<'\n';
                cout<<tw[fp(b,c,4)]<<'\n';
        }else if(a==4){
                if(fp(b,c,2)==0) cout<<6<<'\n';
                else cout<<4<<'\n';
        }else if(a==5) cout<<5<<'\n';
        else if (a==6) cout<<6<<'\n';
        else if(a==8){
                cout<<ba[fp(b,c,4)]<<'\n';
        }else cout<<fp(a,fp(b,c,4),10)<<'\n';
}
