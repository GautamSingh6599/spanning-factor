#!usr/bin/env python3

"""Create a text file consisting the x and y coordinates of a convex polygon.

Functions
---------
create_convex_rnd
output_text
"""

import math
import random


def convex_polygon(vert, rad=8):
    """
    Return two lists x, y of point coordinates of a convex polygon.

    Parameters
    ----------
    vert : int
    Number of vertices of the polygon.
    rad : float
        Distance of each point from the origin.
    """
    agl = []
    for _ in range(vert):
        agl.append(random.uniform(0, 2 * math.pi))
    agl.sort()
    x = [rad * math.cos(i) for i in agl]
    y = [rad * math.sin(i) for i in agl]
    return x, y


def output_text(lst_x, lst_y, fn, vert):
    """
    Output the coordinates into a text file.

    Parameters
    ----------
    lst_x : list
        x coordinates of the convex polygon.
    lst_y : list
        y coordinates of the convex polygon
    fn : str
        Name of the text file.
    vert : int
        Number of vertices in the polygon.
    """
    with open(fn, "a", encoding="utf-8") as file:
        file.write(str(vert) + "\n")
        for i in range(vert):
            file.write(str(lst_x[i]) + " " + str(lst_y[i]) + "\n")


VERTICES = 6
RADIUS = 1
NAME = "../temp/convex_polygon_r_1_n_6.txt"
ITERATIONS = 1

# with open(NAME, "a", encoding="utf-8") as file:
#     file.write(str(ITERATIONS) + "\n")
for _ in range(ITERATIONS):
    polygon_x, polygon_y = convex_polygon(VERTICES, RADIUS)
    output_text(polygon_x, polygon_y, NAME, VERTICES)
