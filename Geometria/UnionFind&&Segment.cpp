#include <bits/stdc++.h>
using namespace std; 
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
typedef vector<int> vi;

class UnionFind{
private:
  vi p, rank;
public:
  UnionFind(int N){
    rank.assign(N,0);
    p.assign(N,0);
    for(int i=0;i<N;i++){
      p[i]=i;
    }
  }
  int findSet(int i){
    return (p[i]==i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
  }
  void unionSet(int i,int j){
    if(!isSameSet(i,j)){
      int x = findSet(i), y = findSet(j);
      if(rank[x]>rank[i]) p[y]=x;
      else{
    p[x]=y;
    if(rank[x]==rank[y]) rank[y]++;
      }
    }
  }
  void imprimir(){
    for(int i=0;i<p.size();i++) printf("%d ",p[i]);
    puts("");
  }
};

const int MAX = 1024;

struct Point { int x, y; };
struct Segment { Point a, b; };

Segment seg[MAX];
inline int direction(Point &pi, Point &pj, Point &pk) {
  return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
}

inline bool onsegment(Point &pi, Point &pj, Point &pk) {
  return (inside(min(pi.x,pj.x),pk.x,max(pi.x,pj.x)) && inside(min(pi.y,pj.y),pk.y,max(pi.y,pj.y)));
}

inline bool intersect(Point &p1, Point &p2, Point &p3, Point &p4) {
  int d1, d2, d3, d4;
  d1 = direction(p3, p4, p1);
  d2 = direction(p3, p4, p2);
  d3 = direction(p1, p2, p3);
  d4 = direction(p1, p2, p4);
  if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0 && d4>0))) return true;
  if(!d1 && onsegment(p3, p4, p1)) return true;
  if(!d2 && onsegment(p3, p4, p2)) return true;
  if(!d3 && onsegment(p1, p2, p3)) return true;
  if(!d4 && onsegment(p1, p2, p4)) return true;
  return false;
}


int main(){
    int t;
  cin>>t;
  int n,m;
  while(t--){  
    Point p[n];
    Point q[n];
    cin>>n>>m;
    for(int i=0;i<n;i++){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      seg[i].a.x = a;
      seg[i].a.y = b;
      seg[i].b.x = c;
      seg[i].b.y = d;
    }
    UnionFind uf(n);
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
    if( intersect(seg[i].a, seg[i].b, seg[j].a, seg[j].b)){
      uf.unionSet(i,j);
    }
      }
    }
    // uf.imprimir();
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      if(uf.isSameSet(a-1,b-1)) puts("YES");
      else puts("NO");
    }
  }
  return 0;
}