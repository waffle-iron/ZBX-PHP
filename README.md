[![Stories in Ready](https://badge.waffle.io/ZenProjects/ZBX-PHP.png?label=ready&title=Ready)](https://waffle.io/ZenProjects/ZBX-PHP)
# Zabbix PHP Loadable Module

This directory contains a [Zabbix Loadable module](https://www.zabbix.com/documentation/3.2/manual/config/items/loadablemodules), which extends functionality of Zabbix
Agent/Server/Proxy. 

# Prerequisite :

The **PHP Embed SAPI - libphp.so** :

How to compile it (the important option are "--enable-embed") :
```
# ./configure --enable-embed --prefix=/path/to/php/install/dir \
		      --with-snmp=shared --with-ldap=shared --enable-shared=yes  \
		      --with-curl=shared  --with-mysqli=shared 
# make
# make install
```
For example to have libphp5.so embeded library with snmp, ldap, curl and mysqli shared module.

# How to Build the module

Compile the zbx_php module with php (the importante option are "--with-php=..."):

```
# ./configure --prefix=/path/to/zabbix/install/dir \
              --enable-server  \
              --with-php=/path/to/php/install/dir
# make
# make install
```	      
It should produce zbx_php.so.

# Configure zbx_php with zabbix

Zabbix agent, server and proxy support two parameters to deal with modules:

- **LoadModulePath** – full path to the location of loadable modules, where to copy zbx_php.so
- **LoadModule** – module(s) to load at startup. The modules must be located in a directory specified by LoadModulePath. It is allowed to include multiple LoadModule parameters.

For example, to extend Zabbix agent we could add the following parameters:

```
	LoadModulePath=/usr/local/lib/zabbix/agent/
	LoadModule=zbx_php.so
```

Upon agent startup it will load the zbx_php.so modules from the /usr/local/lib/zabbix/agent directory. It will fail if a module is missing, in case of bad permissions or if a shared library is not a Zabbix module.

# Zabbix Frontend configuration

Loadable modules are supported by Zabbix agent, server and proxy. Therefore, item type in Zabbix frontend depends on where the module is loaded. If the module is loaded into the agent, then the item type should be “Zabbix agent” or “Zabbix agent (active)”. If the module is loaded into server or proxy, then the item type should be “Simple check”.

- **zbx_php.ping** - always returns '1'
- **zbx_php.version** - returns the php version
- **zbx_php.php[phpscript.php, param1, param2, ...]** - execute phpscript with params

