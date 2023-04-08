#include <iostream>
using namespace std;
int score[10000];
int main()
{
    int n=0,j=0,k=0;
    float jg,yx;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> score[i];
    }
    for(int i=0;i<n;i++){
        if(score[i]>=60){
            j++;
        }
        if(score[i]>85){
            k++;
        }
    }
    jg=((float)j*100/(float)n*100);
    yx=((float)k*100/(float)n*100);
    printf("%.0f%\n",jg);
    printf("%.0f%",yx);
    return 0;
}