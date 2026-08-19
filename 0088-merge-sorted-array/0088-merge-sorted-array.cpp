class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int k = 0;
        int i = 0;
        int j = 0;

        vector<int> arr(n + m);

        while (i < m && j < n) {

            if (nums1[i] <= nums2[j]) {
                arr[k] = nums1[i];
                i++;
            }
            else {
                arr[k] = nums2[j];
                j++;
            }

            k++;
        }

        while (i < m) {
            arr[k] = nums1[i];
            k++;
            i++;
        }

        while (j < n) {
            arr[k] = nums2[j];
            k++;
            j++;
        }

        for (int x = 0; x < m + n; x++) {
            nums1[x] = arr[x];
        }
    }
};