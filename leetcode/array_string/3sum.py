class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        freq_map = dict()
        res = []
        # len < 3
        if (len(nums) < 3):
            return []
        for num in nums:
            if num in freq_map:
                freq_map[num] += 1
            else:
                freq_map[num] = 1
        # all same
        if (0 in freq_map and freq_map[0] > 2):
            res.append([0, 0, 0])
        # two same
        key_list = list(freq_map.keys())
        key_list.sort()
        index = 0
        for key in key_list:
            if freq_map[key] >= 2:
                zero_sum = -2*key
                if (zero_sum in freq_map and zero_sum != key):
                    res.append([key, key, zero_sum])
        # no same
        for num in key_list[:-2]:
            for nest_num in key_list[index+1:]:
                zero_sum = -1 * (num + nest_num)
                if (zero_sum in freq_map and zero_sum > nest_num):
                    res.append([num, nest_num, zero_sum])
            index += 1
        return res
