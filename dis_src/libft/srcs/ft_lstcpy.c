/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerevo <lowczarc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:37:40 by zerevo            #+#    #+#             */
/*   Updated: 2018/02/20 11:22:07 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*ret;

	ret = NULL;
	while (lst)
	{
		ft_lstadd(&ret, ft_lstcreat(lst->content, lst->content_size));
		lst = lst->next;
	}
	return (ret);
}
