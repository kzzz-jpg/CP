#include<bits/stdc++.h>
using namespace std;
#define int long long
void per(int &a,int &b,int bit){
    if((a&(1<<1))==(b&(1<<1))){
        a=(a-(a&1))|bit;
    }
}
int a[3];
int dir[3][2]={{0,1},{1,2},{2,1}};
signed main(){
    string bt,rgb;
    while(getline(cin,bt)){
        getline(cin,rgb);
        stringstream ss;
        ss<<rgb;
        while(ss>>a[0]>>a[1]>>a[2]){
            for(int i=0;i<bt.size();i++){
                per(a[dir[i&3][0]],a[dir[i&3][1]],bt[i]-'0');
                cerr<<a[dir[i&3][0]]<<' '<<a[dir[i&3][1]]<<'\n';
            }
            cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<' ';
        }
        cout<<'\n';
    }
}