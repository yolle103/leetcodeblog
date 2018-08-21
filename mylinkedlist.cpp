#include<stdio.h>
#include<iostream>
using namespace std;

class MyLinkedList{
public:
    MyLinkedList(){
        root = NULL;
        len = 0;
    }
    int get(int index){
        LinkNode *p = root;
        if(index>=len)
            return -1;
        for(int i=0;i<index; i++){
            p = p->next;
        }
        return p->val;
    }

    void addAtHead(int val){
        LinkNode * newhead = new LinkNode(val);
        newhead->next = root;
        root = newhead;
        len++;
    }
    void addAtTail(int val){
        LinkNode *newtail = new LinkNode(val);
        LinkNode *p = root;
        while(p->next != NULL)
            p = p->next;
        p->next = newtail;
        len++;
    }
    void addAtIndex(int index, int val){
        if(index >len)
            return;

        // add at tail
        if(index == len)
            addAtTail(val);
        else if(index == 0)
            addAtHead(val);
        else{
            LinkNode *p = root;
            LinkNode *newnode = new LinkNode(val);
            LinkNode * pre;
            for(int i=0; i<index; i++){
                pre = p;
                p = p->next;
            }
            pre->next = newnode;
            newnode->next = p;
        }
        len++;


    }
    void deleteAtIndex(int index){
        if(index >len)
            return;
        LinkNode * delnode;
        LinkNode *p = root;
        LinkNode *pre;
        if(index == 0){
            delnode = root;
            root = root->next;
        }else{
            for(int i=0;i<index; i++){
                pre = p;
                p = p->next;
            }
            delnode = p;
            pre->next = p->next;
        }
        delete delnode;
    }
    void pprint(){
        LinkNode * p =root;
        while(p != NULL){
            cout<<p->val<<"  ";
            p = p->next;
        }
        cout<<endl;
    }
private:
    struct LinkNode{
        int val;
        LinkNode *next;
        LinkNode(int x):val(x), next(NULL){}
    };
    LinkNode * root;
    int len;
};
int main(){
    MyLinkedList mylist;
    mylist.addAtHead(1);
    mylist.addAtHead(2);
    mylist.addAtTail(3);
    cout<<mylist.get(0)<<endl;
    cout<<mylist.get(4)<<endl;
    mylist.addAtIndex(1, 5);
    mylist.addAtIndex(4, 4);
    mylist.pprint();
    mylist.deleteAtIndex(0);
    mylist.pprint();
    mylist.deleteAtIndex(3);
    mylist.pprint();
    mylist.deleteAtIndex(1);
    mylist.pprint();
}

