#include<iostream>

using namespace std;

int main(){
    long long  a,b;
    
    scanf("%d%d",&a,&b);
    
    long long c=a*b;
    
    double d=c/12.0;
    
    printf("%.3lf",d);
    
    return 0;
}
