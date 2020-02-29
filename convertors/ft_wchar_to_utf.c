#include "libftprintf.h"
/*
 ** credits https://stackoverflow.com/questions/148403/utf8-to-from-wide-char-conversion-in-stl/14809553
 */

char                *ft_wchar_to_utf(wchar_t c)
{
    char            *out;
    unsigned int    codepoint = 0;


    out = ft_calloc(5, 1);
    if (((c >= 0xd800) && (c <= 0xdfff)) || (c >= 0x10ffff))
        return (NULL);
    else
    {
        if (c >= 0xdc00 && c <= 0xdfff)
            codepoint |= c - 0xdc00;
        else
            codepoint = c;

        if (codepoint <= 0x7f)
            out[0] = codepoint;
        else if (codepoint <= 0x7ff)
        {
            out[0] = (0xc0 | ((codepoint >> 6) & 0x1f));
            out[1] = (0x80 | (codepoint & 0x3f));
        }
        else if (codepoint <= 0xffff)
        {
            out[0] = (0xe0 | ((codepoint >> 12) & 0x0f));
            out[1] = (0x80 | ((codepoint >> 6) & 0x3f));
            out[2] = (0x80 | (codepoint & 0x3f));
        }
        else
        {
            out[0] = (0xf0 | ((codepoint >> 18) & 0x07));
            out[1] = (0x80 | ((codepoint >> 12) & 0x3f));
            out[2] = (0x80 | ((codepoint >> 6) & 0x3f));
            out[3] = (0x80 | (codepoint & 0x3f));
        }
    }
    return out;
}
