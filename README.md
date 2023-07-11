# Movement-Part-1
CS 4150/5150: Game Artificial Intelligence Assignment #1 Movement, Part 1


Steps to start:
1.If you already have a sample code with CMakeLists.txt file, then click File|Open and point CLion to the top-level CMakeLists.txt file, then choose Open as Project. 
2.You can also use MakeFiles and open them as projects. 
3.Creating a New Project:
a.Select File | New Project from the main menu or click New Project on the welcome screen. 
b.Set the type of your project: C or C++, an executable or a library. 
c.Provide the root folder location and select the language standard. 
d.CLion creates a new CMake project and fills in the top-level CMakeLists.txt.

4.Open the existing code base: 
a.Select File | Open from the main menu and select the project folder.
b.Create a CMakeLists.txt with basic instructions to run the project. Check this: https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html
c.The IDE will compile the project, and you can run it as shown in the images below. 



Input:
The grid will be specified as text file that looks something like this:
11X11
11X11
1XX11
11111
each character represents a single tile as follows.
‘X’ – impassible tile
[1..9] – passible tile.  The cost of traversing the tile is given by the integer value (1 is easiest, 9 is hardest).  
In addition, your program should accept start and destination coordinates as an x and y value.  (0,0) is the bottom left grid tile, so in this case if you wanted to go from the top left tile to the top right tile the coordinates would be (0,3) and (4,3).
Finally, you should provide options to set the output mode.  Output mode can be:
Standard: just display the path
Expanded: display the path and all expanded nodes 
All: display the path, all expanded nodes, and all other touched nodes
Output:
Your path planner should output the solution to the screen, along with the elapsed time.  The solution should look like the input, but with ‘s’ for the start node, ‘d’ for the destination node, ‘+’ for other nodes along the path, ‘e’ for expanded nodes (if the mode is “Expanded” or “All”), and ‘t’ for all other touched nodes (if the mode is “All”).  So for example, if the mode was “All” and the map and coordinates are the ones given as examples above, your output would appear something like this:

seXtd
+eXt+
+XX+t
t++tt
Elapsed Time: 0.00187455 seconds
Testing Your Code:
Project1.txt contains a sample map, which I created using Notepad.  I strongly recommend creating maps of your own that test as many different edge cases as you can think of, including large and difficult maps.
