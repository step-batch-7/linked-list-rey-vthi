#include<stdlib.h>
#include<stdio.h>
#include "list.h"

List_ptr create_list(void){
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

Status add_to_end(List_ptr list, int value) 
{
  Node_ptr new_node = create_node(value);
   if (list->head == NULL)
   {
     list->head = new_node;
   } else {
     list->last->next = new_node;
   }
     list->last = new_node;
     list->count++;
     return Success;
}

void display(List_ptr list)
{
  Node *p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d\n", p_walk->value);
    p_walk = p_walk->next;
  }
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
   {
     list->head = new_node;
     list->last = new_node;
   } else {
     new_node->next = list->head;
     list->head = new_node;
   }
    list->count++;
    return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position > list->count || position < 0)
  {
    return Failure;
  }
  Node_ptr new_node = create_node(value);
  if (position == 0)
  {
    return add_to_start(list, value);
  }
  Node_ptr p_walk = list->head;
  Node_ptr previous_node = list->head;
  int counter = 0;
  while (counter != position)
  {
    previous_node = p_walk;
    p_walk = p_walk->next;
    counter++;
  }
  previous_node->next = new_node;
  new_node->next = p_walk;
  list->count++;
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if (p_walk->value == value)
    {
      return Failure;
    }
    p_walk = p_walk->next;
  }
    return add_to_end(list, value);
}

Status remove_from_start(List_ptr list)
{
  if(list->head == NULL)
  {
    return Failure;
  }
  Node_ptr new_first_node = list->head->next;
  free(list->head);
  list->head = new_first_node;
  list->count--;
  return Success;
}

Status remove_from_end(List_ptr list)
{ 
  Status status = Failure;
  if(list->head == NULL)
  {
    return Failure;
  }
  Node_ptr last_node = NULL;
  Node_ptr p_walk = list->head;
  while (p_walk->next != NULL)
  {
    last_node = p_walk;
    p_walk = p_walk->next;
  }
  free(p_walk);
  list->last= last_node;
  if(last_node != NULL)
    last_node->next = NULL;
  else
    list->head = last_node;
  list->count--;
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  if(list->head == NULL || position < 0 || position >= list->count){
    return Failure;
  }
  if(position == 0){
    return remove_from_start(list);
  }
  int counter = 0;
  Node_ptr p_walk = list->head;
  Node_ptr last_node = list->head;
  while (counter < position)
  {
    last_node = p_walk;
    p_walk = p_walk->next;
    counter++;
  }
  last_node->next = p_walk->next;
  list->count--;
  free(p_walk);
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  if(!does_exist(list,value))
    return Failure;
  Node_ptr p_walk = list->head;
  for(int position = 0; p_walk!=NULL; position++)
  {
    if(p_walk->value == value)
    {
      return remove_at(list,position);
    }
    p_walk = p_walk->next;
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  if(!does_exist(list,value))
    return Failure;
  Node_ptr p_walk = list->head;
  for(int position = 0; p_walk!=NULL; position++)
  {
    if(p_walk->value == value)
    {
      remove_at(list,position);
      position-=1;
    }
    p_walk = p_walk->next;
  }
  return Success;
}

void destroy_list(List_ptr list)
 {
   Node_ptr p_walk = list->head;
   while(p_walk != NULL){
     Node_ptr next = p_walk->next;
     free(p_walk);
     p_walk = next;
   }
   free(list);
 }

Status clear_list(List_ptr list)
{
  Node_ptr p_walk = list->head;
   while(p_walk != NULL){
     Node_ptr next = p_walk->next;
     free(p_walk);
     p_walk = next;
   }
   list->head = NULL;
   list->last = NULL;
   list->count = 0;
   return Success;
}

Status does_exist(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if(p_walk->value == value){
      return Success;
    }
    p_walk = p_walk->next;
  }
  return Failure;
}

void show_operation_status(int status)
{
  if(status == Failure)
  {
    printf("Failed to perform operation\n");
  } else
  {
    printf("Operation performed successfully\n");
  }
}
