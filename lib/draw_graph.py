"""
Returns a .png of the triangulated polygon.

Functions
---------
"""

from create_convex import RADIUS, VERTICES, TYPE
import matplotlib.pyplot as plt


def triangulated(fn):
    """
    Return the x, y coordinates of a triangulated polygon and it's stretch factor.

    Parameters
    ----------
    fn : str
        Name of the file to open.
    """
    coordinates = []
    with open(fn, "r", encoding="utf-8") as file:
        span_ratio = file.readline()
        lines = file.readlines()
        for line in lines:
            a = line.strip().split()
            x = [float(i) for i in a[0::2]]
            y = [float(i) for i in a[1::2]]
            coordinates.append([x, y])
    return span_ratio, coordinates


def draw_graph(triangles, span, size):
    """
    Draw the triangulated polygon.

    Parameters
    ----------
    triangles : list
        x, y coordinates of the triangles.
    span : float
        Spanning ratio of the triangulated polygon.
    size : float
        Size of the figure.
    """
    plt.figure(figsize=(size, size))
    plt.axis("equal")
    for triangle in triangles:
        triangle_x = triangle[0]
        triangle_y = triangle[1]
        plt.fill(triangle_x, triangle_y, facecolor="none", edgecolor="black")
    plt.title(f"Spanning Ratio: {span}")
    plt.savefig(f"../temp/TP_{TYPE}_R{RADIUS}_N{VERTICES}.png")

NAME = f"../temp/TP_{TYPE}_R{RADIUS}_N{VERTICES}.txt"
SIZE = 10
spanning_ratio, coordinates = triangulated(NAME)
draw_graph(coordinates, spanning_ratio, SIZE)
