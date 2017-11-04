int main(){
	int c,p,x,l;
	cin>>c>>p>>x>>l;
	int u,v;
	vector<vector<int> > g(c,vector<int>());
	for(int i=0;i<p;i++){
		cin>>u>>v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}
	vector<int> d(c,0);
	vector<int> ori(c,0);
	for(int i=0;i<c;i++){
		d[i]=ori[i]=g[i].size();
	}
	x--;
	l--;
	vector<bool> vivo(c,true);
	vivo[l]=false;
	queue<int> q;
	q.push(l);
	while(!q.empty()){
		int nodo=q.front();
		q.pop();
		vivo[nodo]=false;
		for(int i=0;i<g[nodo].size();i++){
			int next=g[nodo][i];
			if(vivo[next]){
				d[next]--;
				if(d[next]==ori[next]/2){
					q.push(next);
				}
			}
		}
	}
	if(vivo[x]){
		puts("stay");
	}else{
		puts("leave");
	}
	return 0;
}