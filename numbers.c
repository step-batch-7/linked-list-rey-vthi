#include "list.h"
#include <stdio.h>

int main(void)
{
  char option;
  int number,status,position;
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
      show_operation_status(status);
      break;
    case 'b':
      printf("Enter a number to add at the start in the list\n");
      scanf("%d", &number);
      status = add_to_start(list, number);
      show_operation_status(status);

      break;
    case 'c':
      printf("Enter a number and position to insert at a given position in the list\n");
      scanf("%d %d", &number, &position);
      status = insert_at(list, number, position);
      show_operation_status(status);
      break;
    case 'd':
      printf("Enter a unique number to add into list\n");
      scanf("%d", &number);
      status = add_unique(list, number);
      show_operation_status(status);
      break;
    case 'e':
      printf("removing a number from the begining\n");
      status = remove_from_start(list);
      show_operation_status(status);
      break;
    case 'f':
      printf("removing a number from the end\n");
      status = remove_from_end(list);
      show_operation_status(status);
      break;
    case 'g':
      printf("Enter a position to remove a number from the list\n");
      scanf("%d", &position);
      status = remove_at(list, position);
      show_operation_status(status);
      break;
    case 'h':
      printf("Enter a number to remove the first occurrence in the list\n");
      scanf("%d", &number);
      status = remove_first_occurrence(list, number);
      show_operation_status(status);
      break;
    case 'i':
      printf("Enter a number to remove all occurrences in the list\n");
      scanf(" %d", &number);
      status = remove_all_occurrences(list, number);
      show_operation_status(status);
      break;
    case 'j':
      printf("clearing the whole list");
      status = clear_list(list);
      show_operation_status(status);
      break;
    case 'k':
      printf("Enter a number to check if a number exists in the list\n");
      scanf("%d", &number);
      status = does_exist(list, number);
      if(status == Failure){
        printf("Number does not exist in the list\n");
      } else
      {
        printf("Number exist in the list\n");
      }
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