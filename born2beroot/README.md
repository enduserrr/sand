# BORN2BEROOT

To start download the latest Debian image and move it to the directory where the VM will be installed.
 
## USEFUL RESOURCES

- [Latest Debian release](https://www.debian.org/download)

- [Info video playlist](https://www.youtube.com/playlist?list=PLAoA-usw1t-4sIlwNXKS2RIn0ZBx4VQhn)

- [Tutorial](https://github.com/gemartin99/Born2beroot-Tutorial)

## TESTERS

- [Tester1](https://github.com/gemartin99/Born2beroot-Tester)

- [Tester2](https://github.com/highrulez/Born2BeRoot-Tester)

## GOOD TO KNOW

Virtual Machine:
A Virtual Machine (VM) is a virtualized computational device created inside a physical computer along with its operating system. The VM utilizes a specified amount of resources partitioned from the physical computer. It has its own operating system and software, functioning as a closed system within a host system. VMs are valuable for testing risky or unstable endeavors and provide the benefit of having multiple different OS environments on a single hardware device. They are cost-effective, versatile, and easily containable.

Aptitude & apt:
Both are package managers. Aptitude is a higher-level package manager compared to apt, offering more robust capabilities and a graphical user interface.

AppArmor:
AppArmor is a security module in the Linux kernel that allows the system admin to restrict the capabilities of a program.

LVM (Logical Volume Manager):
LVM enables easier allocation and management of logical volumes on physical volumes, offering more flexibility than conventional partitioning schemes for storing volumes.

Logical volumes are groups of information from one or more physical volumes, which can be physical storage devices or partitions of physical storage devices.

## USEFUL COMMANDS

General:
- uname -v
- lsblk
- dpkg -s sudo (which sudo)
- sudo nano /etc/localhost
- sudo visudo
- sudo reboot
- sudo init 0

Ufw & SSH:
- dpkg -s ufw
- sudo ufw status numbered
- sudo systemctl status ufw
- sudo ufw allow <port>
- sudo ufw allow <port num>
- which ssh
- sudo systemctl status ssh

Users & Groups:
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