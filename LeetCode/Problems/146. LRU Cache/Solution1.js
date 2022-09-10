var Node = function(_key, _value) {
    this.key = _key ?? 0;
    this.value = _value ?? 0;
    this.prev = null;
    this.next = null;
};

var LRUCache = function(capacity) {
    this.n = capacity;
    this.head = new Node(-1, -1)
    this.tail = new Node(-1, -1);
    this.head.next = this.tail;
    this.tail.prev = this.head;
    this.map = new Map();
};


LRUCache.prototype.get = function(key) {
    if (this.map.has(key)) {
        this.refresh(key);
        return this.map.get(key).value;
    }
    return -1;
};


LRUCache.prototype.put = function(key, value) {
    if (this.map.has(key)) {
        this.map.get(key).value = value;
        this.refresh(key);
    } else {
        const node = new Node(key, value);
        this.map.set(key, node);
        node.prev = this.head;
        node.next = this.head.next;
        this.head.next.prev = node;
        this.head.next = node;
        if (this.map.size > this.n) {
            const toDelete = this.tail.prev;
            this.tail.prev = toDelete.prev;
            toDelete.prev.next = this.tail;
            toDelete.next = toDelete.prev = null;
            this.map.delete(toDelete.key);
            delete(toDelete);
        }
    }
};


LRUCache.prototype.refresh = function(key) {
    const tmp = this.map.get(key);
    tmp.prev.next = tmp.next;
    tmp.next.prev = tmp.prev;
    tmp.prev = this.head;
    tmp.next = this.head.next;
    this.head.next.prev = tmp;
    this.head.next = tmp;
}
