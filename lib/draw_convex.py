#!usr/bin/env python3
"""Return an image of a triangulated convex polygon.

FUNCTIONS
---------
"""

import matplotlib.pyplot as plt


def access_polygon(fn):
    """
    Return two lists x, y of point coordinates of a convex polygon.

    Parameters
    ----------
    fn : str
        Name of the file which contains the coordinates.
    """
    x = []
    y = []
    with open(fn, encoding="utf-8") as file:
        lines = file.readlines()
        for line in lines[1:]:
            a = line.strip().split()
            x.append(float(a[0]))
            y.append(float(a[1]))
    return x, y


def make_plot(x, y, size):
    """
    Create and save a polygon plot as a picture.

    Parameters
    ----------
    x : list
        The x coordinates of the convex polygon
    y : list
        The y coordinates of the convex polygon
    """
    plt.figure(figsize=(size, size))
    plt.axis("equal")
    plt.fill(x, y, facecolor="none", edgecolor="blue")
    plt.savefig("../temp/convex_polygon_r_1_n_10.png")


FILE = "../temp/convex_normal_polygon_r_1_n_10.txt"
pol_x, pol_y = access_polygon(FILE)
make_plot(pol_x, pol_y, 15)
