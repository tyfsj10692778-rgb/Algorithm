#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    double n;
    scanf("%lf",&n);
    //m为整数部分，k为小数部分
    int m=(int)n;
    double k=n-m;
    //整数部分
    int a=m%100,A=m/100;
    int b=a%50,B=a/50;
    int c=b%20,C=b/20;
    int d=c%10,D=c/10;
    int e=d%5,E=d/5;
    int f=e%2,F=e/2;
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n%d nota(s) de R$ 50.00\n%d nota(s) de R$ 20.00\n%d nota(s) de R$ 10.00\n%d nota(s) de R$ 5.00\n%d nota(s) de R$ 2.00\n",A,B,C,D,E,F);
    //小数部分
    k+=f;
    int i=0,p=0,q=0,r=0,s=0;
    while(k>=1){
        k--;
        i++;
    }
    while(k>=0.5){
        k-=0.5;
        p++;
    }
    while(k>=0.25){
        k-=0.25;
        q++;
    }
    while(k>=0.1){
        k-=0.1;
        r++;
    }
    while(k>=0.05){
        k-=0.05;
        s++;
    }
    int u =(int)round(k/0.01);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n%d moeda(s) de R$ 0.50\n%d moeda(s) de R$ 0.25\n%d moeda(s) de R$ 0.10\n%d moeda(s) de R$ 0.05\n%d moeda(s) de R$ 0.01\n",i,p,q,r,s,u);

    return 0;
}
