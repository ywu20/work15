#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
char ** parse_args( char * line ){
  char ** args = calloc(6, sizeof(char*));
  line = strsep(&line, "\n");
  char* token;
  int i = 0;

  while(token = strsep(&line," ")){

  args[i] = token;
   i++;
  }
  args[i]= NULL;

  return args;
}

int main(){
 char line [100];
 fgets(line, 100, stdin);

 //printf("line: %s\n", line);
 char ** args = parse_args( line );
/*
 int i =0;
 while(args[i]){
  printf("arg[%d]: %s\n", i, args[i]);
  i++;
 }

*/
 execvp(args[0], args);
 return 0;
}
