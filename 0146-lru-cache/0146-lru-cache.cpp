class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* oldest;
    Node* latest;

    void insert(Node* node) {
        Node* latest_prev = this->latest->prev;
        Node* latest = this->latest;

        latest_prev->next = node;
        latest->prev = node;

        node->prev = latest_prev;
        node->next = latest;
    }

    void remove(Node* node) {
        Node* node_prev = node->prev;
        Node* node_next = node->next;

        node_prev->next = node_next;
        node_next->prev = node_prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        oldest = new Node(0, 0);
        latest = new Node(0, 0);

        oldest->next = latest;
        latest->prev = oldest;
    }

    ~LRUCache() {
        Node* curr = oldest;
        
        while(curr != nullptr) {
            Node* next = curr->next;
            cache.erase(curr->key);
            delete curr;
            curr = next;
        }
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
        }
        
        Node* node = new Node(key, value);
        insert(node);
        cache[key] = node;

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