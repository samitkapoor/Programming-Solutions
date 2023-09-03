void selectionSort(vector<int>&arr) {
    for(int i = 0 ; i < arr.size() ; i++){
        int mini = i;
        for(int j = i+1 ; j < arr.size() ; j++){
            if(arr[mini] > arr[j]) {
                mini = j;
            }
        }

        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
