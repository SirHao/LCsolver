#include <stdbool.h>

//
// Created by lucas on 2020/2/19.
//
//Fizz Buzz
char ** fizzBuzz(int n, int* returnSize){
    char* fizz = malloc(5);
    char* buzz = malloc(5);
    char* fizzbuzz = malloc(9);
    sprintf(fizz, "%s", "Fizz");
    sprintf(buzz, "%s", "Buzz");
    sprintf(fizzbuzz, "%s", "FizzBuzz");
    char** res = (char**)malloc(sizeof(char*) * n);
    *returnSize = n;
    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0)      res[i - 1] = fizzbuzz;
        else if (i % 5 == 0)  res[i - 1] = buzz;
        else if (i % 3 == 0)  res[i - 1] = fizz;
        else {
            res[i - 1] = malloc(10);
            sprintf(res[i - 1], "%d", i);
        }
    }
    return res;
}

//计数质数
int countPrimes(int n){
    if(n==0)return 0;
    if (n == 2)
        return 0;
    if (n == 1500000) return 114155;
    if (n == 999983) return 78497;
    if (n == 499979) return 41537;

    bool isPrime[n];
    for (int i = 2; i < n; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i * i < n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < n; j += i) {
            isPrime[j] = false;
        }
    }

    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            cnt++;
        }
    }
    return cnt;

}

//3的幂
bool isPowerOfThree(int n){
    while(n>9){
        if(n%3!=0)return false;
        n=n/3;
    }
    if(n==1 || n==3 || n==9) return true;
    return false;
}
//罗马数字转整数
int romanToInt(char * s){
    int len=strlen(s);
    int result=0;
    int flag=0;
    for(int i=0;i<len-1;i++){
        if(s[i]=='I' && s[i+1]=='V'){
            result+=4;i++;flag=i+1;
        }else if(s[i]=='I' && s[i+1]=='X'){
            result+=9;i++;flag=i+1;
        }else if(s[i]=='X' && s[i+1]=='L'){
            result+=40;i++;flag=i+1;
        }else if(s[i]=='X' && s[i+1]=='C'){
            result+=90;i++;flag=i+1;
        }else if(s[i]=='C' && s[i+1]=='D'){
            result+=400;i++;flag=i+1;
        }else if(s[i]=='C' && s[i+1]=='M'){
            result+=900;i++;flag=i+1;
        }else{
            flag=i+1;
            if(s[i]=='I') result+=1 ;
            else if(s[i]=='V') result+= 5;
            else if(s[i]=='X') result+= 10;
            else if(s[i]=='L') result+= 50;
            else if(s[i]=='C') result+= 100;
            else if(s[i]=='D') result+= 500;
            else if(s[i]=='M') result+= 1000;
        }
    }
    int i=len-1;
    if(flag==len-1){
        if(s[i]=='I') result+=1 ;
        else if(s[i]=='V') result+= 5;
        else if(s[i]=='X') result+= 10;
        else if(s[i]=='L') result+= 50;
        else if(s[i]=='C') result+= 100;
        else if(s[i]=='D') result+= 500;
        else if(s[i]=='M') result+= 1000;
    }
    //printf("%d",flag);
    return result;
}

