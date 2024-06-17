Quick-WPI 0.10 by J”rg Skottke 2001

This quick & dirty program creates a basic WPI archive
for programs that only need a single executable. You can
install dll's too, no program object will be created then.


Usage:

qwpi <basename> [ENTER]

<basename> must be the name of the EXE file - but without extension.
<basename> will be the name of the desktop object.
That's it. All files in the current directory are included
into the WPI-Archive recursively

Requirements:
- WarpIN installed
- wic.exe in PATH and LIBPATH
- qwpi.exe in PATH

Features:
- you just provide a name, everything else is automatic
- creates a program object if the <basename>.EXE file is found
- looks for README, README.TXT, FILE_ID.DIZ and includes them

Limitations:
- only one WPI package can be created
- program versioning is not supported
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
GPL, even though i'm pretty sure nobody wants this code.


J”rg Skottke
2001/08/10, Hamburg (Germany)
