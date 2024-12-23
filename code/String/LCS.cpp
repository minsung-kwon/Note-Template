string LCS(const string &A, const string &B) {
    int n = (int)A.size(); int m = (int)B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int len = dp[n][m];
    string lcs; lcs.resize(len);
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(A[i - 1] == B[j - 1]){
            lcs[len - 1] = A[i - 1]; 
            i--; j--; len--;
        }
        else {
            if(dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        }
    }
    return lcs; // 복원된 LCS 문자열 반환
}
