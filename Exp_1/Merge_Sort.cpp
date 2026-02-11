#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) L[i] = nums[left + i];
    for(int j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(vector<int>& nums, int left, int right) {
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortHelper(nums, left, mid);
    mergeSortHelper(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSortHelper(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}