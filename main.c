#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char * s){
    int len=strlen(s);
    if(len==0) return false;
    if(len==1) return true;
    int i=0;int j=len-1;
    while(i<j){
        while((s[i]<'0'|| s[i]>'9') && (s[i]<'a'||s[i]>'z') && (s[i]<'A'|| s[i]>'Z')) i++;
        while((s[j]<'0'||s[j]>'9') && (s[j]<'a'|| s[j]>'z') && (s[j]<'A' || s[j]>'Z')) j--;
        if(s[i]==s[j]){
            i++;j--;continue;
        }
        if(((s[i]-'a')==(s[j]-'A')) || ((s[j]-'a')==(s[i]-'A')) ){
            i++;j--;continue;
        }
        if((s[i]-'0')>10) return false;
        return false;
    }
    return true;
}



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
            }
            else {
                break;
            }
        }
    }
    if(result>2147483648 && fu==1) result=2147483647;
    if(result>2147483648 && fu==-1) result=2147483648;
    return fu*result;

}


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
struct ListNode {
         int val;
         struct ListNode *next;
    };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL)
        return head;
    else{
        struct ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
}

bool is_Palindrome (struct ListNode* head){
    if(head==NULL || head->next==NULL) return true;
    struct ListNode* ptr=head;
    int link_count=1;
    while(ptr->next!=NULL)  {
        ptr=ptr->next;
        link_count++;
    }
    struct ListNode *ptr2;
    struct ListNode *newhead;
    if(link_count%2==0){
        link_count=link_count/2;
        ptr=head;
        for(int i=0;i<link_count-1;i++) ptr=ptr->next;

        ptr2=ptr->next;
        ptr->next=NULL;

        newhead=reverseList(head);
    }else{
        link_count=link_count/2;
        ptr=head;
        for(int i=0;i<link_count-1;i++) ptr=ptr->next;

        ptr2=ptr->next->next;
        ptr->next=NULL;

        newhead=reverseList(head);
    }
    for(int i=0;i<link_count;i++) {
        if(newhead->val!=ptr2->val) return false;
        newhead=newhead->next;
        ptr2=ptr2->next;
    }
    return true;

}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int main() {
    struct ListNode fir,sec,thr;
    struct ListNode *fir_ptr;
    fir_ptr=&fir;
    fir.next=&sec;
    sec.next=&thr;
    thr.next=NULL;
    fir.val=1;
    sec.val=0;
    thr.val=0;
    bool bb=is_Palindrome(fir_ptr);
   int a;
    return 0;
}