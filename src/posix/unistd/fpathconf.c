/*@doc
 * desc: See POSIX fpathconf()
 */
long fpathconf(int fd, int name)
{
	return (_xconf(name));
}
