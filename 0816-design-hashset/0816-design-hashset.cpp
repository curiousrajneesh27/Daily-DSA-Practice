class MyHashSet {

private:
    static const int SIZE = 1009;


    vector<list<int>> buckets;

    int hash(int key) {
        return key % SIZE;
    }
    
public:
    MyHashSet() {
        buckets.resize(SIZE);
    }
    
    void add(int key) {
        int index = hash(key);
        for (int val : buckets[index]) {
            if (val == key) return;
        }
        buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = hash(key);
        buckets[index].remove(key);
    }
    
    bool contains(int key) {
        int index = hash(key);
        for (int val : buckets[index]) {
            if (val == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */