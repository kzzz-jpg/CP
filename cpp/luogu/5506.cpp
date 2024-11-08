#include<bits/stdc++.h>
using namespace std;
struct plane{
	int x,y,z,h,f,atk,def,mat,mdf,fix,hp;
	string op;
} f[200];
int dir[5][8][3]={
	{
		{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1}
	},
	{
		{1,0,-1},{1,1,-1},{0,1,-1},{-1,1,-1},{-1,0,-1},{-1,-1,-1},{0,-1,-1},{1,-1,-1}
	},
	{
		{1,0,0},{1,1,0},{0,1,0},{-1,1,0},{-1,0,0},{-1,-1,0},{0,-1,0},{1,-1,0}
	},
	{
		{1,0,1},{1,1,1},{0,1,1},{-1,1,1},{-1,0,1},{-1,-1,1},{0,-1,1},{1,-1,1}
	},
	{
		{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1}
	}
};
int n,t;
signed main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>f[i].x>>f[i].y>>f[i].z>>f[i].h>>f[i].f>>f[i].atk>>f[i].def>>f[i].mat>>f[i].mdf>>f[i].hp>>f[i].fix;
		cin>>f[i].op;
	}
	for(int i=0;i<t;i++){
		for(int j=1;j<=n;j++){
			if(f[j].hp<=0) continue;
			f[j].x+=dir[f[j].h][f[j].f][0];
			f[j].y+=dir[f[j].h][f[j].f][1];
			f[j].z+=dir[f[j].h][f[j].f][2];
		}
		for(int j=1;j<=n;j++){
			if(f[j].hp<=0) continue;
			if(f[j].op[i]=='N') continue;
			if(f[j].op[i]=='F') {
				f[j].hp+=f[j].fix;continue;
			}
			if(f[j].op[i]=='U'){
				if(f[j].h==4) continue;
				f[j].h++;
				continue;
			}
			if(f[j].op[i]=='D'){
				if(f[j].h==0) continue;
				f[j].h--;
				continue;
			}
			if(f[j].op[i]=='R'){
				f[j].f--;
				if(f[j].f<0) f[j].f=7;
				continue;
			}
			if(f[j].op[i]=='L'){
				f[j].f++;
				if(f[j].f>7) f[j].f=0;
				continue;
			}
			if(f[j].op[i]=='A'){
				bool flag=0;
				for(int tmp=0;tmp<300;tmp++){
					for(int k=1;k<=n;k++){
						if(f[k].hp<=0||k==j) continue;
						if(f[k].x==f[j].x+dir[f[j].h][f[j].f][0]*tmp&&f[k].y==f[j].y+dir[f[j].h][f[j].f][1]*tmp&&f[k].z==f[j].z+dir[f[j].h][f[j].f][2]*tmp){
							f[k].hp-=max(0,f[j].atk-f[k].def);
							flag=1;
							break;
						}
					}
					if(flag) break;
				}
				continue;
			}
			if(f[j].op[i]=='M'){
				bool flag=0;
				for(int tmp=0;tmp<300;tmp++){
					for(int k=1;k<=n;k++){
						if(f[k].hp<=0||k==j) continue;
						if(f[k].x==f[j].x+dir[f[j].h][f[j].f][0]*tmp&&f[k].y==f[j].y+dir[f[j].h][f[j].f][1]*tmp&&f[k].z==f[j].z+dir[f[j].h][f[j].f][2]*tmp){
							f[k].hp-=max(0,f[j].mat-f[k].mdf);
						}
					}
				}
				continue;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<f[i].x<<' '<<f[i].y<<' '<<f[i].z<<' ';
		if(f[i].hp<=0) cout<<0<<'\n';
		else cout<<f[i].hp<<'\n';
	}
}
