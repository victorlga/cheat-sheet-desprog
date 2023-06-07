// Se for vetor, fila, PUT com index
void queue_int_genput(queue_int *q, int value, int index) {
    int i = q->end;
    while (i != (q->end - index) % q->capacity) {
        int prev = (i - 1) % q->capacity;
        q->data[i] = q->data[prev];
        i = prev;
    }
    q->data[i] = value;
    q->end = (q->end + 1) % q->capacity;
    q->size++;
}
//////////////////////////////////////////////////////////////////////////
// Se for vetor, fila, GET com index

int queue_int_genget(queue_int *q, int value, int index) {
    int i = (q->begin + index) % q->capacity;
    int value = q->data[i];
    int temp;
    while (i != q->begin) {
        temp = i;
        i = (i-1) % q->capacity;
        q->data[temp] = q->data[i];
    }
    q->size--;
    return value;
}

///////////////////////////////////////////////////////////////////////////
// Se for vetor, pilha, POP com index
int stack_int_pop(stack_int *s, int index) {
    int value = s->data[index];
    s->size--;
    for (int i = index; i < s->size; i++) {
        s->data[i] = s->data[i + 1];
    }
    return value;
}
/////////////////////////////////////////////////////////////////////////////
// Se for vetor, pilha, PUSH com index
void stack_int_push(stack_int *s, int value, int index) {
    int i;
    for (i = s->size; i > s->size - index; i--) {
        s->data[i] = s->data[i - 1];
    }
    s->data[i] = value;
    s->size++;
}
///////////////////////////////////////////////////////////////////////////
// Se for lista ligada, fila, PUT com index
void queue_int_genput(queue_int *q, int value, int index) {
    node *p;
    node *n;

    // Encontra o tamanho total
    int size = 0;
    for (n = q->first; n != NULL; n = n->next) {
        size++;
    }
    // Encontra os nós que devemos colocar antes e depois
    p = NULL;
    n = q->first;
    for (int i = 0; i < size - index; i++) {
        p = n;
        n = n->next;
    }
    // Aloca um nó, define o valor dele
    // Se não for o primeiro
    // Se for o primeiro
    // Isso aqui em baixo vai ser igual independente da referencia do index
    n = malloc(sizeof(node));
    n->value = value;
    if (p != NULL) {
        n->next = p->next;
        p->next = n;
    } else {
        n->next = q->first;
        q->first = n;
    }

    if (index == 0) {
      q->last = n;
    }
}

// Se for lista ligada, fila, GET com index
int queue_int_genget(queue_int *q, int index) {
    // size - index - 1
    // Dentro do for (i = 0; i < size - index - 1; i++)
    // Dentro do for so atualiza o valor de p e n, mais nada
}
/////////////////////////////////////////////////////////////////////////
// Se for lista ligada, pilha, POP com index
int stack_int_genpop(stack_int *s, int index) {
    node *n;
    int size = 0;
    for (n = s->top; n != NULL; n = n->next) {
        size++;
    }

    node *p = NULL;
    node *n = s->top;
    for (int i = 0; i < size - index - 1; i++) {
        p = n;
        n = n->next;
    }

    if (p != NULL) {
        p->next = n->next;
    } else {
        s->top = n->next;
    }
    int value = n->value;
    free(n);
    return value;
}
///////////////////////////////////////////////////////////////////////////////////
// Se for lista ligada, pilha, PUSH com index
void stack_int_push(stack_int *s, int value, int index) {
    node *p = NULL;
    node *n = s->top;
    for (int i = 0; i < index; i++) {
        p = n;
        n = n->next;
    }

    n = malloc(sizeof(node));
    n->value = value;
    if (p != NULL) {
        n->next = p->next;
        p->next = n;
    } else {
        n->next = s->top;
        s->top = n;
    }
}

int queue_int_maxget(queue_int *q) {
    int max = q->data[q->begin];
    int index;

    for (int i = 1; i < q->size; i++) {
        int temp = q->data[((q->begin + i) % q->capacity)];
        if (max < temp) {
            index = (q->begin + i) % q->capacity;
        }
    }

    int value = q->data[index];

    while (index != q->begin) {
        int temp = index;
        index = (index-1) % q->capacity;
        q->data[temp] = q->data[index];
    }
    q->size--;
    q->begin = (q->begin + 1) % q->capacity;
    return value;
}

int queue_int_maxget(queue_int *q) {
    node * max = q->first;
    node * n = q->first;

    while (n != NULL) {
        if (max->value < n->value) {
            max = n;
        }
        n = n->next;
    }
    int value = max->value;

    node * p = NULL;
    n = q->first;
    while (n != max) {
        p = n;
        n = n->next;
    }

    if (p != NULL) {
        p->next = max->next;
    } else {
        q->first = max->next;
    }
    free(max);
    return value;
}