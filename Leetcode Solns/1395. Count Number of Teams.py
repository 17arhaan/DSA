class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        increasing, decreasing = 0, 0
        
        for i in range(n):
            left_smaller = sum(1 for j in range(i) if rating[j] < rating[i])
            left_larger = sum(1 for j in range(i) if rating[j] > rating[i])
            right_smaller = sum(1 for j in range(i + 1, n) if rating[j] < rating[i])
            right_larger = sum(1 for j in range(i + 1, n) if rating[j] > rating[i])
            
            increasing += left_smaller * right_larger
            decreasing += left_larger * right_smaller
        
        return increasing + decreasing
