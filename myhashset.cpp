#include<list>
#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;
class MyHashSet{
public:
    MyHashSet(){
        this->hashset = vector<list<int> *>(1000, NULL);
    }
    void add(int key){
        int value = hashfunc(key);
        cout<<"add "<<value<<endl;
        list<int> * llist;
        if(this->hashset[value] == NULL){
            cout<<"new bucket"<<endl;
            llist = new list<int>();
            this->hashset[value] = llist;
        }else
            llist = this->hashset[value];
        // check if the key already in set
        // if in dont add
        for(auto k:*llist){
            if(k == key)
                return;
        }
        // add key
        llist->push_back(key);
    }

    void remove(int key){
        int value = hashfunc(key);
        cout<<"remove "<<key<<endl;
        list<int> * llist = NULL;
        llist = this->hashset[value];
        // value not in
        if(llist == NULL)
            return;
        else{
            llist->remove(key);
        }
        
    }
    bool contains(int key){
        int value = hashfunc(key);
        cout<<"search "<<key<<endl;
        list<int> * llist = NULL;
        llist = this->hashset[value];
        // value not in
        if(llist != NULL)
            for(auto l: *llist){
                if(l == key)
                    return true;
            }
        return false;
            
        }
    
    
    void pprint(){
        for(auto i: this->hashset){
            if(i != NULL){
                list<int> * temp = i;
                for(auto c:*temp)
                    cout<<c<<"   ";
                cout<<endl;
                cout<<"---------"<<endl;
            }

        }
    }
private:
    int hashfunc(int key){return key%1000;}
    vector<list<int> *> hashset;        

    
};
int main(){
    MyHashSet s;
    s.add(1);
    s.add(1001);
    s.add(2);
    s.pprint();
    cout<<"remove 2"<<endl;
    s.remove(2);
    s.pprint();
    cout<<s.contains(2);
}
