
struct customArr
{
    int size;
    int capacity;
    int *ptr;
};

// Create an Array
void createArray(struct customArr *a, int capacity, int size)
{
    (*a).capacity = capacity;
    (*a).size = size;
    (*a).ptr = (int *) malloc(capacity * sizeof(int));
}