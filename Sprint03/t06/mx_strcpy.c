char *mx_strcpy(char *dst, const char *src)
{
    if (!dst || !src) return 0;
    for (int i = 0; src[i] != '\0'; i++)
        dst[i] = src[i];
    return dst;
}


