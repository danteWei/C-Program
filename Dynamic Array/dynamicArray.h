#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_
#define NOT_OK (0)
#define ALL_OK (1)
#define INDEX_OUT_OF_BOUND (-1)
#define TRUE (1)
#define FALSE (0)

typedef struct {
	int vertex;
	double dist;
	int pos;
} node_t;

typedef node_t DT;

typedef struct {
	DT *arr;			// an integer array
	int size;			// the number of elements currently in the array
	int capacity;		// the max number of elements that can be stored in the array
} d_array_t;

int d_init(d_array_t *);
int get(d_array_t *, int, DT *);
int removeAt(d_array_t *, int, DT *);
int push(d_array_t *, DT);
int resize(d_array_t *, int);
int d_clear(d_array_t *);
int d_set(d_array_t *, int, DT);

#endif
