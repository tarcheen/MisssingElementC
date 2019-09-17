/*
 Developer: Hamed Mirlohi
 Date: 09/11/2019
 
 In this problem, we are preseneted with two arrays of numbers.
 Child array has all the elements of mother array, however one item is missing.
 to Approach this problem, we are using Hash tables to solve the issue.
 we store all the childs missing item in hash table, then we check the hash-table
 against all mothers value, if one value was not detected in the hash table, then
 we will return the result.
 
 */

#include "stdio.h"
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 20
#define TAKEN 't'
#define NOT_FOUND 'n'


char find_missing(char* arr, char* missArray, int arrLength, int missArrayLength)
{

 char myHash[HASH_SIZE];
    
 int i;
// fill hash with child array characters 
for(i = 0; i < missArrayLength; ++i)
{
    myHash[missArray[i]] = TAKEN;
}

// check see which parent array character does not have it
for(i = 0; i < arrLength; ++i)
{
    if(myHash[arr[i]] != TAKEN)
    {
        // detected, return the missing character
        return arr[i];
    }
   
}
    
return NOT_FOUND;
   
}


int main(void)
{
   char arr[] = {'2','4','6','8'};
   char missArr[] = {'6','2','8'};
   char number = find_missing(arr, missArr, sizeof(arr), sizeof(missArr));
    
    if(number == 'n')
    {
        printf("No missing char\n");
        return 0;
    }
    printf("Missing char: %c\n", number);
}
