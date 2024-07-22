#include<string>
using namespace std;

template<typename V>
class MapNode{                  // For linledlist inside array
    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key,V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode(){
        delete next;
    }
};

template<typename V>        // Key(string), value(template)
class ourmap{
    MapNode<V>** buckets;
    int count;
    int numbuckets;

    public:
    ourmap(){
        count = 0;
        numbuckets = 5;
        buckets = new MapNode<V>*[numbuckets];
        for(int i=0; i<numbuckets; i++){        // For garbage value(NULL)
            buckets[i] = NULL;
        }
    }

    ~ourmap(){
        for(int i=0; i<numbuckets; i++){        // deleting LL firt
            delete buckets[i];
        }
        delete [] buckets;
    }

    // Functions

    int size(){
        return count;
    }

    private:
    int getBucketIndex(string key){        //Hash Functions(Two parts)-> hash code,compressor
        int hashCode = 0;                   //HashCode= string key->base p ,"abc" = a*p^2 + b*p^1 + c*p^0   ,(p^0 = 1)

        int currentCoeff = 1;
        for(int i = key.length() -1 ; i>=0 ;i--){
            hashCode = hashCode + key[i] * currentCoeff;
            hashCode = hashCode % numbuckets;       //For compressor(keeping small)
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numbuckets;
        }

        return hashCode % numbuckets;       // Compressor
    }

    void rehash(){
        MapNode<V>** temp = buckets;                    // Storing buckect(arr) to temp
        buckets = new MapNode<V>* [2 * numbuckets];
        for(int i=0 ; i<2*numbuckets ; i++){
            buckets[i] = NULL;
        }
        int oldBuckectCount = numbuckets;
        numbuckets *= 2;
        count = 0;

        for(int i=0 ; i<oldBuckectCount ; i++){
            MapNode<V>* head = temp[i];
            while(head != NULL){
                string key = head->key;
                V value = head->value;
                insert(key,value);
                head = head->next;
            }
        }

        for(int i=0 ; i<oldBuckectCount ; i++){         // delete prev LL
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;                                // delete prev buckect(arr)
    }

    public: 
    double getLoadFactor(){
        return (1.0 * count) / numbuckets;
    }

    void insert(string key,V value){
        int bucketIndex = getBucketIndex(key);

        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* newNode = new MapNode<V>(key,value);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count++;

        double loadFactor = (1.0 * count) / numbuckets;
        if(loadFactor > 0.7){
            rehash();
        }
    }

    V remove(string key){                               //This Function delete that value and return value
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                }else{
                    prev->next = head->next;
                }
                V value = head->value;          // Before deleting store the value
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }      
        return 0;
    }

    V getValue(string key){
       int bucketIndex = getBucketIndex(key);

        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }  
        return 0;
    }

};