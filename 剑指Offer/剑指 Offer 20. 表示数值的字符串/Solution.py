class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        isSign = False
        isDot = False
        isExp = False
        isNum = False
        for i in range(len(s)):
            if s[i] in ['+', '-']:
                if not isSign:
                    isSign = True
                else:
                    return False
            elif s[i] == '.':
                if not isDot:
                    isDot = True
                    isSign = True
                else:
                    return False
            elif s[i].lower() == 'e':
                if isNum and not isExp:
                    isExp = True
                    isSign = False
                    isDot = True
                    isNum = False
                else:
                    return False
            elif s[i].isdecimal():
                isSign = True
                isNum = True
            else:
                return False
        return isNum
