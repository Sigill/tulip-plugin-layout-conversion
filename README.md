# Tulip lavout conversion plugin

## Description

These plugins allow to convert a LayoutProperty to a DoubleVectorProperty and vice versa.

They actually only support Tulip version 3.8.

## Build

Launch one of the CMake project configuration tool and select your build directory. Set the CMAKE_MODULE_PATH variable to the location of the FindTULIP3.cmake file (should be <tulip_install_dir>/share/tulip) and the TULIP_DIR variable to <tulip_install_dir>.

More informations [here](http://tulip.labri.fr/TulipDrupal/?q=node/1481).

## Use

Both plugins are located in the "Algorithm/General/Layout conversion" menu.

Both plugins need the following parameters:

 * _{source|target}Layout_: the layout to convert from (or to).
 * _{target|source}Doublevector_: the DoubleVectorProperty to convert to (or from).
 * _2D_: a boolean indicating if we want to restrict the process to 2D coordinates (default is 3D).
