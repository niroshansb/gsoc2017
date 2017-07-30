# Publishing and Sharing Maps with MapMint 

## Installation 
You can install mapmint by following the tutorial which is available in [GitHub](http://mapmint.github.io/userguide-fr/en/introduction/installmapmint.html).
There are few things you need to concern when you are installing the mapmint. I will mentioned the things I concern when I am installing mapmint in my server. The first thing is about the version of postgres which you are going to use. The version is defined in the [main.yml](https://github.com/mapmint/ansible-roles/blob/master/ubuntu/dependencies/vars/main.yml) file. You can change it before you run the ansible file. Then you need to edit the Libreoffice version to the latest version. It can be identified by running the [loVersion.sh](https://github.com/mapmint/ansible-roles/tree/master/scripts) script. 
