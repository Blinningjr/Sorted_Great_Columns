#include <mergesort.h>
#include <tview.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int arrayacces = 0;

void drawsleep(int *num, int size, int largestnum){
    printstock(num, size, largestnum);
    usleep(20000);
}

void partition(int *num, int start, int end){
    if (end - start < 2) {
        return;
    }
    int half = start + (end- start)/2;
    partition(num, start, half);
    partition(num, half, end);
    int b = half;
    int a = start;
    while (a < end-1)
    {
        if (a >= b || b >= end){
            return;
        }
        if (num[a] > num[b]){
            int temp = num[b];
            arrayacces += 3;
            for (int i = b; i > a; i--){
                num[i] = num[i-1];
                arrayacces += 2;
            }
            num[a] = temp;
            arrayacces += 1;
            b += 1;
        }
        a +=1;
    }
}

int * mergesort(int num[], int size){
    partition(num, 0, size);
    return num;
}

void steppartition(int *num, int start, int end, int size, int largestnum){
    if (end - start < 2) {
        return;
    }
    int half = start + (end- start)/2;
    steppartition(num, start, half, size, largestnum);
    steppartition(num, half, end, size, largestnum);
    int b = half;
    int a = start;
    while (a < end-1)
    {
        if (a >= b || b >= end){
            return;
        }
        if (num[a] > num[b]){
            int temp = num[b];
            for (int i = b; i > a; i--){
                num[i] = num[i-1];
            }
            num[a] = temp;
            drawsleep(num, size, largestnum);
            b += 1;
        }
        a +=1;
    }
}

void stepmergsort(int num[], int size, int largestnum){
    drawsleep(num, size, largestnum);
    steppartition(num, 0, size, size, largestnum);
}

void run_visualizer_mergesort(int *num, int size, int largest){
  int nums[size];
  arrayacces = 0;
  memcpy(nums, num, sizeof(nums));
  clock_t t, start ,stop; 
  t = clock();
  mergesort(nums, size);
  int accestemp = arrayacces;
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  start = clock();
  stepmergsort(num, size, largest);
  stop = clock();
  double time= ((double)(stop - start))/10000; // in sec
  printchararr("Algorithem: mergesort");
  printtime(time_taken);
  printarracces(accestemp);
  printtime(time);
}
