# BORN2BEROOT

- Download the latest bebian image and move it to the directory the VM will be installed
 
## USEFUL RESOURCES

- [Download debian](https://www.debian.org/download)

- [Info video playlist](https://www.youtube.com/playlist?list=PLAoA-usw1t-4sIlwNXKS2RIn0ZBx4VQhn)

## TESTERS

- [Tester1](https://github.com/gemartin99/Born2beroot-Tester)

- [Tester2](https://github.com/highrulez/Born2BeRoot-Tester)

## USEFUL COMMANDS

General:
- uname -v
- lsblk
- dpkg -s sudo (which sudo)
- sudo nano /etc/localhost
- sudo visudo
- sudo reboot
- sudo init 0

Ufw & ssh:
- dpkg -s ufw
- sudo ufw status numbered
- sudo systemctl status ufw
- sudo ufw allow <port>
- sudo ufw allow <port num>
- which ssh
- sudo systemctl status ssh

Users & groups:
- sudo adduser <username>
- sudo deluser <user>
- sudo addgroup <groupname>
- sudo groupdel <group>
- sudo adduser <user> <group>
- sudo deluser <user> <group>
- passwd <username>
- getent group <group>

Cron:
- sudo crontab -e
- sudo service cron stop
- sudo service cron start
