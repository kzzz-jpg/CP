#include<bits/stdc++.h>
using namespace std;
#define int long long
int hd[200500],nxt[200500],to[200500],w[200500];
int cnt=1;
void addE(int a,int b,int v){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	w[cnt]=v;
	hd[a]=cnt++;
}
int low[200500],lev[200500];
int dfn=1;
void tarjan(int x){
	low[x]=lev[x]=dfn++;
	for(int  e=hd[x];e;e=nxt[e]){

