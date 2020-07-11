#!/bin/csh

# Sample .cshrc file
setenv EXINIT 'set smd sw=4 wm=2'
set history=50
set savehist=50
set ignoreeof noclobber
if ($?prompt) then
	set prompt='[\!]$ '
	alias f finger -R
	alias lo logout
endif
