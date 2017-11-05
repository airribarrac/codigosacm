vector<int> a;
vector<int> b;
vector<int> c;

long long inversiones;

void merge(int l,int m,int r){
	int s=m-l+1;
	int aux=s;
	int t=r-m;
	for(int i=0;i<s;i++) b[i]=a[l+i];
	for(int i=0;i<t;i++) c[i]=a[m+1+i];
	int i=0,j=0,k=l;
	while(i<s && j<t){
		if(b[i]>c[j]){
			inversiones+=aux;
			a[k++]=c[j++];
		}else{
			aux--;
			a[k++]=b[i++];
		}
	}
	while(i<s) a[k++]=b[i++];
	while(j<t) a[k++]=c[j++];
}
void merge_sort(int l,int r){
	if(r>l){
		int m=(l+r)/2;
		merge_sort(l,m); merge_sort(m+1,r);	merge(l,m,r);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		inversiones=0;
		cin>>n;
		a.assign(n,0);b.assign(n,0);c.assign(n,0);
		for(int i=0;i<n;i++){
			int aux;
			cin>>aux;
			a[i]=aux;
		}
		merge_sort(0,n-1);
		cout<<inversiones<<endl;
	}
	return 0;
}