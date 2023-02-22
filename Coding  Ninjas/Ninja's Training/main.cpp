int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> lastTasks(4, 0);

    lastTasks[0] = max(points[0][1], points[0][2]);
    lastTasks[1] = max(points[0][0], points[0][2]);
    lastTasks[2] = max(points[0][0], points[0][1]);
    lastTasks[3] = max(points[0][1], max(points[0][0], points[0][2]));

    for(int i = 1 ; i < n ; i++){
        vector<int> temp(4, 0);
        for(int last = 0 ; last < 4 ; last++){
            temp[last] = 0;

            for(int task = 0 ; task < 3 ; task++){
                if(task != last) {
                    temp[last] = max(temp[last], points[i][task] + lastTasks[task]);
                }
            }
        }

        lastTasks = temp;
    }

    return lastTasks[3];
}
