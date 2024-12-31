#include<bits/stdc++.h>
using namespace std;
struct pt{
        int y,id;
        string p;
        bool operator <(pt o)const{
                return y<o.y;
        }
} a[200500];
map<string,int> prf;
string ans[200500];
int n,m;
signed main(){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
                cin>>a[i].p>>a[i].y;
                a[i].id=i;
                while(a[i].p.size()<6) a[i].p='0'+a[i].p;
        }
        sort(a+1,a+1+m);
        string tmp;
        stringstream ss;
        for(int i=1;i<=m;i++){
                int nw=++prf[a[i].p];
                ss<<nw;
                ss>>tmp;
                ss.str("");
                ss.clear();
                while(tmp.size()<6) tmp='0'+tmp;
                ans[a[i].id]=a[i].p+tmp;
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
}
