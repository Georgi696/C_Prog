#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);    
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
  case FULL_HOUSE: return "FULL_HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  default: return "NOTHING";
  }
}

char value_letter(card_t c) {
  char x = '?';
  if(c.value >= 2 && c.value <= 9){
    return '0' + c.value;
  }
  switch(c.value){
  case 10:
    x = '0';
    break;
  case VALUE_JACK:
    x = 'J';
    break;
  case VALUE_QUEEN:
    x = 'Q';
    break;
  case VALUE_KING:
    x = 'K';
    break;
  case VALUE_ACE:
    x = 'A';
    break;
  default:
    break;
  }

  return x;
}


char suit_letter(card_t c) {
  char x = '?';
  switch(c.suit){
  case SPADES:
    x = 's';
    break;
  case HEARTS:
    x = 'h';
    break;
  case DIAMONDS:
    x = 'd';
    break;
  case CLUBS:
    x = 'c';
    break;
  default:
    break;
  }
  return x;
  
}

void print_card(card_t c) {
  char valueLetter = value_letter(c);
  char suitLetter = suit_letter(c);
  printf("%c%c",valueLetter,suitLetter);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;

  switch(value_let){
  case '0':
    temp.value = 10;
    break;
  case 'J':
    temp.value = VALUE_JACK;
    break;
  case 'Q':
    temp.value = VALUE_QUEEN;
    break;
  case 'K':
    temp.value = VALUE_KING;
    break;
  case 'A':
    temp.value = VALUE_ACE;
    break;
  default:
    temp.value = value_let - '0'; 
  }

  switch(suit_let){
  case 's':
    temp.suit = SPADES;
    break;
  case 'h':
    temp.suit = HEARTS;
    break;
  case 'd':
    temp.suit = DIAMONDS;
    break;
  case 'c':
    temp.suit = CLUBS;
    break;
  default:
    temp.suit = '?';
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  int div_num = c/13;
  int reminder = c%13;
  temp.value = reminder + 2;

  switch(div_num){
  case 0:
    temp.suit = SPADES;
    break;
  case 1:
    temp.suit = HEARTS;
    break;
  case 2:
    temp.suit = DIAMONDS;
    break;
  case 3:
    temp.suit = CLUBS;
    break;
  default:
    temp.suit = NUM_SUITS;
    break;
  }
  return temp;
}
