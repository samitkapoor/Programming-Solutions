class Solution {
    public boolean isPalindrome(int x) {
        if (x == 0)
            return true;
        else if (x < 0 || x % 10 == 0)
            return false;

        int reversedX = 0;
        int t = x;

        while (t != 0) {
            reversedX = (reversedX * 10) + (t % 10);
            t /= 10;
        }

        if (reversedX == x)
            return true;

        return false;
    }
}