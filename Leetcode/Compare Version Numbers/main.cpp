class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        int i1 = 0;
        int i2 = 0;

        while(i1 < n1 && i2 < n2) {
            while(i1 < n1 && version1[i1] == '0') i1++;
            while(i2 < n2 && version2[i2] == '0') i2++;

            int num1 = 0;
            int num2 = 0;
            while(i1 < n1 && version1[i1] != '.') {
                int x = version1[i1] - '0';
                num1 = (num1 * 10) + x;
                i1++;
            }
            while(i2 < n2 && version2[i2] != '.') {
                int x = version2[i2] - '0';
                num2 = (num2 * 10) + x;
                i2++;
            }

            if(num2 > num1) return -1;
            else if(num1 > num2) return 1;

            i1++, i2++;
        }

        while(i1 < n1) {
            if(version1[i1] != '0' && version1[i1] != '.') {
                return 1;
            }
            i1++;
        }
        while(i2 < n2) {
            if(version2[i2] != '0' && version2[i2] != '.') {
                return -1;
            }
            i2++;
        }

        return 0;
    }
};
