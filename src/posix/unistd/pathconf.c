/*@doc
 * desc: See POSIX pathconf()
 */
long pathconf(const char *path, int name)
{
	return (_xconf(name));
}
