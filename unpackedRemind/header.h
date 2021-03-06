#include <gtk/gtk.h>
#include <unistd.h> // read, write, close
#include <fcntl.h>  // open
#include <stdlib.h> // exit
#include <stdio.h>  // perror
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <limits.h>

#define BAR "=================================================================="

#define handle_error(msg)\
do{\
  perror(msg);\
  exit(EXIT_FAILURE);\
}while(0)


#define backup_error(msg)\
do{\
  fprintf(stderr, "%s\n", msg);\
  sleep(1);\
  system("tput reset");\
  exit(EXIT_FAILURE);\
}while(0)

typedef struct config{
  char* remindDir;  // 
  char* homedir;    // 
  char* exeDir;
  char* iconDir;
  char* updateFile; //  
  char* launchDir;  // launch directory
}config;

config* mine;

void freeMia(config* mine){ 
  free(mine->remindDir);  // .local/share/application/RemindMe
  free(mine->homedir);    // home dir of your pc
  free(mine->exeDir);     // where is the exe
  free(mine->iconDir);    // where is the icon
  free(mine->updateFile); // where is the update.conf
  free(mine->launchDir);  // where do you have launched this program
  free(mine);
}

char* append(char* string1, char* string2){
    size_t dim = (strlen(string1)) + (strlen(string2) + 1);
    char *tmp = malloc(dim * sizeof(char));
    strcpy(tmp, string1);
    strcat(tmp, string2);
    return tmp;
}

int fileExists(const char* filename){
    struct stat buffer;
    int exist = stat(filename,&buffer);
    if(exist == 0)  return 1;
    else  return 0;
}

void printaTest(){
    printf("Home directory ---> %s\n", mine->homedir);
    printf("Launching Directory ---> %s\n", mine->launchDir);
    printf("RemindMe directory ----> %s\n", mine->remindDir);
    printf("Executable directory ---> %s\n", mine->exeDir);
    printf("Update file in directory ----> %s\n", mine->updateFile);
    printf("Icon File in directory ---> %s\n", mine->iconDir);
    exit(0);
}


#include "pre_welcome.h"
#include "eliquid.h"
#include "autobackup.h"
#include "sublInstaller.h"
#include "startupMain.h"
#include "sharedExecIcons.h"
#include "gccInstallers.h"
#include "installGuides.h"
#include "conkyInstaller.h"
#include "firstInstallation.h"
#include "intallers.h"
#include "deezerDownloader.h"

void downloadSettingIcon();
void removeAndExit();
static void activate (GtkApplication *app, gpointer user_data);