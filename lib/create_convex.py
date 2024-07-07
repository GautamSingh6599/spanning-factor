#!usr/bin/env python3

"""Create a text file consisting the x and y coordinates of a convex polygon.

Functions
---------
create_convex_rnd
output_text
"""

import math
import random
import argparse
from regular_polygon import regular_polygon


def convex_polygon(vert, rad=2):
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

parser = argparse.ArgumentParser()
parser.add_argument('vertices', type=int, help='The number of Vertices in the Polygon')
parser.add_argument('radius', type=int, help='Radius of the Circle')
parser.add_argument('type', type=str, help='Type of the Polygon')

args = parser.parse_args()

VERTICES = args.vertices
RADIUS = args.radius
TYPE = args.type
NAME = f"temp/Polygon_{TYPE}_R{RADIUS}_N{VERTICES}.txt"

with open(f"temp/TP_{TYPE}_R{RADIUS}_N{VERTICES}.txt", "x") as file:
    pass

with open(NAME, "a", encoding="utf-8") as file:
    if TYPE == "regular":
       polygon_x, polygon_y = regular_polygon(VERTICES, RADIUS)
       output_text(polygon_x, polygon_y, NAME, VERTICES)
    if TYPE == "convex":
       polygon_x, polygon_y = convex_polygon(VERTICES, RADIUS)
       output_text(polygon_x, polygon_y, NAME, VERTICES)
