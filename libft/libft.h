/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:29:42 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/10 13:00:02 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# define BUFFER_SIZE 42

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
Converts the initial portion of the string str to int.

Trims whitespace from the start of strs and
checks for 1 sign before the integers.

LIMITS: INT_MAX, INT_MIN

LIMIT PROTECTION: NO, Undefined behavior
Behavior becomes defined after it exceeds LLONG_MAX or LLONG_MIN
(Returns 1, 0, -1 based on which limits it exceeds)
 */
int		ft_atoi(const char *str);
/*
Writes len bytes to string ptr "b"

NULL PROTECTION: NO, Undefined behavior
 */
void	ft_bzero(void *b, size_t len);
/*
Checks if char is alpha or digit.
 */
int		ft_isalnum(int c);
/*
Checks if char is alphabet
 */
int		ft_isalpha(int c);
/*
Checks if char is within ascii limits
 */
int		ft_isascii(int c);
/*
Checks if char is a digit
 */
int		ft_isdigit(int c);
/*
Checks if char is a printable char
 */
int		ft_isprint(int c);
/*
Located the first occurrence of char "c" within "n" bytes of string "s"

NULL PROTECTION: NO, Undefined behavior
 */
void	*ft_memchr(const void *s, int c, size_t n);
/*
Copies "n" bytes from src to dst.

Behavior is undefined if src and dst overlap.

NULL PROTECTION: YES, Returns dst if both src and dst are NULL
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);
/*
Copies "n" bytes from src to dst.

Can copy if src and dst overlap.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);
/*
Compares "n" bytes from string s1 and string s2
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/*
Writes len bytes from of value (unsigned char)"c" to "b".
 */
void	*ft_memset(void *b, int c, size_t len);
/*
Splits string str into pieces based on the seperator (char)sep.

Protected against failed allocation, will free all allocated memory,
if a failed malloc is encountered.

NULL PROTECTION: YES, Returns NULL if both str is NULL, or if malloc failed.
 */
char	**ft_split(const char *str, char sep);
/*
Locates the first occurrence of char "c" within string "s"

(The search includes the terminating char for string "s")
 */
char	*ft_strchr(const char *s, int c);
/*
Locates the last occurrence of char "c" within string "s"

(The search includes the terminating char for string "s")
 */
char	*ft_strrchr(const char *s, int c);
/*
Duplicated string src by allocating memory and copying it into
new char pointer string.

NULL PROTECTION: YES, Returns NULL if memory allocation fails
 */
char	*ft_strdup(char *src);
/*
Allocates enough memory for a new string to join both strings "s1" and "s2"
into a single string.

NULL PROTECTION: YES, Returns NULL if memory allocation fails OR if either
of the strings are NULL;
 */
char	*ft_strjoin(char const *s1, char const *s2);
/*
Concatenates src into dest IF dest has enough size for characters, depends on
size_t "size" for the size of dest.

IF size is less than or equal to the null terminated length of dest then
concatenation fails.

Returns the total length of the new null terminated string.

NULL PROTECTION: YES, Returns 0 if s1 and s2 are NULL
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size);
/*
Copies characters from src into dest, depends on size_t "size" for the size
of dest.

Returns the total length of the new null terminated string.

NULL PROTECTION: YES, Returns length of src if size is 0.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
/*
Counts the length of string str excluding the null terminator.
 */
size_t	ft_strlen(const char *str);
/*
Compares "n" characters from string s1 and string s2
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*
Locates the first occurrence of the needle "to_find" within string str,
and not more than len bytes are searched from str, or till the null terminator
within string str.

Returns the pointer to the first character of the first occurrence
of the needle if it is found OR NULL if needle is not found.

NULL PROTECTION: YES, Returns str if needle is NULL, and returns NULL
if str and len are NULL.
 */
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
/*
Removes all characters present in to_find from the beginning and the end of
string str and returns a new malloc-ed string with the trimmed size.

Returns the pointer to the newly allocated trimmed string.

NULL PROTECTION: YES, Returns NULL if str or to_find are NULL
 */
char	*ft_strtrim(char const *s1, char const *set);
/*
Allocates the appropriate memory for a new sub string taken out of string "s".

Starts from index start, and goes on for len bytes.

If start index is larger than the length of string s, returns a memory
allocation of 1 byte that can be freed.

NULL PROTECTION: YES, Returns NULL if s is NULL
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/*
Allocates memory for "nmemb" amount of objects that are of size "size" each.

LIMITS: nmemb * size cannot be larger than INT_MAX
NULL PROTECTION: YES, Returns NULL if memory allocation fails
 */
void	*ft_calloc(size_t nmemb, size_t size);
/*
Takes in an int n, and converts it to a string with the appropriate allocated
memory.

LIMITS: n is limited by INT_MAX and INT_MIN
NULL PROTECTION: YES, Returns NULL if memory allocation fails
 */
char	*ft_itoa(int n);
/*
Goes through each character of string "s" and applies function "f" to every
character

Functions stops if string "s" or function "f" are NULL
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/*
Goes through each character of string "s" and applies function "f" to every
character then returns that modified character to a newly allocated string.

Functions stops if string "s" or function "f" are NULL

NULL PROTECTION: YES, Returns NULL if memory allocation fails
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*
Write out char "c" of size 1 byte to the given file descriptor "fd"

Checks if file descriptor is negative, returns and stops functions if true.
 */
void	ft_putchar_fd(char c, int fd);
/*
Write out str "s" of size strlen(s) bytes to the given file descriptor "fd"

Checks if file descriptor or str "s" is negative, returns and stops functions
if true.
 */
void	ft_putstr_fd(char *s, int fd);
/*
Write out str "s" of size strlen(s) bytes to the given file descriptor "fd"
followed by a newline.

Checks if file descriptor or str "s" is negative, returns and stops functions
if true.
 */
void	ft_putendl_fd(char *s, int fd);
/*
Recursively convert int "n" to a char and write it out to the given file
descriptor "fd".
*/
void	ft_putnbr_fd(int n, int fd);
/*
Converts uppercase alphabet to lowercase;
*/
int		ft_tolower(int c);
/*
Converts lowercase alphabet to upper;
*/
int		ft_toupper(int c);

/*
Mallocs for a new t_list type and adds given parameter to the new nodes
content, and assigns the next pointer value to NULL;

NULL PROTECTION: YES, Returns NULL if memory allocation fails
*/
t_list	*ft_lstnew(void *content);
/*
Assigns obj's next value to the first node of lst.

NULL PROTECTION: YES, Returns nothing and stops function if the first node of
lst is NULL or obj is NULL
*/
void	ft_lstadd_front(t_list **lst, t_list *obj);
/*
Returns the size of the linked list

NULL PROTECTION: YES, Returns 0 if lst is NULL
*/
int		ft_lstsize(t_list *lst);
/*
Returns the last node of the list

NULL PROTECTION: YES, Returns NULL if lst is NULL
*/
t_list	*ft_lstlast(t_list *lst);
/*
Adds obj to the next value of the last node within lst.

If lst is NULL, then lst will point to obj.
*/
void	ft_lstadd_back(t_list **lst, t_list *obj);
/*
Deletes the content of node lst and then frees the node.

NULL PROTECTION: YES, Returns nothing and stops function if
lst or function f is NULL
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/*
Applies the function ft_lsddelone to all nodes within the given linked list.

NULL PROTECTION: YES, Returns nothing and stops function if
lst or function f is NULL
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));
/*
Applies function "f" to the content of every node in given linked list

NULL PROTECTION: YES, Returns nothing and stops function if
lst is NULL
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));
/*
Creates a new linked list that will take in all nodes of lst with the modified
values of their content using function "f".

NULL PROTECTION: YES, Returns NULL if lst, f, or del are NULL. Also clears the
new linked list to free its memory and returns NULL if memory allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

///////////////////////////
//GET_NEXT_LINE FUNCTIONS//
///////////////////////////

//Returns the next line from a given FD
//If it reaches end of file, Null is returned
char	*get_next_line(int fd);
void	strcpy_gnl(char *dst, const char *src);
char	*strjoin_gnl(char const *s1, char const *s2);
int		strchr_gnl(const char *s, int c);

#endif
