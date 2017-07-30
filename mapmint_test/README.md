# Publishing and Sharing Maps with MapMint 

## Installation 
You can install mapmint by following the tutorial which is available in [GitHub](http://mapmint.github.io/userguide-fr/en/introduction/installmapmint.html).
There are few things you need to concern when you are installing the mapmint. Here I mentioned the things I concerned when I was installing mapmint in my server. The first thing is about the version of postgres which you are going to use. The version is defined in the [main.yml](https://github.com/mapmint/ansible-roles/blob/master/ubuntu/dependencies/vars/main.yml) file. You can change it before you run the ansible file. Then you need to edit the Libreoffice version to the latest version. It can be identified by running the [loVersion.sh](https://github.com/mapmint/ansible-roles/tree/master/scripts) script. After you indentfied the latest version of LibreOffice you need to changed the existing version which is mentioned in the ubuntu [main.yml](https://github.com/mapmint/ansible-roles/blob/master/ubuntu/dependencies/vars/main.yml) file under lo_version and in the [debian file](https://github.com/mapmint/ansible-roles/blob/master/debian/dependencies/vars/main.yml) as well. Then you can run the ansible and wait until complete the installation. 

## Start 

Then you can access your MapMint instance by using the following URLs. 

 * Access to administrative modules : http://localhost/ui/Dashboard_bs

 * Access to the public interface : http://localhost/ui/public/

Sometime you may get a 404 error, which means page not found. So, you can restart the apache server and try again. 

