struct FenwickTree{
  vi FT;
  FenwickTree(int N){
     FT.resize(N+1,0);
  }

  int query(int i){
     int ans = 0;
     for(;i;i-=i&(-i)) ans += FT[i];
     return ans;
  }

  int query(int i, int j){
     return query(j)-query(i-1);
  }

  void update(int i, int v){
     for(;i<FT.size();i+=i&(-i)) FT[i] += v;
  }

  void update(int i, int j, int v){
     update(i,v); update(j+1,-v);
  }
};