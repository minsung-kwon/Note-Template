ll dijkstra(const vector<vector<pair<ll, ll>>> &G, ll s, ll t) {
    const ll INF = LLONG_MAX; // 혹은 0x3f3f3f3f3f3f3f3f 사용 가능
    int n = (int)G.size();
    vector<ll> dist(n, INF);
    vector<int> P(n, -1); // 경로 복원을 위한 부모 배열(필요 없으면 생략)
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    dist[s] = 0; pq.push({0ll, s});
    while(!pq.empty()){
        auto [cdist, u] = pq.top(); pq.pop();
        if(dist[u] < cdist) continue;
        for(auto &[v, w] : G[u]) {
            ll ndist = cdist + w;
            if(dist[v] > ndist) {
                dist[v] = ndist;
                P[v] = u; // 경로 복원용
                pq.push({ndist, v});
            }
        }
    }
    if(dist[t] == INF) {
        return -1;
    }
    return dist[t];
    // --- 경로 복원 (필요시 사용) ---
    vector<int> path;
    for(int cur = t; cur != -1; cur = P[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
}
