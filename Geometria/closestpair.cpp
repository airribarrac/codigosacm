#define px second
#define py first
typedef pair<ll,ll> pairll;
int n;
pairll pnts[100000];
set<pairll> box;
double best;
int compx(pairll a,pairll b){
	return a.px<b.px;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&pnts[i].px,&pnts[i].py);
	}
	sort(pnts,pnts+n,compx);
	best=100000000000;
	box.insert(pnts[0]);
	int left=0;
	for(int i=1;i<n;i++){
		while(left<i && pnts[i].px-pnts[left].px > best) box.erase(pnts[left++]);
		for(typeof(box.begin()) it=box.lower_bound(make_pair(pnts[i].py-best, pnts[i].px-best)); 
 		it!=box.end() && pnts[i].py+best>=it->py; it++){
        	best = min(best, sqrt(pow(pnts[i].py - it->py, 2.0)+pow(pnts[i].px - it->px, 2.0)));
 		}
 		box.insert(pnts[i]);
 		printf("%.2f\n",best);
	}
}