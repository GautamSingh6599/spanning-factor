"""
Returns a .png of the triangulated polygon.

Functions
---------
"""

import matplotlib.pyplot as plt
import argparse


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
        max_span = list(coordinates[-1])
        coordinates.pop()
    return span_ratio, coordinates, max_span


def draw_graph(triangles, span, max_span, size):
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
    plt.fill(max_span[0], max_span[1], facecolor="none", edgecolor="red")
    plt.title(f"Spanning Ratio: {span}")
    plt.axis('off')
    plt.savefig(f"temp/TP_{TYPE}_R{RADIUS}_N{VERTICES}.png")

parser = argparse.ArgumentParser()
parser.add_argument('vertices', type=int, help='The number of Vertices in the Polygon')
parser.add_argument('radius', type=int, help='Radius of the Circle')
parser.add_argument('type', type=str, help='Type of the Polygon')

args = parser.parse_args()

VERTICES = args.vertices
RADIUS = args.radius
TYPE = args.type

NAME = f"temp/TP_{TYPE}_R{RADIUS}_N{VERTICES}.txt"
SIZE = 10
spanning_ratio, coordinates, max_span = triangulated(NAME)
draw_graph(coordinates, spanning_ratio, max_span, SIZE)
