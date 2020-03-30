#include<stdio.h>
#include<stdlib.h>

int main(){
    int s_queue[5] = {1,2,3,4,5};
    int t_queue[5] = {6,0,7,8,9};
    int ready_queue[10] = {0};
    int r = 0;
    
    int i = 0;
    int j = i+1;
    int t=0;
    
    for(i; i < 5 ; i++,j++){
        if(s_queue[i] != 0 && t_queue[i] == 0){
            ready_queue[r] = s_queue[i];
            r++;
        } else if(s_queue[i] != 0 && t_queue[i] != 0){
            ready_queue[r] = t_queue[i];
            r++;
            ready_queue[r]=s_queue[i];
            r++;
        } 
    }

    //printf("\t\t\t\t\t\t\t\t\n");
    printf("The constraints: \n");
    printf("1. Each number represents a person, all the number below or equal to 5 are students, and more than 5 are teachers.\n");
    printf("2.By default i have taken the maximum length of each queue as 5.\n");
    printf("3.Ready queue represents the order in which the request will be processed.\n");
    printf("4.0 represents that at that moment any one of both, teacher or student was at the counter.\n\n\n");
    printf("Order:");
    for(int m=0; m<10;m++){
        if(ready_queue[m] > 5){
            printf(" Teacher %d >",ready_queue[m]);
        }else if(ready_queue[m] < 5 && ready_queue[m] > 0){
            printf(" Student %d >",ready_queue[m]);
        }
        //printf("%d\n",ready_queue[m]);
    }
    printf("\n");
}
