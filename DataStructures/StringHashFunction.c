#include "pch.h"
#include "framework.h"

#include "StringHashFunction.h"

int HashFunctionHorner(const char* s, int table_size)
{
    const int key = table_size - 1;

    int hash_result = 0;
    int i = 0;
    while (s[i] != '\0') {
        hash_result = (key * hash_result + s[i]) % table_size;
        ++i;
    }
    hash_result = (hash_result * 2 + 1) % table_size;
    return hash_result;
}