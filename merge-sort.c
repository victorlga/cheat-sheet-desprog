void combina(int v[], int temp[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k;

    for (k = l; k <= r; k++) {
        if (i > m) {
            temp[k] = v[j];
            j++;
        } else if (j > r) {
            temp[k] = v[i];
            i++;
        } else if (v[i] > v[j]) {
            temp[k] = v[j];
            j++;
        } else {
            temp[k] = v[i];
            i++;
        }
    }

    for (k = l; k <= r; k++) {
        v[k] = temp[k];
    }
}

void merge_sort_r(int v[], int temp[], int l, int r) {
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    merge_sort_r(v, temp, l, m);
    merge_sort_r(v, temp, m + 1, r);
    combina(v, temp, l, m, r);
}

void merge_sort(int v[], int n) {
    int temp[n];
    merge_sort_r(v, temp, 0, n - 1);
}