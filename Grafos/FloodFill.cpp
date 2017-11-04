#include <bits/stdc++.h>

using namespace std;

int n,m;
int mapa[2020][2020];
int total;
int w;
int sumar=507;
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
#define fix(x) (x)=2*((x)+sumar)
typedef pair<int,int> ii;
inline bool check(int x,int y){
	return x>=0 && x<2020 && y>=0 && y<2020;	
}

void fill(int x,int y){
	total--;
	queue<ii> q;
	q.push(ii(x,y));
	mapa[x][y]=-1;
	while(!q.empty()){
		x=q.front().first;
		y=q.front().second;

		q.pop();
		for(int i=0;i<4;i++){
			//printf("ini:%d %d\n",x+xx[i],y+yy[i]);
			if(check(x+xx[i],y+yy[i]) && mapa[x+xx[i]][y+yy[i]]<w){
				//printf("a:%d %d\n",x+xx[i],y+yy[i]);
				//printf("%d\n",mapa[x+2*xx[i]][y+2*yy[i]]);
				if(check(x+2*xx[i],y+2*yy[i])&&mapa[x+2*xx[i]][y+2*yy[i]]!=-1){
					//printf("b:%d %d\n",x+2*xx[i],y+2*yy[i]);
					mapa[x+2*xx[i]][y+2*yy[i]]=-1;
					//puts("a");
					total++;
					q.push(ii(x+2*xx[i],y+2*yy[i]));
					//printf("%d %d\n",q.front().first,q.front().second);
				}

			}

		}
	}
	//puts("fin");
}

int main(){
	int x1,y1,x2,y2,h,minX,maxX,minY,maxY;
	while(scanf("%d",&n)){
		total=0;
		
		if(n==0){
			break;
		}
		for(int i=0;i<2020;i++){
			for(int j=0;j<2020;j++){
				mapa[i][j]=0;
			}
		}
		minX=minY=10000;
		while(n--){
			scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&h);
			fix(x1);
			fix(y1);
			fix(x2);
			fix(y2);
			if(x1==x2){
				for(int i=min(y1,y2);i<=max(y1,y2);i++){
					mapa[x1][i]=h;
				}
			}else{
				for(int i=min(x1,x2);i<=max(x1,x2);i++){
					mapa[i][ y1]=h;
				}
			}
			
		}
		
		scanf("%d",&w);
		fill(1,1);
		
		printf("%d\n",1010*1010-total-2);
		
	}
	return 0;
}