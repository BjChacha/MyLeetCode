// simulate
var validateStackSequences = function(pushed, popped) {
    const stack = [];
    for (let e of pushed) {
        stack.push(e);
        while (stack.length > 0 && stack[stack.length-1] === popped[0]) {
            stack.pop();
            popped.shift();
        }
        console.log(stack);
    }
    return stack.length === 0;
};