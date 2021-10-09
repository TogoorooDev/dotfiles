autologin
=========

Feel free to post autologin scripts for your favorite site. __Do not forget to
remove your passwords from the script!!!__

* Twitter


    #!/bin/bash
    read -p "Name: " name
    read -p "Password: " -s pass
    echo
    curl --cookie ~/.surf/cookies.txt --cookie-jar ~/.surf/cookies.txt \
        -d "session[username_or_email]=$name" \
        -d "session[password]=$pass" \
        -d "remember_me=1" \
        -d "commit=Sign In" \
        http://twitter.com/sessions > /dev/null
    curl --cookie ~/.surf/cookies.txt --cookie-jar ~/.surf/cookies.txt \
        http://twitter.com/ > /dev/null
    surf http://mobile.twitter.com


Author
------

* Enno Boland (Gottox) < g s01 de >

