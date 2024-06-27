#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the Number of Processes: ";
    cin >> n;
    int At[n], Bt[n], Ct[n], Tat[n], Wt[n];
    int totaltat = 0, totalwt = 0;
    cout << "Enter Arrival Time of each process: ";
    for(int i = 0; i < n; i++) {
        cin >> At[i];
    }
    cout << "Enter Burst Time of each process: ";
    for(int i = 0; i < n; i++) {
        cin >> Bt[i];
    }
    int sum = At[0];
    for(int i = 0; i < n; i++) {
        sum += Bt[i];
        Ct[i] = sum;
    }
    for(int i = 0; i < n; i++) {
        Tat[i] = Ct[i] - At[i];
        totaltat += Tat[i];
    }
    cout << "Total Turnaround Time: " << totaltat << endl;

    for(int i = 0; i < n; i++) {
        Wt[i] = Tat[i] - Bt[i];
        totalwt += Wt[i];
    }
    cout << "Total Waiting Time: " << totalwt << endl;
    int avgtat = totaltat / n;
    int avgwt = totalwt / n;
    cout << "Average Turnaround Time: " << avgtat << endl;
    cout << "Average Waiting Time: " << avgwt << endl;
    return 0;
}
