class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        running_letter_freq = dict()
        running_letter_seq = list()
        seq_count = dict()
        count = 0
        if len(s) == 0:
            return 0
        if len(s) == 1:
            return 1
        for letter in s: 
            if letter in running_letter_freq:
                key_str = "".join(running_letter_seq)
                seq_count[key_str] = count
                count = 0
                running_letter_freq.clear()
                running_letter_seq.clear()
            count += 1
            running_letter_freq[letter] = 1
            running_letter_seq.append(letter)
        max_count = 0
        if (len(seq_count) == 0):
            return 0
        elif (len(seq_count) == 1):
            return 1
        for seq in seq_count:
            if seq_count[seq] > max_count:
                print('the seq is : ' + seq)
                print('the seq_count is : ' + str(seq_count[seq])) 
                max_count = seq_count[seq]
        return max_count
