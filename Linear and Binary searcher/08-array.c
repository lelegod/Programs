#include <stdlib.h>
#include <stdio.h>

#ifndef  ELT_T
# define ELT_T int
#endif

struct Array
{
    ELT_T *elements;	// memory containing
    size_t size;	// this many elements
};

/* make a new Array and pre-allocate enough space for size elements
 */
struct Array *newArray(size_t size)
{
    struct Array *array = malloc(sizeof(struct Array));
    array->elements = calloc(size, sizeof(ELT_T));
    array->size     = size;
    return array;
}

size_t Array_size(struct Array *array)
{
    return array->size;
}

/* print a message and exit if index is not within the bounds of the array
 */
void Array__boundsCheck(struct Array *array, size_t index)
{
    if (index >= array->size) {
	fprintf(stderr, "index %zi is out of bounds for array of size %zi\n", index, array->size);
	exit(1);
    }
}

/* return the element of the array at the given index
 */
ELT_T Array_get(struct Array *array, size_t index)
{
    Array__boundsCheck(array, index);
    return array->elements[index];
}

/* store the element into the array at the given index
 */
void Array_put(struct Array *array, size_t index, ELT_T element)
{
    Array__boundsCheck(array, index);
    array->elements[index] = element;
}

/* store the element into the array at the given index
 */
void Array_append(struct Array *array, ELT_T element)
{
    array->size += 1;
    array->elements = realloc(array->elements, sizeof(ELT_T) * array->size);
    array->elements[array->size-1] = element;
}

/*ssize_t Array_linSearch(struct Array *array, ELT_T element){
    ssize_t size = array->size;
    for (ssize_t i = 0; i < size; i++){
        if (array->elements[i] == element) {
            return i;
        } 
    }
    return -1;
}

ssize_t Array_binSearch(struct Array *array, ELT_T element){
    ssize_t left = 0;
    ssize_t right = array->size - 1;
    while (left <= right){
        ssize_t mid = (left+right)/2;
        ELT_T e = array->elements[mid];
        if (element<e) right = mid-1;
        else if (element>e) left = mid+1;
        else return mid;
    }
    return -1 - left;
}

void swap(struct Array *array, ssize_t index){
    ELT_T temp = array->elements[index-1];
    array->elements[index-1] = array->elements[index];
    array->elements[index] = temp;
}

void Array_insert(struct Array *array, ELT_T element) {
    Array_append(array, element);
    ssize_t index = array->size - 1; // the index of the new element
    while (index > 0 && array->elements[index-1] > array->elements[index]) {
        swap(array, index);
        --index;
    }
}*/

ssize_t Array_linSearch(struct Array *array, ELT_T element){
    ssize_t size = array->size;
    for (ssize_t i = 0; i < size; i++){
        if (strcmp(array->elements[i], element) == 0) {
            return i;
        } 
    }
    return -1;
}

ssize_t Array_binSearch(struct Array *array, ELT_T element){
    ssize_t left = 0;
    ssize_t right = array->size - 1;
    while (left <= right){
        ssize_t mid = (left+right)/2;
        ELT_T e = array->elements[mid];
        if (strcmp(element,e)<0) right = mid-1;
        else if (strcmp(element,e)>0) left = mid+1;
        else return mid;
    }
    return -1 - left;
}

void swap(struct Array *array, ssize_t index){
    ELT_T temp = array->elements[index-1];
    array->elements[index-1] = array->elements[index];
    array->elements[index] = temp;
}

void Array_insert(struct Array *array, ELT_T element) {
    Array_append(array, element);
    ssize_t index = array->size - 1; // the index of the new element
    while (index > 0 && strcmp(array->elements[index-1], array->elements[index]) > 0) {
        swap(array, index);
        --index;
    }
}

/*void Array_insert(struct Array *array, ELT_T element) {
    ssize_t i = Array_binSearch(array, element);
    ssize_t pos;
    if (i >= 0) {
        return;}
    else {
        pos = -i - 1;}
    Array_append(array, element);
    ssize_t index = array->size - 1; // the index of the new element
    while (index > pos) {
        swap(array, index);
        --index;
    }
}*/

/*void Array_insert(struct Array *array, ELT_T element)
{
    ssize_t left = Array_binSearch(array, element);
    if (left > 0)
        return;

    // Increase array and append into appropriate index
//    array->elements[index] = element;
//    array->size += 1;
//    array->elements = realloc(array->elements, sizeof(ELT_T) * array->size);
    Array_append(array, element);
    ssize_t index = -left;
    ssize_t size = array->size - 1;
    for (ssize_t i = size; i > index; i--)
    {
        swap(array, i);
    }
}*/


