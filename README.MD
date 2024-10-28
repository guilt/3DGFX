# README

Please read **all** of this **Documentation**.

You should read [Library Design](DOC/DESIGN.MD), [Description of the Layout](DOC/DESC.MD)
and [Header Description](DOC/HEADERS.MD).

This Library is released with an accompanying [License](LICENSE.MD) which you
agree to, when using this Library. There is also a [File ID Descriptor](FILE_ID.DIZ)
used for Archival/Packaging.

## BUILDING

On a Modern Computer, you could **Cross-Compile** this with [OpenWatcom C++](https://github.com/open-watcom/open-watcom-v2/).
More instructions on the [OpenWatcom GitHub Wiki](https://github.com/open-watcom/open-watcom-v2/wiki/OW-tools-usage-with-CMake).

```shell
cmake -G "Watcom WMake" -D CMAKE_SYSTEM_NAME=DOS -D CMAKE_SYSTEM_PROCESSOR=I86 -D CMAKE_C_FLAGS="-ml -k8192" -D CMAKE_CXX_FLAGS="-ml -k8192" -S . -B Build
cmake --build Build
```

On **DOS** environments such as **DOSBox-X** or the real thing, pick your Compiler in [the Build Script](BUILD.BAT)
and then Run:

```shell
BUILD.BAT
```

## DEMO

Once built, you should be able to execute them:

```shell
RUNDEMO.BAT
```

## ACKNOWLEDGMENTS

I thank **David Brackeen** and **Johan Peitz** for their help and tutorials on
VGA Programming.

I thank **Jerome St - Louis** For Immense Help on the Triangle Filling, HSR and 
Z-Buffering Algorithms. Thanks go to **Jordan Hargraphix** for his
[SVGA BGI Driver](https://github.com/jharg93/SvgaBGI). I would also like to thank **Diana Gruber** for her Excellent Book -
[Action Arcade Adventure Set](https://archive.org/details/action-arcade-adventure-set).

I thank my **Math Teachers** **Srinivasan** and **Radha Venkatesh** for their Invaluable
Guidance and Support. A Special mention here must be made of my Computer Science Teacher
**K. N. Rukmini**, for making me go through the Oceans of C and C++ with ease. 

I thank you for getting this Code.

## FEEDBACK

If you happen to have any suggestions/improvements on this Code,
**E-Mail me** or raise a **Pull Request**. Visit the GitHub Repository
for more Updates.

Do let me know about what you feel about this release of this
code. This was released in **2001** and computer graphics
has come along very far.

All feedback welcome!

* Author: Karthik Kumar Viswanathan
* Web   : http://karthikkumar.org
* Email : me@karthikkumar.org