// simulation
var isPrefixOfWord = function(sentence, searchWord) {
    const words = sentence.split(' ');
    for (const [i, w] of words.entries()) {
        if (w.startsWith(searchWord)) return i + 1;
    }
    return -1;
};
