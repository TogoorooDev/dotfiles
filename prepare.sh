#! /bin/sh
cd ~
rsync -a .config/neofetch .config/polybar .config/bspwm .config/alacritty .config/sxhkd .config/zsh-plugins .zshrc .Xresources .xinitrc dotfiles
