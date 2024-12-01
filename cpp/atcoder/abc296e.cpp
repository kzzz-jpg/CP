#include<bits/stdc++.h>
using namespace std;
int n;
int hd[200500],nxt[200500],to[200500],ans[200500],a[200500];
int cnt=1;
void addE(int a,int b){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    hd[a]=cnt++;
}
int dfn[200500],low[200500],inq[200500];
int dfnt=1;
stack<int> st;
void tarjan(int x){
    dfn[x]=low[x]=dfnt++;
    st.push(x);
    inq[x]=1;
    for(int e=hd[x];e;e=nxt[e]){
        if(inq[to[e]]){
            low[x]=min(low[x],low[to[e]]);
        }else if(!dfn[to[e]]){
            tarjan(to[e]);
            low[x]=min(low[x],low[to[e]]);
        }
    }
    vector<int> chk;
    if(low[x]==dfn[x]){
        while(st.top()!=x){
            chk.push_back(st.top());
            inq[st.top()]=0;
            st.pop();
        }
        chk.push_back(x);
        inq[x]=0;
        st.pop();
        if(chk.size()>1||a[x]==x){
            for(auto at:chk) ans[at]=1;
        }
    }
}
signed main(){
    cin>>n;
    int t;
    for(int i=1;i<=n;i++) cin>>a[i],addE(i,a[i]);
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    int rlans=0;
    for(int i=1;i<=n;i++) rlans+=ans[i];
    cout<<rlans<<'\n';
}

