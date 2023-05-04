#include <iostream>
#include <vector>

using namespace std;

int findPeakIndex(vector<int> nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    vector<int> arr;
    int n, num;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the elements of array:\n";
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }
    int peak_index = findPeakIndex(arr);
    cout << "Peak element index: " << peak_index << endl;
    return 0;
}
