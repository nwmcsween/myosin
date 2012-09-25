#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "paths.h"

/*@doc
 * desc: See POSIX confstr()
 */
size_t confstr(int name, char *buf, size_t len)
{
	const char *sym = "";

	switch (name) {
	case _CS_PATH:
		sym = _PATH_STDPATH;
		break;
	default:
		errno = EINVAL;
		return (0);
	}

	const size_t sym_len = strlen(sym);
	if (buf != NULL && len != 0) {
		if (len >= sym_len) {
			memcpy(buf, sym, len);
		} else {
			memcpy(buf, sym, len - 1);
			buf[len - 1] = '\0';
		}
	}

	return (sym_len + 1);
}
