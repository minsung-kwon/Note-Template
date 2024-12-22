typedef vector<vector<ll>> matrix;
matrix operator * (const matrix &a, const matrix &b) {
    ll size = a.size(); matrix res(size, vector<ll>(size));
    for (ll i = 0; i < size; i++) {
        for (ll j = 0; j < size; j++) {
            for (ll k = 0; k < size; k++) res[i][j] += a[i][k] * b[k][j];
            res[i][j] %= mod;
        }
    }
    return res;
}
 
matrix Power(matrix a, ll n) {
    ll size = a.size(); matrix res(size, vector<ll>(size));
    for (ll i = 0; i < size; i++) res[i][i] = 1;
    while (n > 0) {
        if (n % 2 == 1) res = res * a;
        n /= 2; a = a * a;
    }
    return res;
}
