import java.util.*;

class Solution {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();

        while (t > 0) {
            int n = scan.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = scan.nextInt();
            }

            boolean flag = true;

            for (int i = 0; i < n - 1; i++) {
                if (arr[i] < arr[i + 1])
                    flag = false;
            }

            if (flag)
                System.out.println("NO");
            else
                System.out.println("YES");
            t--;
        }
    }
}