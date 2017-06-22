#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/types.h>

#ifndef pr_warn
#define pr_warn pr_warning
#endif

#define MODULE_NAME "test1"
#define LICENCE_STR "GPL"
#define AUTHOR_STR  "Veeam Software AG"
#define DESCRIPTION_STR "Veeam test Kernel Module"


#define FILEVER_MAJOR 0
#define FILEVER_MINOR 0
#define FILEVER_REVISION 0
#define FILEVER_BUILD 1

#define _VERSION_STRING(maj,min,rev,build) #maj "." #min "." #rev "." #build
#define VERSION_STRING(maj,min,rev,build) _VERSION_STRING(maj,min,rev,build)

#define FILEVER_STR VERSION_STRING(FILEVER_MAJOR, FILEVER_MINOR, FILEVER_REVISION, FILEVER_BUILD)


#define SUCCESS 0

int __init test1_init(void)
{
	int result = SUCCESS;

	pr_info("    %s:%s %s\n", MODULE_NAME,  __FUNCTION__, "Loading" );

	pr_info("    %s:%s %s%s\n", MODULE_NAME,  __FUNCTION__, "Version=",  FILEVER_STR);


	pr_info("    %s:%s %s\n", MODULE_NAME,  __FUNCTION__, "Loading complete" );
	return result;
}

void __exit test1_exit(void)
{
	pr_info("    %s:%s %s\n", MODULE_NAME,  __FUNCTION__, "Unloading module" );

	pr_info("    %s:%s %s\n", MODULE_NAME,  __FUNCTION__, "Module unloaded" );
}

module_init(test1_init);
module_exit(test1_exit);


MODULE_LICENSE( LICENCE_STR );
MODULE_AUTHOR( AUTHOR_STR );

MODULE_DESCRIPTION( DESCRIPTION_STR );
MODULE_VERSION(FILEVER_STR);

