#
# SCons build Python script
# use scons

# add the source files that make up the game engine here
engine_sources = Split("""
	Surface.cpp
	VirtualScreen.cpp
	File.cpp
	Map.cpp
	""")

# add the source files for the game here
game_sources = Split("""
	demo.cpp
	""")

# libraries needed as my system says from allegro-config --libs
# -lalleg-4.2.2 -lm -lXxf86vm -lXcursor -lXpm -lXext -lX11 -lpthread -ldl

allegro_libs = Split("""
	alleg-4.2.2
    m
    Xxf86vm
    Xcursor
    Xpm
    Xext
    X11
    pthread
    dl
    """)

# make it happen!
Program('whxtctmapviewer', game_sources + engine_sources, LIBS = allegro_libs, CPPPATH = '.')


