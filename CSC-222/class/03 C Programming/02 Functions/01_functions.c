#include <stdio.h>

// you can define functions up here
//  - need to state types for returns and formal parameters

int addOne(int value){
    return value+1;
}

int main(){
    int num = 10;
    int result = addOne(num);
    result = addOne(result);

    printf("New result is: %d.\n", result);
    return 0;
}