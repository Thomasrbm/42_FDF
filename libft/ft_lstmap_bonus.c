/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:18:07 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 17:57:57 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*create_node(void)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	return (new_node);
}

void	ft_lstadd_back2(t_list **lst_new, t_list *new_node)
{
	t_list	*ptr_temp;

	ptr_temp = *lst_new;
	if (!lst_new || !new_node)
		return ;
	if (*lst_new == NULL)
	{
		*lst_new = new_node;
		new_node->next = NULL;
		return ;
	}
	while (ptr_temp->next)
		ptr_temp = ptr_temp->next;
	ptr_temp->next = new_node;
	new_node->next = NULL;
}

void	free_cascade(t_list *lst_new, void (*del)(void *))
{
	t_list	*temp;

	while (lst_new)
	{
		temp = lst_new;
		lst_new = lst_new->next;
		del(temp->content);
		free(temp);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*new_node_ptr;

	lst_new = NULL;
	while (lst)
	{
		new_node_ptr = create_node();
		if (!new_node_ptr)
		{
			free_cascade(lst_new, del);
			return (NULL);
		}
		new_node_ptr->content = f(lst->content);
		new_node_ptr->next = NULL;
		ft_lstadd_back2(&lst_new, new_node_ptr);
		lst = lst->next;
	}
	return (lst_new);
}

// ENTRE FIN DU WHILE ET RETURN LST NEW DANS FT_LSTMAP
	// t_list *print = lst_new;
	// while (print)
	// {
	// 	printf("%s\n", (char *)print->content);
	// 	print = print->next;
	// }

// #include <stdio.h>
// #include  <string.h>

// void	del(void *str)
// {
// 	free(str);
// }

// void	*test(void *str)
// {
// 	int i = 0;
// 	while (((char *)str)[i])
// 	{
// 		i++;
// 	}
// 	char *str_new = malloc(i * sizeof(char) + 1);
// 	if (!str_new)
// 		return (NULL);
// 	i = 0;
// 	while (((char *)str)[i])
// 	{
// 			str_new[i] = ((char *)str)[i] - 32;
// 			i++;
// 	}	
// 	str_new[i] = '\0';
// 	return (str_new);
// }

// int main()
// {
// 	t_list	first;
// 	t_list	second;
// 	t_list	third;

// 	t_list *lst;
// 	lst = &first;

// 	first.content = strdup("hello");
// 	second.content = strdup("worldo");
// 	third.content = strdup("dev");

// 	first.next = &second;
// 	second.next = &third;
// 	third.next = NULL;

// 	printf("%s\n", (char *)first.content);
// 	printf("%s\n", (char *)second.content);
// 	printf("%s\n\n", (char *)third.content);

// 	t_list *stock = ft_lstmap(lst, test, del);

// 	del(first.content);
//     del(second.content);
//     del(third.content);

//     while (stock)
//     {
//         t_list *temp = stock; // Stocke l'adresse du nœud actuel
//         stock = stock->next; // Passe au nœud suivant
//         del(temp->content); // Libère le contenu
//         free(temp); // Libère le nœud
//     }
// 	return 0;
// }

// strdup because cant first->content[] = "HELLO"
// on already existing string and if 
// just litterla sting first->content = "HELLO"
// will not be modifiable / usable for copying
// in another function