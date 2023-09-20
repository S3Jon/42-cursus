#!/bin/bash
# ---- Arquitectura + vrsion ----
ARC=$(uname -a)
# ---- CPU fisicas ----
pCPU=$(cat /proc/cpuinfo | grep "physical id" | sort | uniq | wc -l)
# ---- CPU virtuales ----
vCPU=$(cat /proc/cpuinfo | grep "^processor" | wc -l)
# ---- Uso de memoria ----
#Usada
memUS=$(free -m | grep Mem | awk '{print $3}')
#Total
memTO=$(free -m | grep Mem | awk '{print $2}')
#Porcentaje
memUPERC=$(free -m | grep Mem | awk '{printf("%.2f%%"), $3 / $2 * 100}')
#---- Disk usage ----
#Usado
dskUSD=$(df -ha --total | grep total | awk '{print $3}')
#Total
dskTOT=$(df -ha --total | grep total | awk '{print $2}')
#Porcentaje
dskPERC=$(df -ha --total | grep total | awk '{print $5}')
# ---- CPU LOAD ----
cpuLOAD=$(top -bn1 | grep '^%Cpu' | xargs | awk '{printf("%.1f%%"), $2 + $4}')
# ---- Ultimo rboot ----
lastBOOT=$(who -b | awk '$1 == "system" {print $3 " " $4}')
#lastBOOT=$(last reboot | sed -n '2p' | awk '{print $6" "$7" "$8}')
# ---- LVM Status -----
lvmSTATUS=$(if ((lsblk | grep lvm | wc -l) > 0); then echo yes; else echo no; fi)
#lvmSTATUS=$(if (lsblk | grep lvm | wc -l > 0); then echo yes; else echo no; fi)
# ---- TCP CON # ----
tcpCONN=$(ss | grep tcp |  wc -l)
# ---- User log ----
userCONT=$(who | wc -l)
# ---- Network ----
#IPV4
ipvc=$(hostname -I)
#MAC
ipvs=$(cat /sys/class/net/*/address | head -n 1)
# ---- Sudo # ----
sudCNT=$(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l)

#OUT
echo "  #Architecture: "$ARC
echo "  #CPU physical: "$pCPU
echo "  #vCPU: "$vCPU
echo "  #Memory Usage: "$memUS"/"$memTO"MB ("$memUPERC")"
echo "  #Disk Usage: "$dskUSD"/"$dskTOT" ("$dskPERC")"
echo "  #CPU load: "$cpuLOAD
echo "  #Last boot: "$lastBOOT
echo "  #LVM use: "$lvmSTATUS
echo "  #Connexions TCP: "$tcpCONN" ESTABLISHED"
echo "  #User log: "$userCONT
echo "  #Network: IP "$ipvc" ("$ipvs")"
echo "  #Sudo: "$sudCNT" cmd"
