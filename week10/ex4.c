#include "stdio.h"
#include "dirent.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "stdlib.h"


int main() {
  char** files = malloc(sizeof(char) * 256);
  int* inums = malloc(sizeof(int) * 256);
  DIR* directory = opendir("tmp");
  struct dirent* entry;
  struct stat* buff;
  int counter = 0;
  while ((entry = readdir(directory)) != NULL) {
    stat(entry->d_name, buff);
    files[counter] = entry->d_name;
    inums[counter] = entry->d_ino;
    counter++;
  }

  for (int i = 0; i < counter; i++) {
    int link_counter = 0;
    for (int j = 0; j < counter; j++) {
      if (inums[i] == inums[j]){
           link_counter++;
      }
    }
    if (link_counter > 1) {
      printf("%s: ", files[i]);
      for (int j = 0; j < counter; j++) {
        if (inums[i] == inums[j] && files[i] != files[j]){
            printf("%s ", files[j]);
        }
      }
      printf("\n");
    }
  }
}