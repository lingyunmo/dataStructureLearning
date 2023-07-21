#include <iostream>
#include <vector>
using namespace std;

int (*function)(int a,int b);
int function1(int a,int b);
int function2(int a,int b);
int normalFunction(int a,int b,int (*function)(int a,int b));
int main(){
    normalFunction(1,2,function1);
}

int function1(int a,int b){
    return a+b;
}

int function2(int a,int b){
    return a-b;
}

int normalFunction(int a,int b,int (*function)(int a,int b)){
    return a*b+function(a,b);
}