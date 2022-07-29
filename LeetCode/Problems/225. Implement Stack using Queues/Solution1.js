var MyStack = function() {
    this.q = [[], []];
    this.flag = 0;
};

MyStack.prototype.push = function(x) {
    this.q[this.flag].push(x);
};

MyStack.prototype.pop = function() {
    while (this.q[this.flag].length > 1) this.q[1-this.flag].push(this.q[this.flag].shift());
    this.flag = 1 - this.flag;
    return this.q[1-this.flag].shift();
};

MyStack.prototype.top = function() {
    while (this.q[this.flag].length > 1) this.q[1-this.flag].push(this.q[this.flag].shift());
    this.flag = 1 - this.flag;
    let res = this.q[1-this.flag][0];
    this.q[this.flag].push(this.q[1-this.flag].shift());
    return res;
};

MyStack.prototype.empty = function() {
    return this.q[this.flag].length === 0;
};