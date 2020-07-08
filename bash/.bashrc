# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific environment
if ! [[ "$PATH" =~ "$HOME/.local/bin:$HOME/bin:" ]]
then
    PATH="$HOME/.local/bin:$HOME/bin:$PATH"
fi
export PATH

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

# User specific aliases and functions
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

# Git
function gitbranch() 
{
    git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/(\1)/'
}

# Colors
PS1="\[\e[92m\]["
PS1=$PS1"\[\e[32m\]\u"
PS1=$PS1"\[\e[33m\]@"
PS1=$PS1"\[\e[32m\]\h:"
PS1=$PS1"\[\e[36m\]\W "
PS1=$PS1"\[\e[1m\]\$(gitbranch)"
PS1=$PS1"\[\e[92m\]]\$"
PS1=$PS1"\[\e[0;00m\] "
