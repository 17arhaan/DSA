class Solution {
public:
    int getScore(vector<int>& rolls) {
        int score = 0;
        int n = rolls.size();
        for (int i = 0; i < n; ++i) {
            if ((i > 0 && rolls[i - 1] == 10) || (i > 1 && rolls[i - 2] == 10)) {
                score += 2 * rolls[i];
            } else {
                score += rolls[i];
            }
        }
        return score;
    }

    int isWinner(vector<int>& player1, vector<int>& player2) {
        int sum1 = getScore(player1);
        int sum2 = getScore(player2);

        if (sum1 > sum2) return 1;
        if (sum2 > sum1) return 2;
        return 0;
    }
};
