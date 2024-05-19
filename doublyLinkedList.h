struct ll{
    int data;
    struct ll* prev;
    struct ll* next;
};

extern struct ll* list;

void add(int nodeData);
void print();
