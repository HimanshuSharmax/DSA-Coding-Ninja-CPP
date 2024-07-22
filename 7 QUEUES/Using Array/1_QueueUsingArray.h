template <typename T>
class QueueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueUsingArray(int s){
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize(){
        cout<<"Queue size : ";
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }
    
    void enqueue(T element){                 // Insert element
        if(size == capacity){
            cout<<"Queue is full!"<<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }

    T dequeue(){                         // Delete element
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if(size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        cout<<"Dequeue element : ";
        return ans;
    }

    T front(){
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        cout<<"The Front is : ";
        return data[firstIndex];
    }
};

