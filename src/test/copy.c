#include<stdio.h>
struct Student {
    int age;
    char name[100];
};
int main() {
    struct Student s[10];
    struct Student * p = s;
    s[0].age = 10;
    s[0]->age =10;
    p->age = 10;
    p++;
}