#include <stdio.h>
int main() {
    int n,m;
    printf("Processes and resources: "); scanf("%d%d",&n,&m);
    int alloc[10][10], max[10][10], avail[10], need[10][10];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&alloc[i][j]);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&max[i][j]);
    for(int j=0;j<m;j++) scanf("%d",&avail[j]);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) need[i][j]=max[i][j]-alloc[i][j];
    int finish[10]={0}, safe[10],ind=0;
    int count=0;
    while(count<n) {
        int found=0;
        for(int i=0;i<n;i++) {
            if(!finish[i]) {
                int j; for(j=0;j<m;j++) if(need[i][j]>avail[j]) break;
                if(j==m) {
                    for(int k=0;k<m;k++) avail[k]+=alloc[i][k];
                    safe[ind++]=i; finish[i]=1; found=1; count++;
                }
            }
        }
        if(!found) break;
    }
    if(count==n){ printf("Safe sequence: "); for(int i=0;i<n;i++) printf("P%d ",safe[i]); printf("\n");}
    else printf("Not safe\n");
    return 0;
}
