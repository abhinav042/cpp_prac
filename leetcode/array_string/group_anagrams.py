class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        freq_anagram = dict()
        res_list = list()
        for index, word in enumerate(strs):
            if (word in freq_anagram):
                continue
            if (word == ""):
                res_list.append([word])
                freq_anagram[""] = 1
                continue
            freq_dict = dict()
            word_list = list()
            for letter in word:
                if letter in freq_dict:
                    freq_dict[letter] += 1
                else:
                    freq_dict[letter] = 1
            for nested_index, nested_word in enumerate(strs, start = index + 1):
                add_word = True
                copy_freq = dict(freq_dict)
                for letter in nested_word:
                    if letter not in copy_freq:
                        break
                    else:
                        copy_freq[letter] -= 1
                for letter in copy_freq:
                    if copy_freq[letter] != 0:
                        add_word = False
                        break
                if (add_word):
                    freq_anagram[nested_word] = 1
                    word_list.append(nested_word)
            res_list.append(word_list)
        return res_list
