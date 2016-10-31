CC = g++

LOCAL_INCLUDE = include
LOCAL_LIBRARIES = lib
SHADERS_PATH = shaders

QT_PATH      = /home/pancho/Programs/qt/5.7/gcc_64
QT_INCLUDE   = $(QT_PATH)/include
QT_LIB       = $(QT_PATH)/lib
QT_BIN       = $(QT_PATH)/bin
QT_MOC         = $(QT_BIN)/moc

TARGET        = gtframework

INCLUDES         = -I$(LOCAL_INCLUDE) -I$(QT_INCLUDE) -I$(QT_INCLUDE)/QtGui \
                            -I$(QT_INCLUDE)/QtCore -I$(QT_PATH)/mkspecs/linux-g++

LDFLAGS     = -L$(LOCAL_LIBRARIES) -L$(QT_LIB) -lQt5Gui -lQt5Core -lGL -lpthread \
    -lglfw3 -lGLEW -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -ldl -lGL -lm -lpthread -lstdc++ 

SRCPATH         = ./src
BINPATH         = ./bin

DEFINES         = $(shell find $(SRCPATH) -type f -name '*.h')
SOURCES         = $(shell find $(SRCPATH) -type f -name '*.cpp')
OBJECTS         := $(patsubst $(SRCPATH)/%.cpp, $(BINPATH)/%.o, $(SOURCES))
#MOC_SOURCES := $(patsubst $(SRCPATH)/%.cpp, $(SRCPATH)/moc_%.cpp, $(SOURCES))
#MOC_OBJECTS := $(patsubst $(BINPATH)/%.o, $(BINPATH)/moc_%.o, $(OBJECTS))

CXXFLAGS   = $(INCLUDES)
CXXFLAGS  += -O3
CXXFLAGS  += -std=c++0x
CXXFLAGS  += -pg -D_DEBUG -g -Wall -fPIC
CXXFLAGS  += -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED

#SOURCES += $(MOC_SOURCES)
#OBJECTS += $(MOC_OBJECTS)


CXXOBJECTS = $(SOURCES:.cpp=.o)

COPY_SHADERS = $(BINPATH)/vertex.shader $(BINPATH)/fragment.shader

all: bin $(TARGET) $(COPY_SHADERS)

$(TARGET): $(CXXOBJECTS)
	$(CC) $(CXXFLAGS) -o $(BINPATH)/$(TARGET) $(CXXOBJECTS) $(LDFLAGS) $(INCLUDES)

$(BINPATH)/vertex.shader: $(SHADERS_PATH)/vertex.shader
$(BINPATH)/fragment.shader: $(SHADERS_PATH)/fragment.shader
$(BINPATH)/%:
	cp -f $< $@

#$(BINPATH)/%.o: $(SRCPATH)/%.cpp
#	@mkdir -p "$(@D)"
#	$(CC) $(CXXFLAGS) -c $< -o $@

#$(SRCPATH)/moc_%.cpp: $(SRCPATH)/%.h
#	$(QT_MOC) $(DEFINES) $(INCLUDES) $< -o $@

# Generate cc from h via Qt's Meta Object Compiler
# $(SRCPATH)/%.moc.cc: $(SRCPATH)/%.h
#   $(MOC) $(INCLUDES) $< -o $@

# Create bin folder
bin:
	mkdir $(BINPATH)

# Remove bin folder
clean:
	rm -r $(BINPATH)



	# Generate ctags file for all included files (autocomplete and jump to source)
	#tags:
	#	gcc -M $(INCDIRS) $(SOURCES) | \
#		sed -e 's/[\\ ]/\n/g' | \
#		sed -e '/^$$/d' -e '/\.o:[ \t]*$$/d' | \
#		ctags -L - --c++-kinds=+p --fields=+iaS --extra=+q










#TARGET = main
#OBJECTS = src/main.cpp

#target: $(OBJECTS)
#	$(CC) $(CXXFLAGS) $(OBJECTS) -o main $(LDFLAGS)

#all:target



