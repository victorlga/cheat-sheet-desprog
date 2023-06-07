int particiona(int v[], int l, int r) {
    int p = l;

    for (int i = l; i < r; i++) {
        if (v[i] < v[r]) {
            if (p != i) {
                troca(v, p, i);
            }
            p++;
        }
    }

    if (p != r) {
        troca(v, p, r);
    }

    return p;
}

void quick_sort_r(int v[], int l, int r) {
    if (l >= r) {
        return;
    }
    int p = particiona(v, l, r);
    quick_sort_r(v, l, p - 1);
    quick_sort_r(v, p + 1, r);
}

void quick_sort(int v[], int n) {
    quick_sort_r(v, 0, n - 1);
}