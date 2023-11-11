// Space Optimised
#include <bits/stdc++.h> 
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    int cur=0, p1=0, p2=0;

    for(int i=1; i<n; i++){
        int fs = p1 + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = p2 + abs(heights[i] - heights[i-2]);
        cur = min (fs, ss);
        p2 = p1;
        p1 = cur;
    }
    return p1;
}
