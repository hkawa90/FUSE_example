#include <stdio.h>
#include <string.h>
#include "appFS.h"


void resource1(char **contents, size_t*length)
{
    static char buf[MAX_LEN];
    static int counter = 0;

    printf("getter %d\n", counter);
    snprintf(buf, MAX_LEN-1, "%d\n", counter);
    counter++;

    *contents = buf;
    *length = strlen(buf);
}

int main(int argc, char *argv[])
{
    PUBLISHING_FILE file;

    // Setup publishing files
    file.getter = resource1;
    strcpy(file.path, "/file1");
    file.stat.st_mode = S_IFREG | 0777;
    file.stat.st_nlink = 1;
    file.stat.st_uid = getuid();
    file.stat.st_gid = getgid();
    add_publish_resource(&file);

    strcpy(file.path, "/debug/counter");
    add_publish_resource(&file);
    for (;;) {
        sleep(5);
    }

    return 0;
}
