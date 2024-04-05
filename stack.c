#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
}s;

int IsEmpty(int* arr){
    if (s.top == -1) 
    return 1;
}

void Push(int value){
    

int main(){
    s.size = 4;
    s.top = -1;
    s.arr = (int*)malloc(s.size*sizeof(int));
    s.arr[s.top] =12;
    s.top++;
    if (IsEmpty(s.arr))
    printf("Empty stack");
    else
    printf("Stack is  not empty");

}