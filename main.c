#include <stdlib.h>
#include <tview.h>
#include <quicksort.h>
#include <mergesort.h>

int size = 0;
int maxvalue = 0;
char algorithm = 'n';
int largest;

int find_largestnum(int *num, int size) {
  int largest = num[0];
  for (int i = 1; i < size; i++) {
    if (num[i] > largest) {
      largest = num[i];
    }
  }
  return largest;
}

void fillarrayrand(int *num, int size, int maxvalue){
  for (int i = 0; i < size; i++){
    num[i] = rand() % maxvalue;
  }
}

int main() {

  inputalgorithm(&algorithm);

  if (algorithm == 'q'){
    inputsize(&size);
    inputmaxvalue(&maxvalue);

    int ivar[size];
  
    fillarrayrand(ivar, size, maxvalue);
    largest = find_largestnum(ivar, size);

    run_visualizer_quicksort(ivar, size, largest);
  } else if (algorithm == 'm'){
    inputsize(&size);
    inputmaxvalue(&maxvalue);

    int ivar[size];
    
    fillarrayrand(ivar, size, maxvalue);
    largest = find_largestnum(ivar, size);
    run_visualizer_mergesort(ivar, size, largest); 
  }

  return 0;
}