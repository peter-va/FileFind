#include <iostream>
#include <cstring>
#include <fstream>
#include "list.h"
#include "directory.h"
#include "list.cpp"

using namespace std;

void reader(List<File*>* list, const char* filename)
{
  char line[256], *nline;
  ifstream inf(filename);
  
  while(inf.getline(line, 256))
  {
    char test = line[0];

    switch (test)
    {
      {case 'd': 
        nline = strrchr(line, ' ');
        nline += 1;
        File* insert = new Directory(nline);
        list->insert(insert);
        break; } //directory case
      {default:
        nline = strrchr(line, ' ');
        nline += 1;
        File *insert = new File(nline);
        list->insert(insert);
        break; } //default case (general files)
    } //switch control
  } //while reading the file
} //reader ()

int main(int argc, const char **argv)
{
  char filename[100];
  List<File*> lf;
  reader(&lf, argv[1]);

  while (strncmp(filename, "Done", 4))
  {
    cout << "Please enter a file name (Done = exit): ";
    cin >> filename;
    
    if (strncmp(filename, "Done", 4))
    {
    File* k = new File(filename);
    lf.find(k);
    } //if user did not type "Done"
  } //while user did not type "Done" yet
    
  return 0;
  
}  // main()

