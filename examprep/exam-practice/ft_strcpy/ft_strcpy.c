
char	*ft_strcpy(char *s1, char *s2)
{
	char *dest = s1;
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (dest);
}
/*
int	main(void)
{
	char s1[] = "";
	char s2[] = "test";
	ft_strcpy(s1, s2);
	printf("%s\n", s1);
} */
