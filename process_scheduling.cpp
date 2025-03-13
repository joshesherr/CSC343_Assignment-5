#include <iostream>
#include <algorithm>
using namespace std;

// process information
struct Process {
    string name;
    int burstTime;
    int turnaroundTime;
    int waitingTime;
};

// FCFS
void calculateFCFS(Process proc[], int n) {
    printf("\nFCFS Scheduling:\n");
    
    int currentTime = 0;
    float totalWaiting = 0, totalTurnaround = 0;
    
    for(int i = 0; i < n; i++) {
        proc[i].waitingTime = currentTime;
        currentTime += proc[i].burstTime;
        proc[i].turnaroundTime = currentTime;
        
        totalWaiting += proc[i].waitingTime;
        totalTurnaround += proc[i].turnaroundTime;
    }
    
    // results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) printf("%s\t%d\t\t%d\t\t%d\n", proc[i].name.c_str(), proc[i].burstTime, proc[i].waitingTime, proc[i].turnaroundTime);
    
    printf("\nAverage Waiting Time: %.1f", totalWaiting/n);
    printf("\nAverage Turnaround Time: %.1f\n", totalTurnaround/n);
}

// Comparison for sorting by burst time
bool compare(Process a, Process b) {
    return a.burstTime < b.burstTime;
}

// SJF
void calculateSJF(Process proc[], int n) {
    printf("\nSJF Scheduling:\n");
    
    sort(proc, proc + n, compare);
    
    int currentTime = 0;
    float totalWaiting = 0, totalTurnaround = 0;
    
    for(int i = 0; i < n; i++) {
        proc[i].waitingTime = currentTime;
        currentTime += proc[i].burstTime;
        proc[i].turnaroundTime = currentTime;
        
        totalWaiting += proc[i].waitingTime;
        totalTurnaround += proc[i].turnaroundTime;
    }
    
    // results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) printf("%s\t%d\t\t%d\t\t%d\n", proc[i].name.c_str(), proc[i].burstTime, proc[i].waitingTime, proc[i].turnaroundTime);
    
    printf("\nAverage Waiting Time: %.1f", totalWaiting/n);
    printf("\nAverage Turnaround Time: %.1f\n", totalTurnaround/n);
}

int main() {
    const int n = 5;
    Process processes[n] = {
        {"P1", 2, 2},
        {"P2", 1, 1},
        {"P3", 8, 4},
        {"P4", 4, 2},
        {"P5", 5, 3}
    };
    
    // Create copies for both calculations
    Process fcfs[n], sjf[n];
    for(int i = 0; i < n; i++) {
        fcfs[i] = processes[i];
        sjf[i] = processes[i];
    }
    
    calculateFCFS(fcfs, n);
    calculateSJF(sjf, n);
    
    return 0;
}