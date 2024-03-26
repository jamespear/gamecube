#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/jamespearce/gamecube/SDL/Builds/JUCE/tools
  make -f /Users/jamespearce/gamecube/SDL/Builds/JUCE/tools/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/jamespearce/gamecube/SDL/Builds/JUCE/tools
  make -f /Users/jamespearce/gamecube/SDL/Builds/JUCE/tools/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/jamespearce/gamecube/SDL/Builds/JUCE/tools
  make -f /Users/jamespearce/gamecube/SDL/Builds/JUCE/tools/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/jamespearce/gamecube/SDL/Builds/JUCE/tools
  make -f /Users/jamespearce/gamecube/SDL/Builds/JUCE/tools/CMakeScripts/ReRunCMake.make
fi

