#include <stdio.h>
#include <limits.h>
int main() {
    int n; printf("Number of processes: "); scanf("%d",&n);
    int bt[50], at[50], ct[50], tat[50], wt[50], completed=0, current_time=0;
    for(int i=0;i<n;i++){ printf("Arrival P%d: ",i+1); scanf("%d",&at[i]); printf("BT P%d: ",i+1); scanf("%d",&bt[i]); }
    for(int i=0;i<n;i++){ wt[i]=0; tat[i]=0; }
    while(completed<n) {
        int idx=-1; int min_bt=INT_MAX;
        for(int i=0;i<n;i++) {
            if(at[i]<=current_time && bt[i]>0 && bt[i]<min_bt) { min_bt=bt[i]; idx=i; }
        }
        if(idx!=-1) {
            current_time += bt[idx];
            ct[idx] = current_time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - (min_bt);
            bt[idx]=0;
            completed++;
        } else current_time++;
    }
    printf("P\tAT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++) printf("P%d\t%d\t%d\t%d\t%d\n",i+1,at[i],ct[i],tat[i],wt[i]);
    return 0;
}
