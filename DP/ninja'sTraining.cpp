// RECURSION


int f(int day, int last, vector<vector<int>> &task){
    int maxi;
    if(day == 0){
        maxi = 0;
        for(int t=0; t<3; t++){
            if(t != last){
                maxi = max(maxi, task[0][t]);
            }
        }
        return maxi;
    }
    
    maxi = 0;

    for(int t=0; t<3; t++){
        if (t != last) {
            maxi = max(maxi, task[day][t] + f(day - 1, t, task));
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return f(n-1, 3, points);
}
