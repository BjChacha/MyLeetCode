
var PeekingIterator = function(iterator) {
    this.arr = [];
    this.p = -1;
    this.iter = iterator;
};


PeekingIterator.prototype.peek = function() {
    if (this.p + 1 >= this.arr.length) this.arr.push(this.iter.next());
    return this.arr[this.p+1];
};


PeekingIterator.prototype.next = function() {
    if (this.hasNext()) {
        if (this.arr.length - 1 === this.p) this.arr.push(this.iter.next());
        return this.arr[++this.p];
    } else {
        return -1;
    }
};


PeekingIterator.prototype.hasNext = function() {
    return this.iter.hasNext() || this.p < this.arr.length - 1;
};
