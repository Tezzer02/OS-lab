#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, head; printf("No. requests: "); scanf("%d",&n);
    int req[n]; for(int i=0;i<n;i++) scanf("%d",&req[i]);
    printf("Initial head: "); scanf("%d",&head);
    int done[n]; for(int i=0;i<n;i++) done[i]=0;
    int total=0;
    for(int i=0;i<n;i++){
        int min=1e9, idx=-1;
        for(int j=0;j<n;j++){
            if(!done[j]){
                int d = abs(req[j]-head);
                if(d < min){ min=d; idx=j; }
            }
        }
        done[idx]=1; total += abs(req[idx]-head); head=req[idx];
    }
    printf("Total head movement=%d\n", total);
    return 0;
}
