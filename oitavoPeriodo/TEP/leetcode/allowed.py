class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed = set(allowed)
        res = 0
        for word in words:
            setWord = set(word)
            if(len(setWord.intersection(allowed)) == len(setWord)):
                res+=1
        return res