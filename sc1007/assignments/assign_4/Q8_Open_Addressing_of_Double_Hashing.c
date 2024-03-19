#include <stdio.h>

#define TABLESIZE 37
#define PRIME 13

enum Marker { EMPTY, USED, DELETED };

typedef struct _slot {
  int key;
  enum Marker indicator;
} HashSlot;

typedef struct {
  int index;
  int nComparisions;
} FindResult;

int HashInsert(int key, HashSlot hashTable[]);
int HashDelete(int key, HashSlot hashTable[]);

int hash1(int key);
int hash2(int key);

int main() {
  int opt;
  int i;
  int key;
  int comparison;
  HashSlot hashTable[TABLESIZE];

  for (i = 0; i < TABLESIZE; i++) {
    hashTable[i].indicator = EMPTY;
    hashTable[i].key = 0;
  }

  printf("============= Hash Table ============\n");
  printf("|1. Insert a key to the hash table  |\n");
  printf("|2. Delete a key from the hash table|\n");
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
      comparison = HashInsert(key, hashTable);
      if (comparison < 0)
        printf("Duplicate key\n");
      else if (comparison < TABLESIZE)
        printf("Insert: %d Key Comparisons: %d\n", key, comparison);
      else
        printf("Key Comparisons: %d. Table is full.\n", comparison);
      break;
    case 2:
      printf("Enter a key to be deleted:\n");
      scanf("%d", &key);
      comparison = HashDelete(key, hashTable);
      if (comparison < 0)
        printf("%d does not exist.\n", key);
      else if (comparison <= TABLESIZE)
        printf("Delete: %d Key Comparisons: %d\n", key, comparison);
      else
        printf("Error\n");
      break;
    case 3:
      for (i = 0; i < TABLESIZE; i++)
        printf("%d: %d %c\n", i, hashTable[i].key,
               hashTable[i].indicator == DELETED ? '*' : ' ');
      break;
    }
    printf("Enter selection: ");
    scanf("%d", &opt);
  }
  return 0;
}

int hash1(int key) { return (key % TABLESIZE); }

int hash2(int key) { return (key % PRIME) + 1; }

/* Double hashing */
int hash(int key, int i) { return (hash1(key) + i * hash2(key)) % TABLESIZE; }

FindResult find(int key, HashSlot hashTable[]) {
  // walk hash table slot probing chain and find location
  int nComparisions = 0;
  for (int i = 0; i < TABLESIZE; i++) {
    int hashKey = hash(key, i);
    HashSlot *slot = &hashTable[hashKey];
    if (slot->indicator == USED) {
      nComparisions++;
      if (slot->key == key) {
        // found key
        return (FindResult){hashKey, nComparisions};
      }
    }
    if (slot->indicator == EMPTY) {
      // finished chain without locating key
      return (FindResult){-1, nComparisions};
    }
  }

  // exhasted hash table without locating key
  return (FindResult){-1, nComparisions};
}
int HashInsert(int key, HashSlot hashTable[]) {
  // Write your code here
  FindResult result = find(key, hashTable);
  if (result.index != -1) {
    // duplicate key
    return -1;
  }
  // probe for an unused slot to insert key
  for (int i = 0; i < TABLESIZE; i++) {
    HashSlot *slot = &hashTable[hash(key, i)];
    if (slot->indicator != USED) {
      // insert key into slot
      slot->key = key;
      slot->indicator = USED;
      return result.nComparisions;
    }
  }

  // hash table exhaustion
  return TABLESIZE;
}

int HashDelete(int key, HashSlot hashTable[]) {
  // Write your code here
  FindResult result = find(key, hashTable);
  if (result.index == -1) {
    // no such key
    return -1;
  }
  // mark key as deleted
  hashTable[result.index].indicator = DELETED;
  return result.nComparisions;
}
