#include "libftprintf.h"
/*
** creits https://stackoverflow.com/questions/148403/utf8-to-from-wide-char-conversion-in-stl/14809553
*/
char 			*ft_wchar_to_UTF8(wchar_t * in)
{
    t_list 		*out;
    unsigned int	codepoint = 0;
   char 		*strout;   

    while (*in != 0)
    {
	    printf("it\n");
        if (*in >= 0xd800 && *in <= 0xdbff)
            codepoint = ((*in - 0xd800) << 10) + 0x10000;
        else
        {
            if (*in >= 0xdc00 && *in <= 0xdfff)
                codepoint |= *in - 0xdc00;
            else
                codepoint = *in;

            if (codepoint <= 0x7f && !ft_lststradd(&out, ft_strdup((char[2]){codepoint, 0})))
        	{
		   ft_lstclear(&out, free);
		   return (NULL);
		}    
	else if (codepoint <= 0x7ff && !ft_lststradd(&out, ft_strdup((char[3]){
			0xc0 | ((codepoint >> 6) & 0x1f),
			0x80 | (codepoint & 0x3f),
			0})))
        	{
		   ft_lstclear(&out, free);
		   return (NULL);
		}    
            else if (codepoint <= 0xffff && !ft_lststradd(&out, ft_strdup((char[4]){
			0xe0 | ((codepoint >> 12) & 0x0f),
			0x80 | ((codepoint >> 6) & 0x3f),
			0x80 | (codepoint & 0x3f),
			0})))
        	{
		   ft_lstclear(&out, free);
		   return (NULL);
		}    
            else if (!ft_lststradd(&out, ft_strdup((char[5]){
			0xf0 | ((codepoint >> 18) & 0x07),
			0x80 | ((codepoint >> 12) & 0x3f),
			0x80 | ((codepoint >> 6) & 0x3f),
			0x80 | (codepoint & 0x3f),
			0})))
        	{
		   ft_lstclear(&out, free);
		   return (NULL);
		}    
            codepoint = 0;
        }
	in += 1;
    }
    strout = (ft_lststrjoin(out));
    ft_lstclear(&out, &free);
    return (strout);
}

