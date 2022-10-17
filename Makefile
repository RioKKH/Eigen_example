GPP = g++
GPP_OPTIONS = -Wall --pedantic-error
INCLUDE = -I${HOME}/include/eigen/

TARGET = veryBasic transpose svd svd2 svd3

all : ${TARGET}

veryBasic : veryBasic.cpp
	$(GPP) $(GPP_OPTIONS) $(INCLUDE) $< -o $@

transpose : transpose.cpp
	$(GPP) $(GPP_OPTIONS) $(INCLUDE) $< -o $@

svd : svd.cpp
	$(GPP) $(GPP_OPTIONS) $(INCLUDE) $< -o $@

svd2 : svd2.cpp
	$(GPP) $(GPP_OPTIONS) $(INCLUDE) $< -o $@

svd3 : svd3.cpp
	$(GPP) $(GPP_OPTIONS) $(INCLUDE) $< -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o


