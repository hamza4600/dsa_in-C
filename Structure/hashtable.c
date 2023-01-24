// Creating hash table form scratch in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct entry_s
{
    char *key;
    char *value;
    struct entry_s *next;
} entry_t;

typedef struct
{
    int size;
    entry_t **entries;
} ht_t;

// Create a new hashtable.

ht_t *ht_create(int size)
{

    ht_t *hashtable = NULL;
    int i;

    if (size < 1)
        return NULL;

    // Allocate the table itself.
    if ((hashtable = malloc(sizeof(ht_t))) == NULL)
    {
        return NULL;
    }

    // Allocate pointers to the head nodes.
    if ((hashtable->entries = malloc(sizeof(entry_t *) * size)) == NULL)
    {
        return NULL;
    }
    for (i = 0; i < size; i++)
    {
        hashtable->entries[i] = NULL;
    }

    hashtable->size = size;

    return hashtable;
}

// Hash a string for a particular hash table.

int ht_hash(ht_t *hashtable, char *key)
{

    unsigned long int hashval = 0;
    int i = 0;

    // Convert our string to an integer
    while (i < strlen(key))
    {
        hashval = hashval << 8;
        hashval += key[i];
        i++;
    }

    return hashval % hashtable->size;
}

// Create a key-value pair.

entry_t *ht_newpair(char *key, char *value)
{
    entry_t *newpair;

    if ((newpair = malloc(sizeof(entry_t))) == NULL)
    {
        return NULL;
    }

    if ((newpair->key = strdup(key)) == NULL)
    {
        return NULL;
    }

    if ((newpair->value = strdup(value)) == NULL)
    {
        return NULL;
    }

    newpair->next = NULL;

    return newpair;
}

// Insert a key-value pair into a hash table.

void ht_set(ht_t *hashtable, char *key, char *value)
{
    int bin = 0;
    entry_t *newpair = NULL;
    entry_t *next = NULL;
    entry_t *last = NULL;

    bin = ht_hash(hashtable, key);

    next = hashtable->entries[bin];

    while (next != NULL && next->key != NULL && strcmp(key, next->key) > 0)
    {
        last = next;
        next = next->next;
    }

    // There's already a pair.  Let's replace that string.
    if (next != NULL && next->key != NULL && strcmp(key, next->key) == 0)
    {

        free(next->value);
        next->value = strdup(value);

        // Nope, could't find it.  Time to grow a pair.
    }
    else
    {
        newpair = ht_newpair(key, value);

        // We're at the start of the linked list in this bin.
        if (next == hashtable->entries[bin])
        {
            newpair->next = next;
            hashtable->entries[bin] = newpair;

            // We're at the end of the linked list in this bin.
        }
        else if (next == NULL)
        {
            last->next = newpair;

            // We're in the middle of the list.
        }
        else
        {
            newpair->next = next;
            last->next = newpair;
        }
    }
}

// Retrieve a key-value pair from a hash table.

char *ht_get(ht_t *hashtable, char *key)
{
    int bin = 0;
    entry_t *pair;

    bin = ht_hash(hashtable, key);

    // Step through the bin, looking for our value.
    pair = hashtable->entries[bin];
    while (pair != NULL && pair->key != NULL && strcmp(key, pair->key) > 0)
    {
        pair = pair->next;
    }

    // Did we actually find anything?
    if (pair == NULL || pair->key == NULL || strcmp(key, pair->key) != 0)
    {
        return NULL;
    }
    else
    {
        return pair->value;
    }
}

// delet a key-value pair from a hash table.

void ht_del(ht_t *hashtable, char *key)
{
    int bin = 0;
    entry_t *pair;
    entry_t *last;

    bin = ht_hash(hashtable, key);

    // Step through the bin, looking for our value.
    pair = hashtable->entries[bin];
    last = NULL;
    while (pair != NULL && pair->key != NULL && strcmp(key, pair->key) > 0)
    {
        last = pair;
        pair = pair->next;
    }

    // Did we actually find anything?
    if (pair != NULL && pair->key != NULL && strcmp(key, pair->key) == 0)
    {
        if (last == NULL)
        {
            hashtable->entries[bin] = pair->next;
        }
        else
        {
            last->next = pair->next;
        }
        free(pair->key);
        free(pair->value);
        free(pair);
    }
}

// Destroy a hash table.

void ht_destroy(ht_t *hashtable)
{
    int i;
    entry_t *pair;
    entry_t *next;

    // Free the memory for each bin.
    for (i = 0; i < hashtable->size; i++)
    {
        pair = hashtable->entries[i];
        while (pair != NULL)
        {
            next = pair->next;
            free(pair->key);
            free(pair->value);
            free(pair);
            pair = next;
        }
    }

    // Free the table itself.
    free(hashtable->entries);
    free(hashtable);
}

// print all the key-value pairs in a hash table.

void ht_print(ht_t *hashtable)
{
    int i;
    entry_t *pair;

    for (i = 0; i < hashtable->size; i++)
    {
        pair = hashtable->entries[i];
        while (pair != NULL)
        {
            printf("%s:%s \n", pair->key, pair->value);
            pair = pair->next;
        }
    }
}

// test the hash table.

// search for a key-value pair in a hash table.


void test_hashtable()
{
    ht_t *hashtable = ht_create(65536);

    ht_set(hashtable, "key1", "inky");
    ht_set(hashtable, "key2", "pinky");
    ht_set(hashtable, "key3", "blinky");
    ht_set(hashtable, " key4", "clyde");
    ht_set(hashtable, "key5", "sue");

    ht_print(hashtable);

    ht_del(hashtable, "key1");
    printf("Delete key1 form tabele \n");
    ht_print(hashtable);

    ht_destroy(hashtable);
}

int main()
{
    test_hashtable();
    return 0;
}