/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include<stdio.h>
#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode * p = head;
        while(p != NULL){
            len ++;
            p = p->next;
        }
        int pos = len/2;
        p = head;
        for(int i=0;i<pos;i++)
            p = p->next;
        return p;
    }
};

int main(){
    ListNode *head;
    ListNode *temp[6];
    for(int i=0;i<6;i++)
        temp[i] = new ListNode(i+1);
    cout<<"ini finsh"<<endl;
    for(int i=0;i<6;i++){
        if(i != 5){
            temp[i]->next = temp[i+1];
        }
    }
    head = temp[0];
    auto re = Solution().middleNode(head);
    while(re != NULL){
        cout<<re->val<<"  ";
        re = re->next;
    }

}
