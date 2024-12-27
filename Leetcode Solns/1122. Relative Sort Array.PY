class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        count = {}
        result = []
        
        for num in arr1:
            count[num] = count.get(num, 0) + 1
        
        for num in arr2:
            result.extend([num] * count.pop(num, 0))
        
        remaining = []
        for num, freq in count.items():
            remaining.extend([num] * freq)
        
        return result + sorted(remaining)
