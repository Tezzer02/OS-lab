#include <stdio.h>
/* Simple deadlock detection using resource-allocation graph matrices */
int main(){
    int n,m; printf("Processes and resources: "); scanf("%d%d",&n,&m);
    int alloc[10][10], req[10][10], avail[10];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&alloc[i][j]);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&req[i][j]);
    for(int j=0;j<m;j++) scanf("%d",&avail[j]);
    int finish[10]={0};
    int changed=1;
    while(changed){
        changed=0;
        for(int i=0;i<n;i++){
            if(!finish[i]){
                int ok=1;
                for(int j=0;j<m;j++) if(req[i][j] > avail[j]) { ok=0; break; }
                if(ok){
                    for(int j=0;j<m;j++) avail[j]+=alloc[i][j];
                    finish[i]=1; changed=1;
                }
            }
        }
    }
    int dead=0;
    for(int i=0;i<n;i++) if(!finish[i]) { dead=1; printf("Process P%d possibly deadlocked\n", i); }
    if(!dead) printf("No deadlock detected\n");
    return 0;
}
