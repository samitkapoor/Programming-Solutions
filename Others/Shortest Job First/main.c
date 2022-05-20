#include<stdio.h>

int main(){

    int n;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    
    int processes[n], burst_time[n];
    
    printf("Enter the burst time for : \n");
    for(int i=0 ; i<n ; i++){
        printf("Process - %d : ", i+1);
        scanf("%d", &burst_time[i]);
        processes[i] = i+1;
    }
    
    int w[n], tat[n];
    int total_waiting_time = 0;
    
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n-1 ; j++){
            if(burst_time[j] > burst_time[j+1]){
                int temp = burst_time[j];
                burst_time[j+1] = burst_time[j];
                burst_time[j] = temp;
                
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
    
    
    
    for(int i=0 ; i<n ; i++){
        w[i] = 0;
        for(int j=0 ; j<i ; j++){
            w[i]+=burst_time[j];
        }
        
        total_waiting_time += w[i];
    }
    
    int average_waiting_time = (float)total_waiting_time/n;
    int total_turn_around_time = 0;
    
    for(int i=0 ; i<n ; i++){
        tat[i] = w[i] + burst_time[i];
        total_turn_around_time+=tat[i];
    }
    
    int average_turn_around_time = (float)total_turn_around_time/n;
    
    printf("Total turn around time: %d\nTotal waiting time : %d\nAverage Waiting Time : %d\nAverage Turn Around Time : %d\n", total_turn_around_time,total_waiting_time,average_waiting_time,average_turn_around_time);
    
    return 0;
}
