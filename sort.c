#include <stdio.h>
#include "bitvec.h"

#define RECORDS_NUM 10000000

void print_bitvec(bitvec *bv) {
  int i;

  for (i = 0; i < bv->bytes_n*8; ++i) {
    if (i>0 && i % 8 == 0) putchar(' ');
    printf("%d", bitvec_get(bv, i));
  }
  putchar('\n');
}

int main() {
  int i, phone;
  FILE *src_f, *dst_f, *dst_txt_f;
  bitvec *bit;

  src_f = fopen("phones", "r");
  dst_f = fopen("phones-sorted", "w");
  dst_txt_f = fopen("phones-sorted.txt", "w");
  bit = bitvec_init(RECORDS_NUM);

  for (i = 0; i < RECORDS_NUM; ++i) {
    phone = 0;
    fread(&phone, 3, 1, src_f);
    // phone = (phone & 0xFF0000) >> 16 | (phone & 0x0000FF) << 16 | phone & 0x00FF00;
    bitvec_on(bit, phone);
  }

  for (i = 0; i < RECORDS_NUM; ++i) {
    if (bitvec_get(bit, i)) {
      fprintf(dst_txt_f, "%07d\n", i);
    }
  }

  fclose(src_f);
  fclose(dst_f);
  fclose(dst_txt_f);
  bitvec_free(bit);
}