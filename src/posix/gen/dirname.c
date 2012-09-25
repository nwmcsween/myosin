#include <libgen.h>
#include <string.h>

/*@doc
 * @desc: See POSIX dirname()
 */
char *dirname(char *s)
{
	if (s == NULL || *s == '\0') {
		return (".");
	}

	size_t i = strlen(s) - 1;
	/* Remove trailing forward slashes, e.g. /usr/bin/ -> /usr/bin */
	for (; i > 0 && s[i] == '/'; i--);
	/* Remove basename, e.g. /usr/bin -> /usr/ */
	for (; i > 0 && s[i - 1] != '/'; i--);
	/* Remove trailing forward slashes on parent /usr/ -> /usr */
	for (; i > 0 && s[i - 1] == '/'; i--);
	/* Handle any so far unhandled paths */
	if (i == 0) {
		if (*s != '/') {
			return (".");
		}
		i++;
	}

	s[i] = '\0';

	return (s);
}