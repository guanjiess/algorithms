#include <stdio.h>
struct studentInfo{
    int id;
    char gender;
    char name[20];
    char major[20];
};

int main(){
    struct studentInfo Alice;
    struct studentInfo GGbond;
    Alice.id = 10086;
    Alice.gender = 'f';
    strcpy(Alice.name, 'Alice Webb');
    strcpy(Alice.major, 'EE');

    printf("Alice's id is %d", Alice.id);
    return 0;
}
