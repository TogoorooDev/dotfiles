#! /bin/sh
cd ~
rsync -a .config/neofetch .config/polybar .config/bspwm .config/alacritty .config/sxhkd .config/zsh-plugins .zshrc .Xresources .xinitrc dotfiles

# Void Package Lists
xbps-query -l | grep "ii" | cut -d" " -f 2 > void-packages.lst
