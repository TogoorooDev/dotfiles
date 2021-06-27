#! /bin/sh

rsync -a alacritty bspwm polybar zsh-plugins neofetch sxhkd ~/.config/
rsync -a .Xresources .xinitrc .zshrc ~/
