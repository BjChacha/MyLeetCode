
var MyHashSet = function() {
    this.n = 1000;
    this.table = Array(1000).fill(0).map(()=>Array());
};

/** 
 * @param {number} key
 * @return {void}
 */
MyHashSet.prototype.add = function(key) {
    if (!this.contains(key)) this.table[key%this.n].push(key)
};

/** 
 * @param {number} key
 * @return {void}
 */
MyHashSet.prototype.remove = function(key) {
    let arr = this.table[key%this.n];
    for (let i = 0; i < arr.length; ++i) {
        if (arr[i] === key) {
            arr.splice(i, 1);
        }
    }
};

/** 
 * @param {number} key
 * @return {boolean}
 */
MyHashSet.prototype.contains = function(key) {
    let arr = this.table[key%this.n];
    for (let i = 0; i < arr.length; ++i) {
        if (arr[i] === key) {
            return true;
        }
    }
    return false;
};

/** 
 * Your MyHashSet object will be instantiated and called as such:
 * var obj = new MyHashSet()
 * obj.add(key)
 * obj.remove(key)
 * var param_3 = obj.contains(key)
 */