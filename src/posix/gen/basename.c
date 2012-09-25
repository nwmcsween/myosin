#include <libgen.h>
#include <string.h>

/*@doc
 * desc: See POSIX basename()
 */
char *basename(char *s)
{
	size_t i;

	i = strlen(s) - 1;

	if (s == NULL || *s == "") {
		return (".");
	}

	for (; *s[i] != '/'; i--);

	return (s);
}
