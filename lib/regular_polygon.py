#!usr/bin/env python3

"""Creates a text file with coordinates of a regular polygon.

Functions
---------
"""

import math


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
