#include <iostream>
using namespace std;

class quick {
public:
    void printarray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << "|";
        }
        cout << endl;
    }

    void quicksort(int arr[], int low, int high) {
        if (low < high) {
            int p = partition(arr, low, high);
            quicksort(arr, low, p - 1);
            quicksort(arr, p + 1, high);
        }
    }

private:
    int partition(int arr[], int low, int high) {
        int pivot = arr[high];  
        int i = low - 1;        

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {  
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);  
        return i + 1;                 
    }
};

int main() {
    quick q;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << "Original array: ";
    q.printarray(A, n);
    q.quicksort(A, 0, n - 1);
    cout << "Sorted array: ";
    q.printarray(A, n);
    return 0;
}