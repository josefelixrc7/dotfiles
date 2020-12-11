# .bash_profile

# Get the aliases and functions
if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

# User specific environment and startup programs

export PATH="$HOME/.cargo/bin:$PATH"

if [[ ! $DISPLAY && $XDG_VTNR -le 6 ]]; then
  exec startx
fi
