#!/bin/bash

# Install and configure aide daemon for file integrity checking
# This script assumes you have the appropraite permissions to install and configure daemons
# Applies to RHEL based systems, RHEL 7 and older (!RHEL 8, 9)

# variables
$directory = '' #replace quotes with the directory for the database to be created in

# verify that aided is installed
sudo yum install aide

sed 'DBDIR:/var/lib/aide/aide.db.gz'|'DBDIR:'$directory

# Initialize the AIDE database for the first time
echo 'Initializing the AIDE database, this may take some time.'
sudo aide --init

# Create a regular running task to verify file integrity
echo 'Adding AIDE scan to cron'
echo '05 4 * * * root /usr/sbin/aide --check'