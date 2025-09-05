#include <iostream>
using namespace std;

int delete_element(int arr[], int n, int key) {
    int pos = -1;
    // Find the position of the key
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        // Key not found
        return n;
    }
    // Shift elements to the left
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // Return new length
    return n - 1;
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9};
    int n = 6;
    int key = 1;
    n = delete_element(arr, n, key);
    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}