void troca(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void selection_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;

        for (int j = i + 1; j < n; j++) {
            if (v[m] > v[j]) {
                m = j;
            }
        }

        if (m != i) {
            troca(v, m, i);
        }
    }
}