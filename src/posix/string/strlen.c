#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "bit.h"

/*@doc
 * @desc: see POSIX strlen()
 */
size_t strlen(const char *s)
{
	const char *z = s;
	const size_t *w;

	/* Todo: Document me */
	for (; ((uintptr_t)s & (sizeof(size_t) - 1)); s++) {
		if (*s == '\0') {
			return (s - z);
		}
	}
	for (w = (const size_t *)s; !word_has_zero(*w); w++);
	for (s = (const char *)w; *s != '\0'; s++);

	return (s - z);
}
