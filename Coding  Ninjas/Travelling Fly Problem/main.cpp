string fly(int n){
    if(n==1) return "YES";
    if(n==2) return "YES";
    vector<int> v(n, 0);
    int step = 0;
    for(int i = 0 ; i < n ; i++){
        v[step] = 1;

        step = (step + (i+1))%(n);
    }

    for(int i : v) {
        if(i == 0) return "NO";
    }

    return "YES";
}
