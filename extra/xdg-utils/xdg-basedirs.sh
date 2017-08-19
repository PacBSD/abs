# See <http://standards.freedesktop.org/basedir-spec/basedir-spec-latest.html>.
# License: public domain.

: ${XDG_DATA_HOME:=$HOME/.local/share}
: ${XDG_CONFIG_HOME:=$HOME/.config}
: ${XDG_DATA_DIRS:=/usr/local/share:/usr/share}
: ${XDG_CONFIG_DIRS:=/etc/xdg}
: ${XDG_CACHE_HOME:=$HOME/.cache}

if [ -z "$XDG_RUNTIME_DIR" ]; then
    XDG_RUNTIME_DIR="/var/run/user/runtime-dir-$UID"
    if ! [ -d "$XDG_RUNTIME_DIR" ]; then
        mkdir -p "$XDG_RUNTIME_DIR"
        chmod 0700 "$XDG_RUNTIME_DIR"
    fi
fi
