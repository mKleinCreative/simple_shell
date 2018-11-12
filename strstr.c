/**
 * _strstr - locates a substring in given string
 * @haystack: memory area pointed to.
 * @needle: constant byte to fill memory with.
 * Return: pointer to beginning of located substring
 *		or NULL if not found.
 */

char *_strstr(char *haystack, char *needle)
{
	int flag, sentence, word;

	if (needle[0] == '\0')
		return (haystack);
	flag = 0;
	for (sentence = 0; haystack[sentence] != '\0'; sentence++)
	{
		for (word = 0; needle[word] != '\0'; word++)
		{
			if (haystack[sentence + word] != needle[word])
			{
				flag = 0;
				break;
			}
			flag = 1;
		}
		if (flag)
			return (haystack + sentence);
	}
		return ('\0');
}

