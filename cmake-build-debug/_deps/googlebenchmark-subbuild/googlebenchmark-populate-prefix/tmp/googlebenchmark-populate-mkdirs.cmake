# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/TU Darmstadt/Semester3/lab_1/cmake-build-debug/_deps/googlebenchmark-src"
  "D:/TU Darmstadt/Semester3/lab_1/cmake-build-debug/_deps/googlebenchmark-build"
  "D:/TU Darmstadt/Semester3/lab_1/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix"
  "D:/TU Darmstadt/Semester3/lab_1/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/tmp"
  "D:/TU Darmstadt/Semester3/lab_1/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/src/googlebenchmark-populate-stamp"
  "D:/TU Darmstadt/Semester3/lab_1/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/src"
  "D:/TU Darmstadt/Semester3/lab_1/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/src/googlebenchmark-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/TU Darmstadt/Semester3/lab_1/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/src/googlebenchmark-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/TU Darmstadt/Semester3/lab_1/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/src/googlebenchmark-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
