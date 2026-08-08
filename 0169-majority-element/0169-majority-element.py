class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        hash = {}
        major_element = 0
        major_element_count = 0

        for n in nums:
            hash[n] = 1 + hash.get(n,0)
            if hash[n] > major_element_count:
                major_element = n
                major_element_count = hash[n]
        
        return major_element