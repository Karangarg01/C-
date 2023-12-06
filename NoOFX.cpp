class Solution {
  public:
    int countX(int L, int R, int X) {
    int count = 0;

    for (int i = L + 1; i < R; i++) {
        int currentNumber = i;  
        while (currentNumber > 0) {
            int dig = currentNumber % 10;
            currentNumber /= 10;
            if (dig == X) count++;
        }
    }

    return count;
}
};
