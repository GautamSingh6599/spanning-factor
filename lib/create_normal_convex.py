#!usr/bin/env python3

"""Create a text file consisting the x and y coordinates of a convex polygon.

Functions
---------
create_convex_rnd
output_text
"""

import math
from random import gauss

def convex_polygon(vert, rad=1):
    """
    Return two lists x, y of point coordinates of a convex polygon.

    Parameters
    ----------
    vert : int
    Number of vertices of the polygon.
    rad : float
        Distance of each point from the origin.
    """
    mu, sigma = 0, math.pi / 3
    agl = []
    while(len(agl) < vert):
        x = gauss(mu, sigma)
        if(abs(x) > math.pi):
            continue
        agl.append(x)
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


VERTICES = 100
RADIUS = 1
NAME = "../temp/convex_normal_polygon_r_1_n_100.txt"
ITERATIONS = 1000

with open(NAME, "a", encoding="utf-8") as file:
    file.write(str(ITERATIONS) + "\n")
for _ in range(ITERATIONS):
    polygon_x, polygon_y = convex_polygon(VERTICES, RADIUS)
    output_text(polygon_x, polygon_y, NAME, VERTICES)
