#include <bits/stdc++.h> 

// same function from the maxsum of subsequences without adjacent elements 
long long helper(vector<int> &nums){
    int n = nums.size();
    long long cur=nums[1], prev1=nums[0], prev2=0;

    for(int i=1; i<n; i++){
        long long pick = nums[i];
        if(i > 1) pick += prev2;
        long long notpick = prev1;
        cur = max(pick, notpick);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
    vector<int> temp1, temp2;

    for(int i=0; i<n; i++){
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(helper(temp1), helper(temp2));
}
