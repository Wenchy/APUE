/*
 * 
 * struct passwd *getpwnam(const char *name);
 *
 *  struct passwd {
 *       char * pw_name;    // Username.
 *       char * pw_passwd;  // Password.
 *       __uid_t -pw_uid;   // User ID.
 *       __gid_t -pw_gid;   // Group ID.
 *       char * pw_gecos;   // Real name.
 *       char * pw_dir;     // Home directory.
 *       char * pw_shell;   // Shell program.
 *   };
 */

#include <stdio.h>
#include <pwd.h>
#include <sys/types.h>

int main(void)
{
    struct passwd *pw;
    char *username = "wenchy";
    pw = getpwnam(username);
    if ( !pw )
    {
        printf("%s does not exist!", username);
        return -1;
    }

    printf("pw->pw_name = %s\n", pw->pw_name);
    printf("pw->pw_passwd = %s\n", pw->pw_passwd);
    printf("pw->pw_uid = %d\n", pw->pw_uid);
    printf("pw->pw_gid = %d\n", pw->pw_gid);
    printf("pw->pw_gecos = %s\n", pw->pw_gecos);
    printf("pw->pw_dir = %s\n", pw->pw_dir);
    printf("pw->pw_shell = %s\n", pw->pw_shell);
    return 0;
}
