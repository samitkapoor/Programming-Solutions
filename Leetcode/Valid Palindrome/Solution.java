class Solution {
    public boolean isPalindrome(String s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {

            if (!((s.charAt(l) >= 'A' && s.charAt(l) <= 'Z') || (s.charAt(l) >= 'a' && s.charAt(l) <= 'z')
                    || (s.charAt(l) >= '0' && s.charAt(l) <= '9'))) {
                l++;
                continue;
            } else if (!((s.charAt(r) >= 'A' && s.charAt(r) <= 'Z') || (s.charAt(r) >= 'a' && s.charAt(r) <= 'z')
                    || (s.charAt(r) >= '0' && s.charAt(r) <= '9'))) {
                r--;
                continue;
            }
            if (Character.toLowerCase(s.charAt(l)) != Character.toLowerCase(s.charAt(r))) {
                return false;
            } else {
                l++;
                r--;
            }

        }

        return true;

    }
}