struct point{
	int x,y,valor;
};

bool comp1(const point &lhs,const point &rhs){
	return lhs.y<rhs.y;
}

bool comp2(const point &lhs,const point &rhs){
	return (lhs.x==rhs.x?lhs.y<rhs.y:lhs.x<rhs.x);
}

point poly[200010];

int main(){
	int p,v;
	while(scanf("%d %d",&p,&v)!=EOF){
		for(int i=0;i<p;i++){
			scanf("%d %d",&poly[i].x,&poly[i].y);
			poly[i].valor=i+1;
		}
		for(int i=p;i<p+v;i++){
			scanf("%d %d",&poly[i].x,&poly[i].y);
			poly[i].valor=-1;
		}
		
		sort(poly,poly+p+v,comp1);				//orden por y;
		
		int original=poly[0].y;					//compresion de puntos por y
		int comprimido=1;
		poly[0].y=comprimido;
		for(int i=1;i<p+v;i++){
			if(poly[i].y==original){
				poly[i].y=comprimido;
			}else{
				original=poly[i].y;
				comprimido++;
				poly[i].y=comprimido;
			}
		}
		FenwickTree FT(800010);
		sort(poly,poly+p+v,comp2);				//orden por x
		int perdido=0;
		for(int i=0;i<p+v;i++){
			if(poly[i].valor==-1){
				FT.update(poly[i].y,poly[i+1].y-1,1);	//los vertices siempre van de a pares
				i++;
			}else{
				if(FT.query(poly[i].y)%2==0){
					perdido+=poly[i].valor;
				}
			}
		} 
		printf("%lld\n",perdido);
	}
	return 0;
}