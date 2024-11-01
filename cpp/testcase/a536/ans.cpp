#include <bits/stdc++.h>
using namespace std;
inline int read(){
	register int x=0;
	register bool f=0;
	register char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return f?-x:x;
}
char cr[200];int tt;
inline void print(int x,char k='\n') {
    if(!x) putchar('0');
    if(x < 0) putchar('-'),x=-x;
    while(x) cr[++tt]=x%10+'0',x/=10;
    while(tt) putchar(cr[tt--]);
    putchar(k);
}
const int inf=2147483647;
const int maxn=1100100;
struct rbt{
	int v,sz,cnt;
	bool col;
	int fa,ch[2];
}t[maxn*4];
int st[maxn*4],top,rt,tot,n,m,ans,lastans;
void pushup(int o){
	t[o].sz=t[t[o].ch[0]].sz+t[t[o].ch[1]].sz+t[o].cnt;
}
bool get(int o){
	return t[t[o].fa].ch[1]==o;
}
int newnode(int v){
	int o=top?st[top--]:++tot;
	t[o]=(rbt){v,1,1,1,0,0,0};
    return o;
}
void rotate(int o,bool c){
	int s1=t[o].ch[!c];
	t[o].ch[!c]=t[s1].ch[c];
	if (t[s1].ch[c])
		t[t[s1].ch[c]].fa=o;
    t[s1].fa=t[o].fa;
    if(!t[o].fa)
		rt=s1;
    else 
		t[t[o].fa].ch[get(o)]=s1;
    t[s1].ch[c]=o;
    t[o].fa=s1;
    pushup(o);
    pushup(s1);
}
void ins_fix(int o) {
	while(t[t[o].fa].col){
        int f=t[o].fa,gf=t[f].fa;
        bool wh=!get(f);
        int ul=t[gf].ch[wh];
        if(t[ul].col) {
            t[f].col=t[ul].col=0;
            t[gf].col=1;
            o=gf;
        }
		else{
			if(o==t[f].ch[wh])
            	rotate(o=f,!wh);
			else{
            	t[gf].col=1;
            	t[f].col=0;
            	rotate(gf,wh);
        	}
    	}
    }
    t[rt].col=0;
}
void ins(int v) {
    int o=rt,f=0;
    while(o){
        t[o].sz++,f=o;    
        if(v==t[o].v){
            t[o].cnt++;
            return;
        }
        o=t[o].ch[v>t[o].v];
    }
    o=newnode(v);
    if(f) t[f].ch[v>t[f].v]=o;
    else rt=o;
    t[o].fa=f;
    ins_fix(o);
}
int kth(int k) {
    int tmp;
    int o=rt;
    for (;o;) {
        tmp=t[t[o].ch[0]].sz;
        if (tmp+1<=k&&k<=tmp+t[o].cnt)
			break;
        else{
			if (k<=tmp)
				o=t[o].ch[0];
			else{
				k-=tmp+t[o].cnt;
				o=t[o].ch[1];
			}
		}
    }
    return t[o].v;
}
void update(int o){
	for(int i=o;i;i=t[i].fa){
		t[i].sz--;
	}
}
void del_fix(int o) {
    while(o!=rt&&!t[o].col) {
        bool wh=!get(o);
        int f=t[o].fa,ul=t[f].ch[wh];
        if(t[ul].col){
            t[ul].col=0;
            t[f].col=1;
            rotate(f,!wh);
            ul=t[f].ch[wh];
        }
		else{
			if(!t[t[ul].ch[0]].col&&!t[t[ul].ch[1]].col){
            	t[ul].col=1;
				o=f;
        	}
			else{
            	if(!t[t[ul].ch[wh]].col){
                	t[t[ul].ch[!wh]].col=0;
                	t[ul].col=1;
                	rotate(ul,wh);
                	ul=t[f].ch[wh];
            	}
            	t[ul].col=t[f].col;
            	t[t[ul].ch[wh]].col=t[f].col=0;
            	rotate(f,!wh);
            	break;
        	}
    	}
    }
    t[o].col=0;
}
void del(int v) {
	int o=rt;
	while(o&&t[o].v!=v){
		o=t[o].ch[t[o].v<v];
	}
    if(!o)return;
    if(t[o].cnt>1) {        
        t[o].cnt--;
        update(o);
        return;
    }
    int d=o,g=0;
    if(t[o].ch[0]&&t[o].ch[1]){
        d=t[o].ch[1];
        while(t[d].ch[0])
			d=t[d].ch[0];
    }
    g=t[d].ch[!t[d].ch[0]];
    t[g].fa=t[d].fa;
    if(!t[d].fa)
		rt=g;
    else t[t[d].fa].ch[get(d)]=g;
    if(o!=d){
    	t[o].v=t[d].v;
    	t[o].cnt=t[d].cnt;
	}
    update(t[d].fa);
    for(int i=t[d].fa;i&&t[d].cnt>1&&i!=o;i=t[i].fa){
    	t[i].sz-=t[d].cnt;
    	t[i].sz++;
    }
    if (!t[d].col) del_fix(g);
    st[++top]=d;
}
int rnk(int v) {
	ins(v);
    int tmp=0,sum=0;
    int o=rt;
    for (;o;) {
        tmp=t[t[o].ch[0]].sz;
        if(v==t[o].v)
			break;
        else{
			if(v<t[o].v)
				o=t[o].ch[0];
        	else{
				sum+=tmp+t[o].cnt,
				o=t[o].ch[1];
        	}
    	}
    }
    del(v);
    return sum+tmp+1;
}
int suf(int v) {
    int res=inf;
    int o=rt;
    for(;o;){
        if(t[o].v>v){
			res=t[o].v,
			o=t[o].ch[0];
		}
        else 
			o=t[o].ch[1];
    }
	return res;
}
int pre(int v) {
    int res=-inf;
    int o=rt;
    for(;o;){
        if(t[o].v<v){
			res=t[o].v,o=t[o].ch[1];
        }
        else
            o=t[o].ch[0];
    }
	return res;
}
signed main(){
	n=read();
    while(n--){
        int opt=read(),v=read();
        if(opt==1) ins(v);
        if(opt==2) del(v);
        if(opt==3) lastans=rnk(v);
        if(opt==4) lastans=kth(v);
        if(opt==5) lastans=pre(v);
        if(opt==6) lastans=suf(v);
        if(opt!=1&&opt!=2) print(lastans);
    }
    return 0;
}