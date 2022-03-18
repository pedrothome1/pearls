#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "bitvec.h"

#define MAX_RECORDS 10000000

int main() {
  int i, r;
  FILE *phones_f, *phones_txt_f;
  bitvec *bit;

  srand(time(NULL));
  phones_f = fopen("phones", "w");
  phones_txt_f = fopen("phones.txt", "w");
  bit = bitvec_init(MAX_RECORDS);

  for (i = 0; i < MAX_RECORDS; ++i) {
    do {
      r = rand() % MAX_RECORDS;
    } while (bitvec_get(bit, r) == 1);

    bitvec_on(bit, r);
    
    fprintf(phones_txt_f, "%07d\t\t0x%08X\n", r, r);
    fwrite(&r, 3, 1, phones_f);
  }

  fclose(phones_f);
  fclose(phones_txt_f);
  bitvec_free(bit);
  return 0;
}