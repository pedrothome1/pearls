#include <stddef.h>
#include <stdlib.h>

#include "bitvec.h"

static inline size_t get_bytes_num(size_t s) {
  return (s % BV_BYTE == 0) ? s/BV_BYTE : s/BV_BYTE + 1;
}

static inline int get_byte_position(int i) {
  return i / BV_BYTE;
}

static void bitvec_grow(bitvec *bv, size_t size) {
  if (bv == NULL || bv->bytes == NULL) return;
  if (size <= bv->bytes_n) return;

  int i;

  bv->bytes = (byte_t *) realloc(bv->bytes, size * sizeof(byte_t));

  for (i = bv->bytes_n; i < size; ++i)
    bv->bytes[i] = 0;
  
  bv->bytes_n = size;
}

bitvec *bitvec_init(size_t capacity) {
  bitvec *bv;
  int bytes_n;

  bv = (bitvec *) malloc(sizeof(bitvec));
  bv->bytes_n = get_bytes_num(capacity);
  bv->bytes = calloc(bv->bytes_n, sizeof(byte_t));

  return bv;
}

void bitvec_free(bitvec *bv) {
  free(bv->bytes);
  free(bv);
}

void bitvec_on(bitvec *bv, int i) {
  if (bv == NULL)
    return;
  if (i < 0)
    return;

  int pos = get_byte_position(i);

  if (pos >= bv->bytes_n)
    bitvec_grow(bv, pos*2 - pos/2);

  bv->bytes[pos] |= 0x1 << (i % 8);
}

void bitvec_off(bitvec *bv, int i) {
  if (bv == NULL)
    return;
  if (i < 0)
    return;

  int pos = get_byte_position(i);

  if (pos >= bv->bytes_n)
    bitvec_grow(bv, pos*2 - pos/2);

  bv->bytes[pos] &= ~(0x1 << (i % 8));
}

int bitvec_get(bitvec *bv, int i) {
  int pos = get_byte_position(i);

  if (bv == NULL)
    return -1;
  if (pos < 0 || pos >= bv->bytes_n)
    return -1;

  int bit = 0x1 << (i % 8);
  
  return (bv->bytes[pos] & bit) == bit ? 1 : 0;
}
