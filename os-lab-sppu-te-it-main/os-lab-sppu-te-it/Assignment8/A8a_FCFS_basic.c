#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, head; printf("No. requests: "); scanf("%d",&n);
    int req[n]; printf("Requests: "); for(int i=0;i<n;i++) scanf("%d",&req[i]);
    printf("Initial head: "); scanf("%d",&head);
    int total=0;
    for(int i=0;i<n;i++){ total += abs(req[i]-head); head=req[i]; }
    printf("Total head movement=%d\n", total);
    return 0;
}
