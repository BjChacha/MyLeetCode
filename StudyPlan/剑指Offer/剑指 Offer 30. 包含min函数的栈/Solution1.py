class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s1 = []
        self.s2 = []

    def push(self, x: int) -> None:
        self.s1.append(x)
        if not self.s2 or self.s2[-1] >= x:
            self.s2.append(x)

    def pop(self) -> None:
        if self.s2[-1] == self.s1[-1]:
            self.s2.pop()
        return self.s1.pop()

    def top(self) -> int:
        return self.s1[-1] if self.s1 else 0

    def min(self) -> int:
        return self.s2[-1] if self.s2 else 0