class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* oldest;
    Node* latest;

    void insert(Node* node) {
        Node* latest_prev = latest->prev;

        latest_prev->next = node;
        node->prev = latest_prev;

        latest->prev = node;
        node->next = latest;
    }

    void remove(Node* node) {
        Node* node_prev = node->prev;
        Node* node_next = node->next;

        node_prev->next = node_next;
        node_next->prev = node_prev;

        node->prev = nullptr;
        node->next = nullptr;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        oldest = new Node(0, 0);
        latest = new Node(0, 0);

        oldest->next = latest;
        latest->prev = oldest; 
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];
        remove(node);
        insert(node);

        return node->val; 
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            cache.erase(key);
        }

        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        if(cache.size() > capacity) {
            Node* lru = oldest->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */