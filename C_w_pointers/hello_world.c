#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


//very simple allocation of the memory and changing something in the newly allocated memory
int main(){
  char* s;
  int stringsize;

  stringsize = sizeof("hello");
  printf("size of 'hello' is %d\n", stringsize); 
  
  s = (char*)malloc(stringsize);
  if (s == NULL){
    printf("malloc failed!\n");
    exit(0);
  }
  
  //now copy the string into the newly allocated memory
  strncpy(s, "hello", stringsize);

  //and change the first character (just to show we can)
  printf("s is %s\n", s);
  s[0] = 'c';
  printf("s is now %s\n", s);
  return 0;  
}


