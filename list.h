#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include <cstring>

template <typename T>
class List;

template <typename T>
class ListNode
{
  ListNode* prev;
  ListNode* next;
  T data;
public:
  ListNode(T fn);
  ~ListNode();
  friend class List<T>;
}; //ListNode declaration

template <typename T>
class List
{
  ListNode<T>* head;
  ListNode<T>* curr;
public:
  List();
  ~List();
  bool find(T &fin);
  void insert(const T &i);
  void print() const;
}; //List declaration

#endif