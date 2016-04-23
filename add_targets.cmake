#
# add targets
#
file(GLOB srcs "*.cc")

foreach(file ${srcs})
    message("file: " ${file})
    string(REGEX REPLACE ".*/(.*).cc" "\\1" target ${file})
    add_executable(${target} ${file})
endforeach(file ${srcs})
