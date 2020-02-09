#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//no.1反转字符串
void reverseString(char* s, int sSize){
    int i=0;int j=sSize-1;
    while(i<j){

        char tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
        i++;j--;
    }
}

//no.2整数反转
int reverse(int x) {
    long temp,result=0;;
    if(x>1534236461) return 0;
    while(x){
        temp=x%10;
        x=x/10;
        result=result*10+temp;
    }

    if(result>2147483642||result<(-2147483641)) return 0;
    return result;
}

//no.3字符串中的第一个唯一字符
int firstUniqChar(char * s){
    int len=strlen(s);
    if(len==0) return -1;
    if(len==1) return 0;

    int map[26];
    memset(map,0,sizeof(map));
    int index=0;
    for(int i=0;i<len;i++){
        index=s[i]-'a';
        map[index]++;
    }
    for(int i=0;i<len;i++){
        index=s[i]-'a';
        if(map[index]==1) return i;
    }
    return -1;
}

//no.4 有效的字母异位词
bool isAnagram(char * s, char * t){
    int len=strlen(s);
    int len2=strlen(t);
    if(len!=len2) return false;
    if(len==0) return true;
    if(len==1) return s[0]==t[0];

    int map[26];
    memset(map,0,sizeof(map));
    int index=0;
    for(int i=0;i<len;i++){
        index=s[i]-'a';
        map[index]++;
    }
    for(int i=0;i<len;i++){
        index=t[i]-'a';
        map[index]--;
    }
    for(int i=0;i<26;i++) if(map[i]!=0) return false;
    return true;
}

//no.5 验证回文字符串
bool isPalindrome(char* s) {
    int len = strlen(s);
    int j = 0;

    char array[len + 1];


    for(int i = 0; i < len; i++){
        if(isalnum(s[i])){
            array[j] = tolower(s[i]);
            j++;
        }
    }
    array[j] = '\0';
    len = strlen(array);
    for(int i = 0; i < len/2; i++){
        if(array[i] != array[len - i - 1]) return false;
    }
    return true;
}

//no.6 字符串转换整数 (atoi)
int myAtoi(char * str){
    int flag=0;
    int i=0;
    long result=0;
    int fu=1;
    int len=strlen(str);
    while(i<len){
        if(flag==0){
            if(str[i]==' ') i++;
            else if(str[i]=='-' && i<len-1) {
                if(!((str[i+1]<'0')||(str[i+1]>'9'))){
                    i++;fu=(-1);
                }else return 0;
            }
            else if(str[i]=='+' && i<len-1) {
                if(!((str[i+1]<'0')||(str[i+1]>'9'))){
                    i++;fu=(1);
                }else return 0;
            }
            else if(!((str[i]<'0')||(str[i]>'9'))){
                flag=1;result=str[i]-'0';i++;
            }
            else return 0;
        }else{
            if(!((str[i]<'0')||(str[i]>'9'))){
                result=result*10+str[i]-'0';
                i++;
                if(result>2147483647 && fu==1) {
                    result=2147483647;break;
                }
                if(result>2147483648 && fu==-1) {
                    result=2147483648;break;
                }
            }
            else {
                break;
            }
        }
    }
    return fu*result;

}

//no.7 实现 strStr()
int strStr(char * haystack, char * needle){
    int len_h=strlen(haystack);
    int len_n=strlen(needle);
    int i=0;
    if(len_h<len_n) return -1;
    else if(len_h==len_n){
        while(i<len_n){
            if(haystack[i]==needle[i]) i++;
            else return -1;
        }
        return 0;
    }else{
        for(int j=0;j<len_h-len_n+1;j++){
            i=0;
            while(i<len_n){
                if(haystack[i+j]==needle[i]) i++;
                else break;
            }
            if(i==len_n) return j;
        }
        return -1;
    }
}

//no.8 外观数列
char * countAndSay(int n){
    char *mark=(char *)malloc(sizeof(char)*5000);
    char *temp=(char *)malloc(sizeof(char)*5000);
    mark[0]='1';
    mark[1]='\0';//结束标志
    int i,count,j;
    char key,*p;
    for(i=1;i<n;i++)//迭代次数
    {
        j=0;
        key=mark[0];
        count=0;
        p=mark;
        while(*p!='\0')
        {
            if(*p==key)//计数
                count++;
            else{
                temp[j++]=count+'0';//先存计数器
                count=1;
                temp[j++]=key;//再存关键字
                key=*p;
            }
            p++;
            if(*p=='\0')
            {
                temp[j++]=count+'0';//先存计数器
                temp[j++]=key;//再存关键字
                temp[j]='\0';
            }
        }
        *p='\0';
        strcpy(mark,temp);
    }
    return mark;
}

//no.9 最长公共前缀
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {					// 没有就直接返回 ""
        char* ret = (char*)malloc(1);
        ret[0] = '\0';
        return ret;
    }
    int count = 0;							// 水平查找第几个
    int flag = true;						// 表示是否退出
    char c;									// 第一个字符串的标准
    char* str = (char*)calloc(128 , sizeof(char));						//分配空间128（至少），并初始化
    while (flag) {
        c = strs[0][count];
        for (int j = 0; j < strsSize; j++) {
            if ((strs[j][count]=='\0') || (strs[j][count] != c)) {		//退出条件
                flag = false;
                break;
            }
        }
        str[count] = c;						// 一样的字符保存
        count++;
    }
    str[count-1] = '\0';					// 去除最后一个
    return str;
}





