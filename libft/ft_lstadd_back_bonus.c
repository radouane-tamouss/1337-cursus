/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:28:40 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/14 00:43:33 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp -> next)
			tmp = tmp -> next;
		tmp -> next = new;
	}
}
