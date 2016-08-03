# See <http://standards.freedesktop.org/basedir-spec/basedir-spec-latest.html>.
# License: public domain.

setenv XDG_DATA_HOME "$HOME/.local/share"
setenv XDG_CONFIG_HOME "$HOME/.config"
setenv XDG_DATA_DIRS "/usr/local/share:/usr/share"
setenv XDG_CONFIG_DIRS "/etc/xdg"
setenv XDG_CACHE_HOME "$HOME/.cache"

if ( ! $?XDG_RUNTIME_DIR ) then
    setenv XDG_RUNTIME_DIR "/tmp/runtime-dir-$uid"
    if ( ! -d "$XDG_RUNTIME_DIR" ) then
        mkdir -p "$XDG_RUNTIME_DIR"
        chmod 0700 "$XDG_RUNTIME_DIR"
    endif
endif
