## Building
In terminal, after installing all the necessary libraries, build using-
```bash
build build.bash
```

## Starting Game
In the game directory run - 
```bash
./Main.out
# don't run main.out or game.out
```

## Common Problem
If you are getting the below error after running Main.out(again Main, not main.out or game.out) - 
```bash
INFO: Initializing raylib 5.1-dev
INFO: Platform backend: DESKTOP (GLFW)
INFO: Supported raylib modules:
INFO:     > rcore:..... loaded (mandatory)
INFO:     > rlgl:...... loaded (mandatory)
INFO:     > rshapes:... loaded (optional)
INFO:     > rtextures:. loaded (optional)
INFO:     > rtext:..... loaded (optional)
INFO:     > rmodels:... loaded (optional)
INFO:     > raudio:.... loaded (optional)
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:39:34: string literal is not a valid UTF-8 string
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:40:29: string literal is not a valid UTF-8 string
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:41:29: string literal is not a valid UTF-8 string
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:42:29: string literal is not a valid UTF-8 string
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:43:29: string literal is not a valid UTF-8 string
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:44:27: string literal is not a valid UTF-8 string
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:45:27: string literal is not a valid UTF-8 string
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:46:27: string literal is not a valid UTF-8 string
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:47:27: string literal is not a valid UTF-8 string
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:48:29: string literal is not a valid UTF-8 string
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:49:29: string literal is not a valid UTF-8 string
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:49:29: too many errors
xkbcommon: ERROR: /usr/share/X11/locale/iso8859-1/Compose:49:29: failed to parse file
WARNING: GLFW: Error: 65544 Description: Wayland: Failed to create XKB compose table
FATAL: PLATFORM: Failed to initialize graphics device
```

You can resolve it by running - 
```bash
export LANG=en_IN.UTF-8
export LC_ALL=en_IN.UTF-8
```

Now try running Main.out

## screenshots
![alt text](https://drive.google.com/file/d/1oPEY6GO0besM_FRw0XJbX5OpoJV04YxC/view?usp=sharing)
![alt text](https://drive.google.com/file/d/1IHdFv8jHjJ_w7iSwD3KNnamVU-clfvS8/view?usp=sharing)
