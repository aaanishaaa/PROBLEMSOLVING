#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the Number of Processes: ";
    cin >> n;

    int arrivalTime[n], burstTime[n], completionTime[n], turnaroundTime[n], waitingTime[n];

    cout << "Enter Arrival Time of each process: ";
    for(int i = 0; i < n; i++) {
        cin >> arrivalTime[i];
    }

    cout << "Enter Burst Time of each process: ";
    for(int i = 0; i < n; i++) {
        cin >> burstTime[i];
    }
    sort(burstTime, burstTime + n);
    int currentTime = 0;
    for(int i = 0; i < n; i++) {
        currentTime = max(currentTime, arrivalTime[i]);
        completionTime[i] = currentTime + burstTime[i];
        currentTime = completionTime[i];

        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }
    cout << "Process\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n";
    for(int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << arrivalTime[i] << "\t\t" << burstTime[i] << "\t\t"
             << completionTime[i] << "\t\t\t" << turnaroundTime[i] << "\t\t\t" << waitingTime[i] << endl;
    }
    double totalTAT = 0, totalWT = 0;
    for(int i = 0; i < n; i++) {
        totalTAT += turnaroundTime[i];
        totalWT += waitingTime[i];
    }
    double avgTAT = totalTAT / n;
    double avgWT = totalWT / n;
    cout << "\nAverage Turnaround Time: " << avgTAT << endl;
    cout << "Average Waiting Time: " << avgWT << endl;

    return 0;
}
