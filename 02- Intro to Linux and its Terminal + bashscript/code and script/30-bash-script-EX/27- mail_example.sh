#!/bin/bash
: '
You can send email by using ‘mail’ or ‘sendmail’ command.
Before using these commands, you have to install 
all necessary packages. 
'
Recipient=”admin@example.com”
Subject=”Greeting”
Message=”Welcome to our site”
`mail -s $Subject $Recipient <<< $Message`