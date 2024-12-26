void init(int n){
  for(int i=1; i<=n; i++) par[i] = i, rank[i] = 1;
}
int find(int v){
  if(v == par[v]) return v;
  return par[v] = find(par[v]);
}
bool merge(int u, int v){
  u = find(u), v = find(v);
  if(u == v) return true;
  if(rank[u] > rank[v]) swap(u, v);
  par[u] = v;
  if(rank[u] == rank[v]) rank[v]++;
}
