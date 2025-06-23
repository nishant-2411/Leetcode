class Solution(object):
    def createPalindrome(self, num, odd):
        pal = num
        if odd:
            num = num // 10
        while num > 0:
            pal = pal * 10 + num % 10
            num = num // 10
        return pal

    def isPalindrome(self, num, base):
        if num == 0:
            return True
        original = num
        reversed_num = 0
        while num > 0:
            reversed_num = reversed_num * base + num % base
            num = num // base
        return original == reversed_num

    def kMirror(self, k, n):
        total = 0
        length = 1
        while n > 0:
            # Generate odd-length palindromes
            for i in range(length, 10 * length):
                if n <= 0:
                    break
                pal = self.createPalindrome(i, True)
                if self.isPalindrome(pal, k):
                    total += pal
                    n -= 1
            # Generate even-length palindromes
            for i in range(length, 10 * length):
                if n <= 0:
                    break
                pal = self.createPalindrome(i, False)
                if self.isPalindrome(pal, k):
                    total += pal
                    n -= 1
            length *= 10
        return total