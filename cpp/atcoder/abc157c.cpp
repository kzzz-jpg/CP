#include<bits/stdc++.h>
using namespace std;
char s[3]={' ',' ',' '};
int n,m;
signed main(){
        cin>>n>>m;
        int si;
        char c;
        for(int i=0;i<m;i++){
                cin>>si>>c;
                if(s[si-1]!=' '&&s[si-1]!=c){
                        cout<<-1<<'\n';
                        return 0;
                }
                s[si-1]=c;
        }
        if(n>1&&s[0]=='0'){
                cout<<-1<<'\n';
                return 0;
        }
        for(int i=0;i<n;i++) if(s[i]==' ') s[i]='0'+(int)(i==0&&n>1);
        cout<<s<<'\n';
}
