#include <stdio.h>
int main() {
    int n; printf("Number of processes: "); scanf("%d",&n);
    int bt[50], wt[50], tat[50];
    for(int i=0;i<n;i++){ printf("BT P%d: ",i+1); scanf("%d",&bt[i]); }
    wt[0]=0; for(int i=1;i<n;i++) wt[i]=wt[i-1]+bt[i-1];
    for(int i=0;i<n;i++) tat[i]=wt[i]+bt[i];
    printf("P\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++) printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    return 0;
}
