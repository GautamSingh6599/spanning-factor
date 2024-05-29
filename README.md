# Convex polygon generator and spanning ratio calculator

## Overview

This program generates a convex polygon with a specified number of vertices randomly and calculates its spanning ratio.
The spanning ratio, or stretch factor, of H is the smallest constant t for which H is a t-spanner of G.
Basically, it's the maximum value of ratio of the euclidean distance between them and 

## Features

- **Random Convex Polygon Generation**: Generates a convex polygon with a user-defined number of vertices.
- **Spanning Ratio Calculation**: Computes the spanning ratio of the generated polygon.

## Requirements

- Python 3.x
- g++ 13.2.1
- Libraries: matplotlib

You can install the required libraries using pip:

```sh
pip install matplotlib
```

## Usage

1. **Clone the Repository**

   ```sh
   git clone https://github.com/GautamSingh6599/spanning-factor.git
   cd spanning-factor
   ```

2. **Run the Program**

   ```sh
   make
   ```

3. **Output**

   The program outputs the following:
   - Displays a visual representation of the generated convex polygon.
   - The spanning ratio of the polygon printed on the png.

## Example

To generate a convex polygon with 8 vertices and find its spanning ratio,
change `VERTICES = 8` in the file `lib/create_covex.py`.

```sh
make
```

You can see the generated polygon in the file `temp/convex_polygon.txt`. There
is a visualisation of the convex polygon in the `temp` folder. There be a visualisation of the triangulation of the polygon and the spanning factor.

```sh
make clean
```

Always do this after you want to rerun `make`. Run `make clean` to remove all
generated files.

## Code structure

- `src/spanning-ratio.cpp`: Contains functions for calculating the spanning ratio.
- `lib/create_convex.py`: Contains functions for generating the convex polygon.
- `lib/draw_polygon.py`: Contains functions to draw the generated polygon.
- `lib/draw_graph.py`: Contains functions to draw the triangulated polygon.
- `README.md`: This file.

## Detailed explanation

### Convex polygon generation

The convex polygon is generated using the following steps:
1. Generate a set of random angles from 0 to 2 * pi.
2. Sort the angles.
3. Convert the angles to a coordinate.

### Spanning ratio calculation

Calculate the spanning ratio by:
1. Calculate the minimum weight triangulation of the polygon.
2. Calculate the shortest_path_matrix with Floyd-Warshall algorithm.
3. Calculate the spanning ratio by dividing the shortest path with the
   euclidean distance between them. The spanning ratio is the largest value in
   the matrix.

## Contributing

Contributions are welcome. Please fork the repository and create a pull request with your changes.

## Contact

For any issues or questions, please open an issue on GitHub or contact [gautam6599123@gmail.com].
