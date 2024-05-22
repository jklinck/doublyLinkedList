struct ll{
    int data;
    struct ll* prev;
    struct ll* next;
};

void add(struct ll** head, int nodeData);

void print(struct ll* head);

void clear(struct ll** head);
