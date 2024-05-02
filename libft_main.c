#include <stdio.h>
#include "libft.h"
static void step_striteri(unsigned int num, char * c)
{
   if(*c == 't') *c = '#';
}
static char step_strmapi(unsigned int num, char c)
{
    if(c == 't') return '*';
return c;
}

static void ft_lstdump(t_list *lst)
{
    t_list	*tmp;

	tmp = lst;
    printf("--- START ---\n");
	while (tmp != NULL)
	{
        printf("Current node: %p,\n", tmp);
        printf("Next node: %p", tmp->next);
        if(tmp->next == NULL)
            printf(" FINAL\n");
        else
            printf("\n");
        printf("Content:%s\n\n",(char *)tmp->content);
		tmp = tmp->next;
	}
    printf("--- END (Size = %d) ---\n", ft_lstsize(lst));
}
int main()
{
    // ------------- ft_split -----------------
    char * fsplit = "Something|for|test"; //Allocated in the immutable memory
    char ** spr;
    spr = ft_split(fsplit, '|');
    printf("ft_split - %s. Result = %s, %s, %s\n", fsplit, spr[0], spr[1], spr[2] );

    // ------------- ft_strmapi -----------------
    char *strmapi;
    char * str2apply = "Test string for strmapi"; //Allocated in the immutable memory
    strmapi = ft_strmapi(str2apply, step_strmapi);
    printf("ft_strmapi - %s, Result = %s\n", str2apply, strmapi);

    // ------------- ft_striteri -----------------
    char str2iteri[] = "Test string for striteri"; //Allocated in the mutable memory
    char * pres;
    pres = ft_strdup(str2iteri); // preserve original string
    ft_striteri(str2iteri, step_striteri);
    printf("ft_striteri - %s, Result = %s\n", pres, str2iteri);

   // ------------- ft_substr -----------------
    char * str2substr = "Test string for substr"; //Allocated in the immutable memory
    char * substr;
    substr = ft_substr(str2substr, 5, 6);
    printf("ft_substr - %s, Result = %s\n", str2substr, substr);

    // ------------- ft_strjoin ----------------
    char *join_part1 = "Something2";
    char *join_part2 = "join!";
    char *joined;
    joined = ft_strjoin(join_part1, join_part2);
    printf("ft_strjoin. Part1 =  %s, Part2 = %s Result = %s\n", join_part1, join_part2, joined);

    // ------------- ft_strtrim -------------
    char * str2trim = "Test string for trim";
    char * what2trim = "iTm";
    char * trim_result;
    trim_result = ft_strtrim(str2trim, what2trim);
    printf("ft_strtrim. String =  %s, Trim = %s Result = %s\n", str2trim, what2trim, trim_result);

	// -------------- BONUS -----------------
    char * lst_content = "Node\0";
    char * lst_content1 = "Another node";
    t_list * mylist;
    mylist = NULL;

   
    ft_lstadd_front(&mylist, ft_lstnew(lst_content));
    ft_lstadd_front(&mylist, ft_lstnew(lst_content));
    ft_lstadd_front(&mylist, ft_lstnew(lst_content));
    ft_lstadd_front(&mylist, ft_lstnew(lst_content));
    ft_lstadd_back(&mylist, ft_lstnew(lst_content1));


    ft_lstdump(mylist);

}
