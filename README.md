# Tulip lavout conversion plugin

## Description

These plugins allow to convert a LayoutProperty to a DoubleVectorProperty and vice versa.

## Build

Launch one of the CMake project configuration tool and select your build directory. Set the CMAKE_MODULE_PATH variable to the location of the FindTULIP.cmake file (should be &lt;tulip_install_dir&gt;/share/tulip).

More informations [here](http://tulip.labri.fr/TulipDrupal/?q=node/1481).

## Use

Both plugins need the following parameters:

 * _{source|target}Layout_: the layout to convert from (or to).
 * _{target|source}Doublevector_: the DoubleVectorProperty to convert to (or from).
 * _2D_: a boolean indicating if we want to restrict the process to 2D coordinates (default is 3D).
