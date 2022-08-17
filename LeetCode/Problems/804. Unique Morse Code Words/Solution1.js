// hash table
var uniqueMorseRepresentations = function(words) {
    const mapper = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
    const set = new Set();
    let tmp
    for (let w of words) {
        tmp = '';
        for (let c of w) {
            tmp += mapper[c.codePointAt()-'a'.codePointAt()];
        }
        set.add(tmp);
    }
    return set.size;
};
