#include "holberton.h"
/**
 * free_grid - frees 2d array
 * @grid: 2d arr
 * Return: void
 */
void free_grid(char **grid)
{
	int i = 0;

	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
