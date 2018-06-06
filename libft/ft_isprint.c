/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:39:09 by dkaplan           #+#    #+#             */
/*   Updated: 2018/05/17 16:19:34 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int i)
{
	return (i >= 32 && i < 127);
}