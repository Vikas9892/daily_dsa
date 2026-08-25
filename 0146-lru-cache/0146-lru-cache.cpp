class LRUCache {
private:

    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    // Remove a node from the linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node right after head
    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // This node was recently used,
        // so move it to the front.
        removeNode(node);
        insertFront(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            // Update value
            node->value = value;

            // Move to front because it is recently used
            removeNode(node);
            insertFront(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);

        mp[key] = node;
        insertFront(node);

        // Capacity exceeded
        if (mp.size() > capacity) {

            // Least recently used node
            Node* lru = tail->prev;

            removeNode(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};