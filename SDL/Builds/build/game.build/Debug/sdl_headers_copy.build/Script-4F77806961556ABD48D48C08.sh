#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/jamespearce/gamecube/SDL/Builds/SDL2
  /usr/local/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/jamespearce/gamecube/SDL/SDL2/include/SDL_vulkan.h /Users/jamespearce/gamecube/SDL/Builds/SDL2/include/SDL_vulkan.h
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/jamespearce/gamecube/SDL/Builds/SDL2
  /usr/local/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/jamespearce/gamecube/SDL/SDL2/include/SDL_vulkan.h /Users/jamespearce/gamecube/SDL/Builds/SDL2/include/SDL_vulkan.h
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/jamespearce/gamecube/SDL/Builds/SDL2
  /usr/local/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/jamespearce/gamecube/SDL/SDL2/include/SDL_vulkan.h /Users/jamespearce/gamecube/SDL/Builds/SDL2/include/SDL_vulkan.h
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/jamespearce/gamecube/SDL/Builds/SDL2
  /usr/local/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/jamespearce/gamecube/SDL/SDL2/include/SDL_vulkan.h /Users/jamespearce/gamecube/SDL/Builds/SDL2/include/SDL_vulkan.h
fi

