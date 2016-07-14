#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;
const int TABLE_SIZE = 100;

/*Link List Class Declaration*/

class LinkedHash
{
    public:
            int key, value;
            LinkedHash *next;
            LinkedHash(int key, int value)
            {
                this->key = key;
                this->value = value;
                this->next = NULL;
            }
};

/*HashMap Class Declaration*/
class HashMap
{
   private :
            LinkedHash **htable;
   public :
            HashMap()
            {
                htable = new LinkedHash*[TABLE_SIZE];
                for (int i = 0; i<TABLE_SIZE; i++)
                {
                    htable[i] = NULL;
                }
            }

            /*~HashMap()
            {
                for (int i = 0; i < TABLE_SIZE; i++)
                {
                    if (htable[i] != NULL)
                    {
                        LinkedHash *prev = NULL;
                        LinkedHash *entry = htable[i];
                        while (entry != NULL)
                        {
                            prev = entry;
                            entry = entry->next;
                            delete prev;
                        }
                    }
                    delete[] htable;
                }
            }*/

            /*Hash Function*/
            int HashFunc(int key)
    	    {
                return key % TABLE_SIZE;
            }

            /*Insert Element at a key*/
            void Insert(int key, int value)
            {
                int hash_val = HashFunc(key);
                if (htable[hash_val] == NULL)
                    htable[hash_val] = new LinkedHash(key, value);
                else
                {
                    LinkedHash *entry = htable[hash_val];
                    while (entry->next != NULL)
                        entry = entry->next;

                    if (entry->key == key)
                        entry->value = value;
                    else
                        entry->next = new LinkedHash(key, value);
                }
            }

            /*Search Element at a key*/
            int Find(int key)
            {
                int hash_val = HashFunc(key);
                if (htable[hash_val] == NULL)
                    return -1;
                else
                {
                    LinkedHash *entry = htable[hash_val];
                    while (entry != NULL && entry->key != key)
                        entry = entry->next;

                    if (entry == NULL)
                        return -1;
                    else
                        return entry->value;
                }
            }

            /*Delete Element at a key*/
            void Delete(int key)
            {
                int hash_val = HashFunc(key);
                if (htable[hash_val] != NULL)
                {
                    LinkedHash *entry = htable[hash_val];
                    LinkedHash *prev = NULL;

                    while (entry->next != NULL && entry->key != key)
                    {
                        prev = entry;
                        entry = entry->next;
                    }

                    if (entry->key == key)
                    {
                        if (prev == NULL)
                        {
                            LinkedHash *next = entry->next;
                            delete entry;
                            htable[hash_val] = next;
                        }
                        else
                        {
                            LinkedHash *next = entry->next;
                            delete entry;

                            prev->next = next;
                        }
                    }
                }
            }
};

int main()
{
    HashMap hash;
    int key, value, choice;
    int success[20], failure[20];
    double successCount = 0;
    double failureCount = 0;
    printf("Key\t\tValue\n");
      
    for(int i=0; i<TABLE_SIZE; i++)
    {
        key   = rand()%100;
        value = rand()%100;
        
        if(i<5)
        {
           success[i] = key;
           failure[i] = rand()%100;
        }
	hash.Insert(key, value);
        printf("%d\t\t%d\n", key, value);
    }

    for(int i = 0; i<5; i++)
    {
        if(hash.Find(success[i]) == -1)
        {
            //cout << "No element found at key " << key << endl;
             failureCount++; 
        }
        else
        {
          cout << "Element at key " << success[i] << " : " <<  hash.Find(key) << endl;
           //cout << hash.Find(key) << endl;
           successCount++;
        }

        if(hash.Find(failure[i]) == -1)
        {
            //cout << "No element found at key " << key << endl;
             failureCount++; 
        }
        else
        {
           cout << "Element at key " <<key<< " : ";
           cout << hash.Find(key) << endl;
           successCount++;
        }
   }

   printf("Success Count = %f\n", (successCount/20));
   printf("Failure Count = %f\n", (failureCount/20));
}    
