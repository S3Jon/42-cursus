##### Login as root
apt install sudo
usermod -aG sudo $youruser
groupadd user42
usermod -aG user42 $youruser
exit
##### Login $youruser
sudo apt install ufw
sudo apt install openssh-server
sudo vi /etc/ssh/sshd_config
//uncomment settings
  "#Port 22" -> 4242
  "#PermitRootLogin prohibit-password" -> no
sudo ufw allow 4242
sudo systemctl status sshd
(if you use adapter do "ip a s" ad copy ip)
##### Open local zsh
ssh $youruser@ip -p 4242 (or "ssh $youruser@localhost -p 4242" depending on adapter settings)
sudo vi /etc/login.defs
  PASS_MAX_DAYS  99999 -> 30
  PASS_MIN_DAYS  0 -> 2
sudo apt install libpam-pwquality
sudo vi /etc/security/pwquality.conf - [Linux Die Net](https://linux.die.net/man/5/pwquality.conf)
//uncommnet changed settings
  "# difok = 1" -> 7
  "# minlen = 8" -> 10
  "# dcredit = 0" -> -1
  "# ucredit = 0" -> -1
  "# lcredit = 0" -> -1
  "# maxrepeat = 0" -> 3
  usercheck = 1
  enforce_for_root
