#include<iostream>
#include<unordered_map>
using namespace std;
template<typename t>
class mapnode{
    public:
    string key;
    t value;
    mapnode* next;
    mapnode(string key,t data){
        this->key=key;
        value=data;
        next=NULL;
    }
    ~mapnode(){
        delete next;
    }
};

template<typename t>
class ourmap{
    mapnode<t>** buckets;
    int count;
    int numbuckets;
    public:
    ourmap(){
        count=0;
        numbuckets=5;
        buckets=new mapnode<t>*[numbuckets];
        for(int i=0;i<numbuckets;i++){
            buckets[i]=NULL;
        }
    }
    ~ourmap(){
        for(int i=0;i<numbuckets;i++){
            delete buckets[i];
        }
        delete [] buckets;
    }
    int size(){
        return count;
    }
    t getvalueofkey(string key){
        int bindex=getbucketindex(key);
        mapnode<t>* head=buckets[bindex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }
    private:
    int getbucketindex(string key){
        int hashcode=0;
        int coeff=1;
        for(int i=key.size()-1;i>=0;i--){
            hashcode+=key[i]*coeff;
            hashcode=hashcode%numbuckets;
            coeff*=37;
            coeff%=numbuckets;
        }
        return hashcode%numbuckets;
    }
    void rehash(){
        mapnode<t>** temp=buckets;
        buckets=new mapnode<t>*[2*numbuckets];
        for(int i=0;i<numbuckets*2;i++){
            buckets[i]=NULL;
        }
        int oldbucketcount=numbuckets;
        numbuckets*=2;
        count=0;
        for(int i=0;i<oldbucketcount;i++){
            mapnode<t>* head=temp[i];
            while (head!=NULL){
                t val=head->value;
                string key=head->key;
                insert(key,val);
                head=head->next;
            }
            for(int i=0;i,oldbucketcount;i++){
                mapnode<t>* head=temp[i];
                delete head;
            }
            delete []temp;
        }
    }
    public:
    void insert(string key,t value){
        int bindex=getbucketindex(key);
        mapnode<t>* head=buckets[bindex];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        head=buckets[bindex];
        mapnode<t>* node=new mapnode<t>(key,value);
        node->next=head;
        buckets[bindex]=node;
        count++;
        double loadfactor=(1.0*count)/numbuckets;
        if(loadfactor>0.7){
            rehash();
        }
    }
    t remove(key){
        int bindex=getbucketindex(key);
        mapnode<t>* head=buckets[bindex];
        mapnode<t>* prev=NULL;
        t val=0;
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    buckets[bindex]=head->next;
                }
                else{
                prev->next=head->next;
                }
                val=head->value;
                head->next=NULL;
                delete head;
                count--;
                return val;
            }
            prev=head;
            head=head->next;
        }
        return val;
    }
};

int main(){
    return 0;
}