/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:50:45 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 14:35:40 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_sort.h"

/**
 * ft_qsort_asc
 */

static int	partition_asc(int *array, int low, int high)
{
	int	pivot;
	int	i;

	pivot = array[high];
	i = (low - 1);
	while (low < high)
	{
		if (array[low] <= pivot)
		{
			i++;
			ft_intswap(&array[i], &array[low]);
		}
		low++;
	}
	ft_intswap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	ft_qsort_asc(int *tab, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition_asc(tab, low, high);
		ft_qsort_asc(tab, low, pivot - 1);
		ft_qsort_asc(tab, pivot + 1, high);
	}
}

/**
 * ft_qsort_des
 */

static int	partition_des(int *array, int low, int high)
{
	int	pivot;
	int	i;

	pivot = array[high];
	i = (low - 1);
	while (low < high)
	{
		if (array[low] >= pivot)
		{
			i++;
			ft_intswap(&array[i], &array[low]);
		}
		low++;
	}
	ft_intswap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	ft_qsort_des(int *tab, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition_des(tab, low, high);
		ft_qsort_des(tab, low, pivot - 1);
		ft_qsort_des(tab, pivot + 1, high);
	}
}

/** function to find the partition position
 * 
 * select the rightmost element as pivot
 * 
 * pointer for greater element
 * 
 * traverse each element of the array
 * compare them with the pivot
 * 
 * if element smaller than pivot is found
 * swap it with the greater element pointed by i
 * 
 * swap element at i with element at j
 * 
 * swap the pivot element with the greater element at i
 * 
 * return the partition point
 */
/*static int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;

	pivot = array[high];
	i = (low - 1);
	while (low < high)
	{
		if (array[low] >= pivot)
		{
			i++;
			ft_intswap(&array[i], &array[low]);
		}
		low++;
	}
	ft_intswap(&array[i + 1], &array[high]);
	return (i + 1);
}*/

/**
 * find the pivot element such that
 * elements smaller than pivot are on left of pivot
 * elements greater than pivot are on right of pivot
 * 
 * recursive call on the left of pivot
 * recursive call on the right of pivot
 */
/*void	ft_qsort_des(int *tab, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(tab, low, high);
		ft_qsort_des(tab, low, pivot - 1);
		ft_qsort_des(tab, pivot + 1, high);
	}
}*/
/*
#include <stdio.h>

//void	printarray(int array[], int size)
{
	for (int i = 0; i < size; ++i) {
		ft_printf("%d  ", array[i]);
	}
	ft_printf("\n");
}

// main function
int	main(void)
{
	int data[] = {8, 7, 2, 1, 0, 9, 6};
	int	n;

	n = sizeof(data) / sizeof(data[0]);
	ft_printf("Unsorted Array\n");
	printarray(data, n);
	ft_qsort(data, 0, n - 1);
	ft_printf("Sorted array in ascending order: \n");
	printarray(data, n);
}
*/
