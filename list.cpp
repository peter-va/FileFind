#include <iostream>
#include <fstream>
#include <cstring>
#include "directory.h"

using std::cout;
using std::endl;

template<typename T>
ListNode<T>::ListNode(T fn)
{
  prev = NULL;
  data = fn;
  next = NULL;
} //ListNode constructor

template<typename T>
ListNode<T>::~ListNode()
{
  delete data;
} //ListNode destructor

template <typename T>
List<T>::List() : head(NULL), curr(NULL) {} //list constructor

template <typename T>
List<T>::~List()
{
  ListNode<T>* ptr = head;

  for (ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  } //cycle list
} //Memory destructor

template <typename T>
bool List<T>::find(T &fin)
{
  int t = 0;

  for (curr = head; curr; curr = curr->next)
  {

    if(!strncmp(fin->getName(), curr->data->getName(), strlen(curr->data->getName())))
    {
      t++;
      curr->data->find(fin->getName());
    } //found one
  } //cycle through list

  if (t) return true;
  cout << "Not found." << endl;
  return false;
} //bool find()

template <typename T>
void List<T>::insert(const T &i)
{
  ListNode<T>* ptr, pre = NULL; curr = NULL;
  
  if (!head)
  {
    head = new ListNode<T>(i);
    return;
  } //if head is null, i.e. beginning of list
  for(ptr = head; (ptr && (*ptr->data > *i)); ptr = ptr->next)
    curr = ptr;
  
  if (curr)
  {
    if (!strncmp(curr->data->getName(), i->getName(),
        strlen(curr->data->getName())))
    {
      File* t = i; curr->data->insert(*t); return;
    } //if the names don't match
    else // if the names match
    {
      if (ptr)
      {
        ListNode<T>* in = new ListNode<T>(i);
        in->next = ptr;
        curr->next = in;
        in->prev = curr;
        return;
      } //if inside list
      else //if curr->next is null
      {
        ListNode<T>* in = new ListNode<T> (i);
        curr->next = in; in->prev = curr; return;
      } // if curr->next is null
    } // if names do match
  } //if curr is not null
  
  else // if curr is null
  {
    if (!strncmp(head->data->getName(), i->getName(),
        strlen(head->data->getName())))
    {
      File* t = i; head->data->insert(*t); return;
    } // if names do not match
    
    else // if names do match
    {
      if (ptr == head)
      {
        ListNode<T>* in = new ListNode<T>(i);
        in->next = ptr;
        head = in;
        return;
      }
      if (!head->next)
      {
        ListNode<T>* in = new ListNode<T>(i);
        head->next = in;
        in->prev = head;
        return;
      } // if head->next is null
      
      ListNode<T>* in = new ListNode<T>(i);
      in->next = head;
      head = in;
      return;
      
    } // if names do match
  } // if curr is null
} // List::insert()

template <typename T>
void List<T>::print() const
{
  ListNode<T>*ptr;

  for (ptr = head; ptr; ptr = ptr->next)
  {
    cout << ptr->data->getName() << endl;
  } //cycle list
} //list print

template class ListNode<File*>;
template class ListNode<Directory*>;
