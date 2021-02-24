#include <stdio.h>
#include <stdlib.h>

void Move(int num, char from, char by, char to){
    if(num == 1)
        printf("Disk[1] from %c to %c\n", from, to);
    else{
        Move(num - 1, from, to, by);
        printf("Disk[%d] from %c to %c\n", num, from, to);
        Move(num - 1, by, from, to);
    }
}

int main(int argv, char* argc[]){
    int disk_num = atoi(argc[1]);

    Move(disk_num, 'A', 'B', 'C');
    
    return 0;
}