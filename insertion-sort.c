void insertion_sort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = v[i];

        int j = i;
        while (j > 0 && v[j - 1] > temp) {
            v[j] = v[j - 1];
            j--;
        }

        v[j] = temp;
    }
}