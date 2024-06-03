/*================================================
Assignment name  : flood_fill
Expected files   : flood_fill.c
Allowed functions: -
--------------------------------------------------------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone
by replacing characters inside with the character 'F'. A zone is an group of
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this: (put it in flood_fill.c)

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

Example:

$> cat test.c
#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$>

============FIX=LATER===============================*/

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

// Function to fill the area recursively
void	fill(char **grid, t_point size, t_point current, char target, char fill)
{
	if (current.x < 0 || current.x >= size.x || current.y < 0 || current.y >= size.y ||
		grid[current.y][current.x] != target)
		return;

	grid[current.y][current.x] = fill;

	fill(grid, size, (t_point){current.x, current.y + 1}, target, fill); // Down
	fill(grid, size, (t_point){current.x, current.y - 1}, target, fill); // Up
	fill(grid, size, (t_point){current.x + 1, current.y}, target, fill); // Right
	fill(grid, size, (t_point){current.x - 1, current.y}, target, fill); // Left
}

// Function to initiate the flood fill
void	flood_fill(char **grid, t_point size, t_point start)
{
	char target = grid[start.y][start.x]; // Character to fill
	char fill = 'F'; // Fill character

	fill(grid, size, start, target, fill);
}

// Function to print the grid
void	print_grid(char **grid, t_point size, int y)
{
	if (y >= size.y)
		return;

	printf("%s\n", grid[y]);
	print_grid(grid, size, y + 1);
}

// Function to allocate memory for the grid recursively
char	**allocate_memory(char **grid, t_point size, int y)
{
	if (y >= size.y)
		return (grid);

	grid[y] = (char *)malloc(size.x + 1); // Allocate memory for the current row
	if (!grid[y])
	{
		// Free memory allocated so far on failure
		while (y >= 0)
			free(grid[y--]);
		free(grid);
		return (NULL);
	}

	// Copy the row data
	snprintf(grid[y], size.x + 1, "%s", zone[y]);
	return (allocate_memory(grid, size, y + 1)); // Move to the next row
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	// Allocate memory for the grid
	char **grid = allocate_memory((char **)malloc(size.y * sizeof(char *)), size, 0);
	if (!grid)
		return (1);

	// Print the original grid
	printf("Original Grid:\n");
	print_grid(grid, size, 0);
	printf("\n");

	// Define the starting point for flood fill
	t_point start = {7, 4};

	// Perform flood fill
	flood_fill(grid, size, start);

	// Print the grid after flood fill
	printf("Grid after flood fill:\n");
	print_grid(grid, size, 0);

	// Free allocated memory for the grid
	while (--size.y >= 0)
		free(grid[size.y]);
	free(grid);

	return (0);
}
