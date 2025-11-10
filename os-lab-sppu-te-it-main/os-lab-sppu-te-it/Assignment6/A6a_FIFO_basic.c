#include <stdio.h>
int main() {
    int n,f; printf("No. pages: "); scanf("%d",&n);
    int pages[50], frames[10], i,j,k=0, faults=0;
    printf("Pages: "); for(i=0;i<n;i++) scanf("%d",&pages[i]);
    printf("Frames: "); scanf("%d",&f);
    for(i=0;i<f;i++) frames[i]=-1;
    for(i=0;i<n;i++){
        int found=0;
        for(j=0;j<f;j++) if(frames[j]==pages[i]) { found=1; break; }
        if(!found){ frames[k]=pages[i]; k=(k+1)%f; faults++; }
    }
    printf("Faults=%d\n",faults);
    return 0;
}
