CXX=g++
CXXFLAGS=-std=c++17

TARGET=slurm-log-seq

$(TARGET):src/main.cpp
	$(CXX) $< -o $@ $(CXXFLAGS)
  
clean:
	rm -f $(TARGET)
