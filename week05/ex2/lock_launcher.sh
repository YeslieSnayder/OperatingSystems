#!/bin/bash
sh ex2_lock.sh &
wait $!
sh ex2_lock.sh
