#include <stdio.h>

#define TABLESIZE 37
#define PRIME 13

enum Marker { EMPTY, USED };

typedef struct _slot {
  int key;
  enum Marker indicator;
  int next;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashFind(int key, HashSlot hashTable[]);

int hash(int key) { return (key % TABLESIZE); }

int main() {
  int opt;
  int i;
  int key;
  int index;
  HashSlot hashTable[TABLESIZE];

  for (i = 0; i < TABLESIZE; i++) {
    hashTable[i].next = -1;
    hashTable[i].key = 0;
    hashTable[i].indicator = EMPTY;
  }

  printf("============= Hash Table ============\n");
  printf("|1. Insert a key to the hash table  |\n");
  printf("|2. Search a key in the hash table  |\n");
  printf("|3. Print the hash table            |\n");
  printf("|4. Quit                            |\n");
  printf("=====================================\n");

  printf("Enter selection: ");
  scanf("%d", &opt);
  while (opt >= 1 && opt <= 3) {
    switch (opt) {
    case 1:
      printf("Enter a key to be inserted:\n");
      scanf("%d", &key);
      index = HashInsert(key, hashTable);
      if (index < 0)
        printf("Duplicate key\n");
      else if (index < TABLESIZE)
        printf("Insert %d at index %d\n", key, index);
      else
        printf("Table is full.\n");
      break;
    case 2:
      printf("Enter a key for searching in the HashTable:\n");
      scanf("%d", &key);
      index = HashFind(key, hashTable);

      if (index != -1)
        printf("%d is found at index %d.\n", key, index);
      else
        printf("%d is not found.\n", key);
      break;

    case 3:
      printf("index:\t key \t next\n");
      for (i = 0; i < TABLESIZE; i++)
        printf("%d\t%d\t%d\n", i, hashTable[i].key, hashTable[i].next);
      break;
    }
    printf("Enter selection: ");
    scanf("%d", &opt);
  }
  return 0;
}

int HashInsert(int key, HashSlot hashTable[]) {
  if (HashFind(key, hashTable) != -1) {
    // duplicate insertion
    return -1;
  }

  // first slot is empty, just insert
  int hashKey = hash(key);
  HashSlot *slot = &hashTable[hashKey];
  if (slot->indicator == EMPTY) {
    slot->key = key;
    slot->indicator = USED;
    return hashKey;
  }

  // look for last node of the hash chain
  int previous = -1;
  do {
    previous = hashKey;
    hashKey = hashTable[hashKey].next;
  } while (hashKey != -1);

  // linear probe for an empty slot to insert key
  for (int i = 1; i < TABLESIZE; i++) {
    // probe next slot
    hashKey = (previous + i) % TABLESIZE;
    HashSlot *slot = &hashTable[hashKey];

    if (slot->indicator == EMPTY) {
      slot->key = key;
      slot->indicator = USED;
      // link with previous node
      hashTable[previous].next = hashKey;
      return hashKey;
    }
  }

  // hash table exhasted
  return TABLESIZE + 1;
}

int HashFind(int key, HashSlot hashTable[]) {
  // Write your code here
  int hashKey = hash(key);
  // follow chain to locate key
  do {
    HashSlot *slot = &hashTable[hashKey];
    if (slot->indicator == USED && slot->key == key) {
      // found slot storing key
      return hashKey;
    }
    hashKey = slot->next;
  } while (hashKey != -1);

  // no such slot storing key
  return -1;
}
