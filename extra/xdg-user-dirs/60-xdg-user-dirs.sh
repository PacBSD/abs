#!/bin/sh

# Set up user directories like ~/Destop and ~/Music
if [ -x /usr/bin/xdg-user-dirs-update ]; then
  /usr/bin/xdg-user-dirs-update
fi
