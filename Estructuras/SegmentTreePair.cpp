#include <bits/stdc++.h>
#define inf 0x7fffffff
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair <int,int> par;
typedef vector< par > vi;
class SegmentTree {
public:
  SegmentTree(const vi&_A){
    arr = _A; n = (int)arr.size();
    tree.resize(4*n);
    lazy.resize(4*n);
    for(int i = 0; i < 4*n; i++){
    	lazy[i] = 0;
     	tree[i] = make_pair(0,i);
    }
    build_tree(1,0,n-1);    
  }
  par rmq(ll i,ll j) {return query_tree(1,0,n-1,i,j);}
  void update(ll i,ll j, ll val){update_tree(1,0,n-1,i,j,val);}
private:
  vi arr, tree;
  vector <long long int >lazy;
  ll n;
  void build_tree(ll node, ll a, ll b) {
    if(a > b) return;  	
    if(a == b) { 
      tree[node] = arr[a];
      return;
    }	
    build_tree(node*2, a, (a+b)/2); 
    build_tree(node*2+1, 1+(a+b)/2, b);	
    tree[node] =  (tree[node*2].first < tree[node*2 +1].first) ? tree[node*2] : tree[node*2+1];
  }

  void update_tree(ll node, ll a, ll b, ll i, ll j, ll value) {  
    if(lazy[node] != 0) { 
      tree[node].first += lazy[node]; //+=
      if(a != b) {
	lazy[node*2] += lazy[node]; //+= 
	lazy[node*2+1] += lazy[node]; //+=
      }
      lazy[node] = 0;
    }
  
    if(a > b || a > j || b < i) return;
    if(a >= i && b <= j) {
      tree[node].first += value; //+=
      if(a != b) {
	lazy[node*2] += value; //+=
	lazy[node*2+1]+= value; //+=
      }
      return;
    }    
    update_tree(node*2, a, (a+b)/2, i, j, value); 
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
 tree[node] =  (tree[node*2].first < tree[node*2 +1].first) ? tree[node*2] : tree[node*2+1];
  }

  par query_tree(ll node, ll a, ll b, ll i, ll j) {
    //Cuidado con -inf que está como entero en caso de usar long long
    if(a > b || a > j || b < i) return make_pair ((ll)inf,-1); //(-inf,max) (inf,min)  
    if(lazy[node] != 0){
      tree[node].first += lazy[node]; //+=
      if(a != b) {
	lazy[node*2] += lazy[node]; //+=
	lazy[node*2+1] += lazy[node]; //+=
      }
      lazy[node] = 0;
    }
    
    if(a >= i && b <= j) return tree[node];
    par q1 = query_tree(node*2, a, (a+b)/2, i, j);
    par q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); 
    par res = (q1.first < q2.first) ? q1 : q2;
    return res;
  }
};

int main() {
  //optimizar_io
	int a,b,c,d,aux,aux2;
	scanf("%d %d %d %d",&a,&b,&c,&d);
  vi conexo,disconexo;
  conexo.resize(a);
  disconexo.resize(a);
  vector <vector <int> > adj;
  adj.resize(a);
  for(int i=0;i<b;i++){
  	cin>>aux >> aux2;
  	adj[aux-1].push_back(aux2-1);
   	adj[aux2-1].push_back(aux-1);
  } 
  for(int i = 0; i < a; i++){
  	conexo[i] = make_pair(adj[i].size(),i);
  	disconexo[i] = make_pair(a-1-adj[i].size(),i);
  }
  SegmentTree amigo(conexo);
  SegmentTree enemigo(disconexo);
  vector <bool> respuesta;
  respuesta.resize(a,true);
  par temp;
  while(1){
  	temp = amigo.rmq(0,a-1);
  	if(temp.first >= c || c == 0){
	temp = enemigo.rmq(0,a-1);
	if(temp.first >= d || d == 0)break; 
	}
  		respuesta[temp.second] = false;
  		for(int i = 0; i < adj[temp.second].size() ; i++){
  			amigo.update(adj[temp.second][i],adj[temp.second][i],-1);
  			enemigo.update(adj[temp.second][i],adj[temp.second][i],+1);
  		}
  		enemigo.update(0,a-1,-1);
		amigo.update(temp.second,temp.second,50000000); 		
    		enemigo.update(temp.second,temp.second,50000000);
  }
  ll imprimir = 0;
  for(int i = 0; i < a; i++)if(respuesta[i])imprimir++;
  printf("%lld\n",imprimir);
  return 0;
}
 