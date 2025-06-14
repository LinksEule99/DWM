#!/bin/bash
#
# Refer to:
#   https://github.com/dylanaraps/pywal

# Set wal color scheme on load if:
#    - a cached color scheme exists and
#    - we are in an interactive shell and
#    - we are not in a login shell
#
# This to avoid setting the color scheme when ssh-ing into the
# box as well as when using other tools like scp. 

if [ -f ${XDG_CACHE_HOME:-~/.cache}/wal/sequences ]; then
	if [[ $- == *i* ]]; then
		if [ $ZSH_VERSION ]; then
			[[ ! -o login ]] && LOAD_SEQUENCES=1
		else
			shopt -q login_shell || LOAD_SEQUENCES=1
		fi

		if [[ ! -z $LOAD_SEQUENCES ]]; then
			(cat ${XDG_CACHE_HOME:-~/.cache}/wal/sequences &)
			unset LOAD_SEQUENCES
			clear
		fi
	fi
fi
