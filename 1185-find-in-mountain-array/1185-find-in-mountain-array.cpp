class Solution {
public:
    int binarysearch1(int left, int right, MountainArray &mountainArr, int& target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = mountainArr.get(mid);
            if (value == target) return mid;
            else if (value > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }

    int binarysearch2(int left, int right, MountainArray &mountainArr, int& target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = mountainArr.get(mid);
            if (value == target) return mid;
            else if (value > target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0;
        int right = n - 1;
        int peakindex = -1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) left = mid + 1;
            else right = mid;
        }
        peakindex = left;

        int temp = binarysearch1(0, peakindex, mountainArr, target);
        if (temp != -1) return temp;
        temp = binarysearch2(peakindex + 1, n - 1, mountainArr, target);
        if (temp != -1) return temp;
        return -1;
    }
};
