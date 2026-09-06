#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>
#include <iomanip>
using namespace std;


void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

vector<int> readDataset(const string& filename) {
    ifstream file(filename);
    vector<int> data;
    int num;
    if (file.is_open()) {
        while (file >> num) {
            data.push_back(num);
        }
        file.close();
    } else {
        cout << "Error: Could not open " << filename << endl;
    }
    return data;
}

int main() {
    vector<string> filenames = {"dataset.txt"};

    cout << left << setw(20) << "Dataset" 
         << setw(15) << "Size" 
         << setw(20) << "Bubble Sort (s)" 
         << setw(20) << "Merge Sort (s)" << endl;

    for (const string& filename : filenames) {
        vector<int> originalData = readDataset(filename);
        if (originalData.empty()) continue;

        int size = originalData.size();

        vector<int> bubbleData = originalData;
        auto start = chrono::high_resolution_clock::now();
        bubbleSort(bubbleData);
        auto stop = chrono::high_resolution_clock::now();
        double bubbleTime = chrono::duration<double>(stop - start).count();

        vector<int> mergeData = originalData;
        start = chrono::high_resolution_clock::now();
        mergeSort(mergeData, 0, mergeData.size() - 1);
        stop = chrono::high_resolution_clock::now();
        double mergeTime = chrono::duration<double>(stop - start).count();

        cout << left << setw(20) << filename 
             << setw(15) << size 
             << setw(20) << fixed << setprecision(6) << bubbleTime 
             << setw(20) << fixed << setprecision(6) << mergeTime << endl;
    }

    return 0;
}
