char *mx_strstr(const char *s1, const char *s2)
{ 
    int j;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        j = 0;
        while (s1[i + j] == s2[j])
        {
            if (s2[j + 1] == '\0')
                return (char *)( s1 + i );
            j++;
        }
    }
    return 0;
}



