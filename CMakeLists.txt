CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(umbc)

SET(CMAKE_CXX_STANDARD 98)

# Modern compiler with 98 ANSI still seems confused about 'NULL'
ADD_DEFINITIONS(-DNULL=0)

ADD_SUBDIRECTORY(ArrayList)
ADD_SUBDIRECTORY(LinkedList)
# ADD_SUBDIRECTORY(BST)
# add_subdirectory(CircularBuffers)
