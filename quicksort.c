#include <quicksort.h>
#include <tview.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int arrayaccesqiick = 0;

int * quicksort(int num[], int size) {
    quicks(num, 0, size);
    return num;
}

void quicks(int *num, int start, int end) {
    if (end - start < 2){
        return;
    }
    int npivot = start;
    for (int i = start + 1; i < end; i++){
        if (num[i] <= num[start]) {
            int saved = num[npivot + 1];
            num[npivot + 1] = num[i];
            num[i] = saved;
            arrayaccesqiick += 6;
            npivot = npivot + 1;
        }
    }
    int saved = num[npivot];
    num[npivot] = num[start];
    num[start] = saved;
    arrayaccesqiick += 4;
    quicks(num, start, npivot);
    quicks(num, npivot + 1, end);
}

void stepquick_help(int *num, int start, int end, int size, int largest) {
    if (end - start < 2){
        return;
    }
    int npivot = start;
    for (int i = start + 1; i < end; i++){
        if (num[i] <= num[start]) {
            int saved = num[npivot + 1];
            num[npivot + 1] = num[i];
            num[i] = saved;
            npivot = npivot + 1;
            printstock(num, size, largest);
            usleep(20000);
        }
    }
    int saved = num[npivot];
    num[npivot] = num[start];
    num[start] = saved;
    printstock(num, size, largest);
    usleep(100);
    stepquick_help(num, start, npivot, size, largest);
    stepquick_help(num, npivot + 1, end, size, largest);
}

void stepquick(int *num, int size, int largest) {
    printstock(num, size, largest);
    stepquick_help(num, 0, size, size, largest);
}

void run_visualizer_quicksort(int *num, int size, int largest){
    int nums[size];
    memcpy(nums, num, sizeof(nums));
    clock_t t, start, stop;; 
    t = clock();
    arrayaccesqiick = 0;
    quicksort(nums, size);
    int temparracces = arrayaccesqiick;
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    start = clock();
    stepquick(num, size, largest);
    stop = clock();
    double time= ((double)(stop - start))/10000; // in sec
    printchararr("Algorithem: quicksort");
    printtime(time_taken);
    printarracces(temparracces);
    printtime(time);
}
