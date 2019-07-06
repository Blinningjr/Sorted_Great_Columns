#include <stdio.h>
#include <tview.h>

void clearterminal(){
    printf("\e[1;1H\e[2J");
}

void printarracces(int num) {
    printf("Array acces: %d times \n", num);
}

void printtime(double num) {
    printf("Time: %f sec \n", num);
}

void printchararr(char *chars){
    printf("%s\n",chars);
}

void printintarr(int *num, int size){
    for (int i = 0; i < size; i++){
        printf("%d,", num[i]);
    }
    printf("\n");
}

void printstock(int *num, int size, int largestnum){
    clearterminal();
    int hight = largestnum;
    while (hight > 0) {
        for (int i = 0; i < size; i++) {
            if (hight <= num[i]) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
        hight -= 1;
    }
}

void inputsize(int *size){
    int temp =0;
    while (temp < 1 || temp > 500){
        clearterminal();
        printf("Input a size of array(1<=size<=500):");
        scanf("%d", &temp);
    }
    *size = temp;
}

void inputmaxvalue(int *maxvalue){
    int temp =0;
    while (temp < 1 || temp > 200){
        clearterminal();
        printf("Input a max value(1<=max value<=200):");
        scanf("%d", &temp);
    }
    *maxvalue = temp;
}

void inputalgorithm(char *algorithm){
    char temp = 'n';
    while (temp != 'q' && temp != 'm'){
        clearterminal();
        printf("Unput algorithm(q = quicksort or m = mergesort):");
        scanf("%c", &temp);
    }
    *algorithm = temp;
}
