all: convex draw_convex span permission triangulate graph

convex: lib/create_convex.py
	python3 lib/create_convex.py

draw_convex: temp/convex_polygon.txt
	python3 lib/draw_convex.py

span:
	g++ -std=c++17 -O2 -Wextra src/*.cpp -o bin/span

permission: bin/span
	chmod 777 -R bin/

triangulate: temp/convex_polygon.txt
	bin/SRMWP < temp/convex_polygon.txt > temp/triangulated_polygon.txt

graph: temp/triangulated_polygon.txt
	python3 lib/draw_graph.py

clean:
	rm -rf temp/convex_polygon.txt temp/convex_polygon.png temp/triangulated_polygon.txt temp/triangulated_polygon.png bin/SRMWP
