# Rasterizer

<img src="https://cs184.eecs.berkeley.edu/cs184_sp16_content/article_images/3_1.jpg" width="800px" align="middle"/>

I have implemented a rasterizer, which includes features like supersampling, hierarchical transforms, and texture mapping with antialiasing. This rasterizer is a functional vector graphics renderer that can take in modified SVG (Scalable Vector Graphics) files, which are widely used on the internet.

<img src="https://cs184.eecs.berkeley.edu/cs184_sp16_content/article_images/3_7.jpg" width="800px" align="middle"/>

## Using the GUI

You can run the executable with the command

    ./draw [path to svg file/folder to render]
    
Example:
    
    ./draw ../svg/basic/test1.svg

A flower should show up on your screen. You are able to change the viewpoint by dragging your mouse to pan around or scrolling to zoom in and out. Here are all the keyboard shortcuts available:

|Key | Action|
|:-----:|------|
|`' '`  | return to original viewpoint|
|`'-'`  | decrease sample rate|
|`'='` | increase sample rate|
|`'Z'` | toggle the pixel inspector|
|`'P'` | switch between texture filtering methods on pixels|
|`'L'` | switch between texture filtering methods on mipmap levels|
|`'S'` | save a *png* screenshot in the current directory|
| `'1'-'9'`  | switch between svg files in the loaded directory|

The argument passed to `draw` can either be a single file or a directory containing multiple *svg* files, as in

    ./draw ../svg/basic/

If you load a directory with up to 9 files, you can switch between them using the number keys 1-9 on your keyboard.

The following website goes into major detail about the implementation and results of the rasterize: https://kevin-arias.github.io/Rasterizer/

