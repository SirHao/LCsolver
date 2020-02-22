#include <zconf.h>
#include <stdbool.h>

//
// Created by lucas on 2020/2/10.
//
//
struct ListNode {
    int val;
    struct ListNode *next;
    };
//no.1 删除链表中的节点
void deleteNode(struct ListNode* node) {
    *node=*(node->next);
}
//no.2 删除链表的倒数第N个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL || n == 0)
        return head;
    struct ListNode *first, *second;
    first = head;second = head;
    while(n--) first = first->next;
    if(first == NULL) return head->next;
    while(first->next){
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return head;

}
//no.3 反转链表
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
//no.4 合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)return l2;
    if(l2==NULL)return l1;
    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}
//no.5 回文链表
bool isPalindrome (struct ListNode* head){
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
//no.6 环形链表
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast=head,*slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) return true;
    }
    return false;
}