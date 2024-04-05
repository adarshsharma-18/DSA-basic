#include <stdio.h>
int main()
{
    printf("hello world");
    int a = 4;
    printf("%d\n", a);
    int *ptr = &a;
    printf("%d\n", ptr);
    printf("%d\n", &ptr);
    printf("%x\n", *ptr);
        return 0;
}
