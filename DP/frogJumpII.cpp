// TABULATION
int minimizeCost(int n, int k, vector<int> &a){
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<n; i++){
        for(int j=1; j<=k && i-j >=0; j++){
            int jump = dp[i-j] + abs(a[i] - a[i-j]);
            dp[i] = min(dp[i], jump);
        
        }        
    }
    return dp[n-1];
}


// Memoized
int f(int ind, vector<int> &a, vector<int> &dp, int k){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int minsteps = INT_MAX;

    for(int i=1; i<=k; i++){
        if(ind-i >= 0){
            int jump = f(ind-i, a, dp, k) + abs(a[ind] - a[ind-i]);
            minsteps = min(minsteps, jump);
        }
    }
    return dp[ind] = minsteps;
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n, -1);
    return f(0, height, dp, k);
}


// Recursion

int f(int ind, int k, vector<int> a){
    if(ind == 0) return 0;
    int minsteps = INT_MAX;

    for(int i=1; i<k; i++){
        if((ind - i)>=0){
            int jumpe = f(ind-i, k, a) + abs(a[ind] - a[ind-i]);
            minsteps = min(jumpe, minsteps);
        }
    }
    return minsteps;
}

int minimizeCost(int n, int k, vector<int> &height){
    return f(0, k, height);
}
