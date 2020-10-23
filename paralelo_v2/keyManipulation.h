#ifndef KEY_MANIPULATION
#define KEY_MANIPULATION

#include <stdint.h>

#include "definitions.h"

void getFirstKey(int rank, int keySize, uint64_t* maxValue, uint64_t* validKey, key_t2 key);
void generate64BitKey(uint64_t validKey, key_t2 key);
void generateNextKey(int npes, uint64_t* validKey, key_t2 key);
void printKeyToFile(key_t2 key, FILE* fp);
void printKey(key_t2 key);
#endif
