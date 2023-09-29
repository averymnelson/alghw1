# PROJECT_DIR=.

# CFLAGS=-I${PROJECT_DIR}/include/
# CC=gcc
# CXX=g++
# LDFLAGS=''

# # Using OpenCV for Visualization
# OPENCV=0
# OPENCV4=0

# ifeq ($(OPENCV), 1)
# 	ifeq ($(OPENCV4), 0)
# 		LDFLAGS+=  `pkg-config --libs opencv`
# 		CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv`
# 	else
# 		LDFLAGS+= -std=c++11 `pkg-config --libs opencv4`
# 		CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv4`
# 	endif
# endif

# SRC_DIR=${PROJECT_DIR}/src


# all: compile
# 	./bin/main

# compile: ${SRC_DIR}/linked_list.cpp ${SRC_DIR}/queue.cpp ${SRC_DIR}/stack.cpp ${SRC_DIR}/graph.cpp ${SRC_DIR}/bfs.cpp ${SRC_DIR}/rdfs.cpp ${SRC_DIR}/dfs.cpp ${SRC_DIR}/articulation_and_bridge.cpp ${SRC_DIR}/main.cpp
# 	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/main  

PROJECT_DIR=.

MINGW_BIN=C:/Homework/mingw64/bin
CFLAGS=-I${PROJECT_DIR}/include/
CC=${MINGW_BIN}/gcc.exe
CXX=${MINGW_BIN}/g++.exe
OPENCV_DIR=C:/Homework/opencv/build/install

# Using OpenCV for Visualization
OPENCV=1
ifeq ($(OPENCV), 1)
	CFLAGS+= -DOPENCV=1 -I${OPENCV_DIR}/include -std=c++11
	LDFLAGS+= -L${OPENCV_DIR}/x64/mingw/bin -lopencv_imgcodecs3413 -lopencv_core3413 -lopencv_highgui3413 -lopencv_imgproc3413
endif

SRC_DIR=${PROJECT_DIR}/src

all: compile
	./bin/main.exe 

compile: ${SRC_DIR}/linked_list.cpp ${SRC_DIR}/queue.cpp ${SRC_DIR}/stack.cpp ${SRC_DIR}/graph.cpp ${SRC_DIR}/bfs.cpp ${SRC_DIR}/rdfs.cpp ${SRC_DIR}/dfs.cpp ${SRC_DIR}/articulation_and_bridge.cpp ${SRC_DIR}/main.cpp
	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/main.exe  

