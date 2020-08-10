#!/bin/bash

################# check binary #################
tmux_path=$(command -v tmux)
if [ -z "$tmux_path" ];then echo "tmux not found";exit;fi

adb_path=$(command -v adb)
if [ -z "$adb_path" ];then echo "adb not found";exit;fi

gniht_path=$(command -v r_gnirehtet)
if [ -z "$gniht_path" ];then echo "r_gnirehtet not found";exit;fi

scrcpy_path=$(command -v scrcpy)
if [ -z "$scrcpy_path" ];then echo "scrcpy not found";exit;fi

################# start new tmux session #################
session="gnirehtet"
tmux new -d -s $session

################# split window #################
tmux split-window -v -t $session

################# start programs in each pane #################
sudo adb start-server
tmux send-keys -t $session:0.0 'r_gnirehtet' C-m
tmux send-keys -t $session:0.1 'scrcpy -S -m1024' C-m

################# start programs in each pane #################
tmux attach -t $session
