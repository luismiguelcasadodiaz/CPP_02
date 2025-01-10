#!/usr/bin/bash
sed 's/${CLASS_NAME}/'$1'/g' canonical_class_template.hpp |tee $1.class.hpp
sed 's/${CLASS_NAME}/'$1'/g' canonical_class_template.cpp |tee $1.class.cpp
c++ -std=c++98 -Werror -Wall -Wextra $1.class.cpp

