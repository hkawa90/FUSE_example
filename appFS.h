#ifndef _APPFS_H_
#define _APPFS_H_

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h> // for PATH_MAX

#ifdef __cplusplus
extern "C"
{
#endif

#define FILE_MAX		(100)
#define MAX_LEN			(100)

#define DEFAULT_MOUNT_POINT	"/tmp/ex37"
typedef void (*appFsGetter)(char **, size_t *);
typedef void (*appFsSetter)(const char *, size_t);

typedef struct _file {
    appFsGetter getter;
    appFsSetter setter;
    struct stat stat;
    char path[PATH_MAX];
} PUBLISHING_FILE;

int add_publish_resource(PUBLISHING_FILE *);
    
#ifdef __cplusplus
};
#endif
    
#endif
