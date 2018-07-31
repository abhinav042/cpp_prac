class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        j = 0
        str_len = len(s)
        running_freq = dict()
        ans = 0
        while (i < str_len and j < str_len):
            if (s[j] not in running_freq):
                running_freq[s[j]] = 1
                j += 1
                if (j - i) > ans:
                    ans = (j - i)
            else:
                running_freq.pop(s[i])
                i += 1
        return ans
        