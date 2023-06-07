void troca(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void bubble_sort(int v[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int trocou = 0;

        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
                trocou = 1;
            }
        }

        if (!trocou) {
            break;
        }
    }
}