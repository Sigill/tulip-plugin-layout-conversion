# Tulip lavout conversion plugin

## Description

These plugins allow to convert a LayoutProperty to a DoubleVectorProperty and vice versa.

## Build

Launch one of the CMake project configuration tool and select your build directory. Set the CMAKE_MODULE_PATH variable to the location of the FindTULIP3.cmake file (should be &lt;tulip_install_dir&gt;/share/tulip).

More informations [here](http://tulip.labri.fr/TulipDrupal/?q=node/1481).

## Use

Both plugins are located in the "Algorithm/General/Layout conversion" menu.

Both plugins need the following parameters:

 * _{source|target}Layout_: the layout to convert from (or to).
 * _{target|source}Doublevector_: the DoubleVectorProperty to convert to (or from).
 * _2D_: a boolean indicating if we want to restrict the process to 2D coordinates (default is 3D).

## LICENSE

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.
