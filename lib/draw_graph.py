"""
Returns a .png of the triangulated polygon.

Functions
---------
"""

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
        for line in lines[1:]:
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
        plt.fill(triangle_x, triangle_y, facecolor="none", edgecolor="blue")
    plt.text(triangles[0][0][0], triangles[0][1][0], f"Spanning Ratio: {span}")
    plt.savefig("temp/triangulated_polygon.png")


NAME = "temp/triangulated_polygon.txt"
spanning_ratio, coordinates = triangulated(NAME)
draw_graph(coordinates, spanning_ratio, 10)
