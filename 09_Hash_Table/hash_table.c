#include <stdio.h>

int hash (int key, int table_size) {
    // Modulo-Remainder Method
    int hash = (key % table_size);
    return hash;
}

int insert (int arr[10], int key) {
    int index = hash(key, 10);
    arr[index] = key;
    return key;
}

int search (int hash_table[10], int key) {
    int n = 10;
    int index_of_key = hash(key, n);
    if (hash_table[index_of_key] == key) 
        return index_of_key;
    return -1;
}

void main () {
    int hash_table[10]= {0};

    insert(hash_table, 10);
    insert(hash_table, 11);
    insert(hash_table, 22);
    insert(hash_table, 33);
    insert(hash_table, 44);
    insert(hash_table, 88);

    printf("Hash Table !! \n");
    for (int j = 0; j < 10; j++)
    {
        printf("%d \n", hash_table[j]);
    }

    printf("Searched %d at %d \n", 10, search(hash_table, 10));
    printf("Searched %d at %d \n", 22, search(hash_table, 22));
    printf("Searched %d at %d \n", 88, search(hash_table, 88));
    printf("Searched %d at %d \n", 99, search(hash_table, 99));
    
}