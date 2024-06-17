Quick-WPI 0.18.2 by J”rg Skottke 2001

This quick & dirty program creates a basic WPI archive
for programs that only need a single executable. You can
install dll's too, no program object will be created then.


Usage:

qwpi <basename> [-i] [ENTER]

<basename> must be the name of the EXE file - but without extension.
<basename> will be the name of the desktop object.
That's it. All files in the current directory are included
into the WPI-Archive recursively
-i specifies interactive mode, allowing to enter some data.

Requirements:
- WarpIN installed
- wic.exe in PATH and LIBPATH
- qwpi.exe in PATH*
*When using QWPI as drag&drop target, this is not required. Please
enter %**N (and eventually -i) into the parameter field of the
Quick-WPI object

Features:
- you just provide a name, everything else is automatic
- creates a program object if the <basename>.EXE file is found
- looks for README, README.TXT, FILE_ID.DIZ etc. and includes them
- supports a definition file (see changes in v 0.17.0 below)
- support for program versioning in interactive mode

Limitations:
- only one WPI package can be created
- no REXX

Attention:
Do not run the program from within the directory that goes
into the archive. WIC will fail without telling you and the
archive is unuseable.

Disclaimer:
The program comes with no warranty at all. It is merely
a test for my own purposes.
If you use the program, keep in mind that you might
violate the rights of others.
WarpIN is a Netl@bs project (http://www.netlabs.org)

License:
GPL, even though i'm pretty sure nobody wants this code
in it's current state.


J”rg Skottke
2001/08/10, Hamburg (Germany)


Changes in version 0.15.0:
- Author and program version can be entered by specifying
  the "-i" parameter (or something else, just looks for
  an existing second command line parameter.
- More "RADME"-type files are recognized


Changes in version 0.17.0:
- The title of the WPS object can now be specified in
  interactive mode and thereby differ from the <basename>
- Looks for a file named QUICKWPI.QWP which contains his:

Author
Title of WPS object
Version
Major revision
Minor revision
Default installation path

  If this file is found, it will be used. Always.
  It is a plain text file, beginning on the first line,
  spaces are allowed for author and title.
  I call it an "archive definition file"
- More "README"-type files added.
- Messages have been modified.
- Compiler optimizations invoked.
- Added WarpIN icon to be associated with QWPI-object


Changes in version 0.18.2:
- .wis file is created in parent directory and no longer
  part of the extracted archive (i have to do this with
  the archive definition file as well)
- An existing archive is deleted before a new one is
  created (the archive tended to be corrupted when an
  existing archive was just overwritten)
- Formatted parts of the screen-output
- Added some errormessages for diagnosis
- Most variables are created on the heap instead of the
  Stack


