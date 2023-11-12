// TABULATION

#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];

    for(int i=0; i<n; i++){
        int pick = nums[i];
        if(i > 1) pick += dp[i-2];
        int notpick = dp[i-1];
        dp[i] = max(pick, notpick);
    }
    return dp[n-1];
}

// MEMOIZATION

#include <bits/stdc++.h> 

int f(int ind, vector<int> &a, vector<int> &dp){
    if(ind == 0) return a[ind];
    if(ind < 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int pick = a[ind] + f(ind-2, a, dp);
    int notpick = f(ind-1, a, dp);
    return dp[ind] = max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(n-1, nums, dp);
}

// RECURSION

#include <bits/stdc++.h> 

int f(int ind, vector<int> &a){
    if(ind == 0) return a[ind];
    if(ind < 0) return 0;

    int pick = a[ind] + f(ind-2, a);
    int notpick = f(ind-1, a);
    return max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    return f(nums.size()-1, nums);
}
