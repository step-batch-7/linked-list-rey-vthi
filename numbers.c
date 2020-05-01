#include "list.h"
#include <stdio.h>

int main(void)
{
  char option;
  int number,status;
  List_ptr list = create_list();
  while (option!='m')
  {
    printf("Main Menu\n(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c) insert a number at a given position in the list\n(d) add a unique item on the list at the end(if it alreay exists, do not insert)\n(e) remove a number from the beginning of the list\n(f) remove a number from the end of the list\n(g) remove a number from a given position in the list\n(h) remove first occurrence of a number\n(i) remove all occurrences of a number\n(j) clear the whole list\n(k) check if a number exists in the list\n(l) display the list of numbers\n(m) exit\n\nPlease enter the alphabet of the operation you would like to perform\n");
    scanf(" %c", &option);
    switch (option)
    {
    case 'a':
      printf("Enter a number to add at the end in the list\n");
      scanf("%d", &number);
      status = add_to_end(list, number);
      break;
    case 'b':
      printf("Enter a number to add at the start in the list\n");
      scanf("%d", &number);
      status = add_to_start(list, number);
      break;
    case 'l':
      printf("Elements of list are: \n");
      display(list);
      break;
    case 'm':
      return 0;
    }
  }

  return 0;
}