#include "cards.h"
#include <stdio.h>

int main(void) {
  card_t c;
  c.value = 4;
  c.suit = 0;

  for(int i = 0; i<52; i++){
    c = card_from_num(i);
    print_card(c);
    printf("\n");
  }
}
