#!/bin/bash
wal -R



vol(){
	vol="$(pactl list sinks | grep '^[[:space:]]Volume:' | head -n $(( $SINK + 1 )) | tail -n 1 | sed -e 's,.* \([0-9][0-9]*\)%.*,\1,')%"
	echo -e "奄 $vol"
}

dte(){
  dte="$(date +"%A, %B %d")"
  echo -e " $dte"
}

tm(){
  tm="$(date +"%H:%M")"
  echo -e " $tm"
}

upd(){
  upd=`checkupdates | wc -l`
  echo -e " $upd"
}

#bat () { 
#	bat="$(acpi | awk '{print $4}' | sed s/,//)"
#	echo -e " $bat"
#}


while true; do
     xsetroot -name "| Volume: $(vol) | Updates: $(upd) | $(bat) | Date: $(dte) | Time: $(tm) |"
     sleep 3s
done & 

