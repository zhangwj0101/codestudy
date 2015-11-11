public class Solution {
  
    public static int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        boolean[] a = new boolean[n];
        Arrays.fill(a, true);
        a[1] = false;
        int t = (int) Math.sqrt(n);
        for (int i = 1; i <= t; i += 2) {
            if (!a[i]) {
                continue;
            }
            for (int j = i; j * i < n; j += 2) {
                int k = j * i;
                if (!a[k]) {
                    continue;
                }
                a[j * i] = false;
            }
        }
        int count = 0;
        for (int i = 3; i < n; i += 2) {
            if (a[i]) {
                count++;
            }
        }
        
        return count + 1;
    }
    
}