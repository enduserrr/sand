# BORN2BEROOT

- Download the latest bebian image and move it to the directory the VM will be installed
 
## USEFUL RESOURCES

- [Download debian](https://www.debian.org/download)

- [Info video playlist](https://www.youtube.com/playlist?list=PLAoA-usw1t-4sIlwNXKS2RIn0ZBx4VQhn)

## TESTERS

- [Tester1](https://github.com/gemartin99/Born2beroot-Tester)

- [Tester2](https://github.com/highrulez/Born2BeRoot-Tester)

## GOOD TO KNOW

Virtual Machine:
VM is virtualized computational device created inside a physical computer and it's OS. The vm gets uses a given amount of resources partitioned from the physical computer for the vm. VM has it's own operating system and software as any computer woud. It is a closed system inside a host system, making it useful as a testing environment for risky or unstable endevours as well as giving the user the benefit of having multiple different OS's and digital environments on singular hardware device. >> Cost effective, versatile and easily containable.

Aptitude & apt:
Both are package managers. Unlike apt (lower level) aptitude is a higher level package manager. Compared to apt it has more robust and numerous capabilities as well as graphical user interface.

AppArmor:
Is a security module in the Linux kernel that enables the system admin to restrict what capabilities a program can use.

LVM:
Lvm is short for logical volume manager which enables easier allocation and management of logical volumes on physical volumes. It offers more flexibility compared to conventional partitioning schemes for storing volumes.

Logical volumes are groups of information from one or more physical volumes. Physical volumes can be physical storage devices or partitions of physical storage devices.

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