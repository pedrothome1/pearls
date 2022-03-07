#include <stdio.h>
#include "bitvec.h"

void print_bitvec(bitvec *bv) {
  int i;

  for (i = 0; i < bv->bytes_n*8; ++i) {
    if (i>0 && i % 8 == 0) putchar(' ');
    printf("%d", bitvec_get(bv, i));
  }
  putchar('\n');
}

void print_bitvec_bytes(bitvec *bv) {
  int i;

  for (i = bv->bytes_n - 1; i >= 0; --i)
    printf("0x%X ", bv->bytes[i]);
  putchar('\n');
}

int main() {
  printf("%X\n", 2228828);
  // bitvec *bv = bitvec_init(10);

  // bitvec_on(bv, 1);
  // bitvec_on(bv, 3);
  // bitvec_on(bv, 7);
  // bitvec_on(bv, 9);

  // printf("Bits: \n");
  // print_bitvec(bv);

  // bitvec_on(bv, 33);
  // bitvec_off(bv, 3);
  // bitvec_off(bv, 9);
  // bitvec_off(bv, 33);
  
  // printf("\nBits: \n");
  // print_bitvec(bv);

  // bitvec_free(bv);
}
