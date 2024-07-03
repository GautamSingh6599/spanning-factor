#!usr/bin/env python3

"""Creates a text file with coordinates of a regular polygon.

Functions
---------
"""

import math
from create_convex import NAME, VERTICES


def regular_polygon(vert, rad=1):
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
    diff = 2 * math.pi / vert
    theta = 0
    for _ in range(vert):
        agl.append(theta)
        theta += diff
    x = [rad * math.cos(i) for i in agl]
    y = [rad * math.sin(i) for i in agl]
    return x, y


def output_text(lst_x, lst_y, fn, vert):
    """
    Output the coordinates into a text file.

    Parameters
    ----------
    lst_x : list
        x coordinates of the regular polygon.
    lst_y : list
        y coordinates of the regular polygon
    fn : str
        Name of the text file.
    vert : int
        Number of vertices in the polygon.
    """
    with open(fn, "a", encoding="utf-8") as file:
        file.write(str(vert) + "\n")
        for i in range(vert):
            file.write(str(lst_x[i]) + " " + str(lst_y[i]) + "\n")


polygon_x, polygon_y = regular_polygon(VERTICES, 2)
output_text(polygon_x, polygon_y, NAME, VERTICES)
