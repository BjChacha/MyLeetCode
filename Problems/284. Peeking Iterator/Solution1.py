class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self._arr = []
        self._p = -1
        self._iter = iterator

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if self._p + 1 >= len(self._arr):
            self._arr.append(self._iter.next())
        return self._arr[self._p+1]

    def next(self):
        """
        :rtype: int
        """
        if self.hasNext():
            if len(self._arr) - 1 == self._p:
                self._arr.append(self._iter.next())
            self._p += 1
            return self._arr[self._p]
        else:
            return -1
            

    def hasNext(self):
        """
        :rtype: bool
        """
        # print(self._iter.hasNext(), self._p , len(self._arr))
        return self._iter.hasNext() or self._p < len(self._arr) - 1