#include <stdio.h>
#include <limits.h>
int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for(int i=1;i<n;i++) if(time[i] < min) { min = time[i]; pos = i; }
    return pos;
}
int main(){
    int n, frames;
    printf("No. pages: "); scanf("%d",&n);
    int pages[n]; printf("Pages: "); for(int i=0;i<n;i++) scanf("%d",&pages[i]);
    printf("Frames: "); scanf("%d",&frames);
    int frame[frames], time[frames];
    for(int i=0;i<frames;i++){ frame[i] = -1; time[i]=0; }
    int counter=0, faults=0;
    for(int i=0;i<n;i++){
        int found=0, freeIndex=-1;
        for(int j=0;j<frames;j++){
            if(frame[j]==pages[i]) { counter++; time[j]=counter; found=1; break; }
            if(frame[j]==-1) freeIndex=j;
        }
        if(!found){
            if(freeIndex!=-1){
                counter++; frame[freeIndex]=pages[i]; time[freeIndex]=counter; faults++;
            } else {
                int pos = findLRU(time, frames);
                counter++; frame[pos]=pages[i]; time[pos]=counter; faults++;
            }
        }
    }
    printf("Page faults = %d\n", faults);
    return 0;
}
