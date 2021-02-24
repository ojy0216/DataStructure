#include <stdio.h>

typedef struct _empInfo{
    int empNum;
    int age;
} EmpInfo;

int main(){
    EmpInfo empInfoArr[1000];
    EmpInfo ei;
    int eNum;

    printf("empNum, age: ");
    scanf("%d %d", &(ei.empNum), &(ei.age));
    empInfoArr[ei.empNum] = ei;

    printf("empNum: ");
    scanf("%d", &eNum);

    ei = empInfoArr[eNum];
    printf("empNum: %d, age: %d\n", ei.empNum, ei.age);

    return 0;
}