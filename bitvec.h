#ifndef BITVEC_H
#define BITVEC_H

#include <stddef.h>

#define BV_BYTE 8

typedef struct bitvec bitvec;
typedef unsigned char byte_t;

struct bitvec {
  size_t bytes_n;   /* Number of allocated bytes */
  byte_t *bytes;
};

bitvec *bitvec_init(size_t capacity);
void bitvec_free(bitvec *bv);

void bitvec_on(bitvec *bv, int i);
void bitvec_off(bitvec *bv, int i);
int bitvec_get(bitvec *bv, int i);

#endif
