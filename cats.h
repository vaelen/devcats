/******
This file is part of devcats.

Copyright 2017, Andrew Young <andrew@vaelen.org>

    Devcats is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

    Devcats is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
along with devcats.  If not, see <http://www.gnu.org/licenses/>.
******/

#include <linux/fs.h> 	     /* file stuff */
#include <linux/kernel.h>    /* printk() */

#ifndef DEV_CATS_DEVCATS_CATS_H
#define DEV_CATS_DEVCATS_CATS_H

static char *cats = ""
        "          ,.                 .,\n"
        "         ,: ':.    .,.    .:' :,\n"
        "         ,',   '.:'   ':.'   ,',\n"
        "         : '.  '         '  .' :\n"
        "         ', : '           ' : ,'\n"
        "         '.' .,:,.   .,:,. '.'\n"
        "          ,:    V '. .' V    :,\n"
        "         ,:        / '        :,\n"
        "         ,:                   :,\n"
        "          ,:       =:=       :,\n"
        "           ,: ,     :     , :,\n"
        "            :' ',.,' ',.,:' ':\n"
        "           :'      ':WW::'   '.\n"
        "          .:'       '::::'   ':\n"
        "          ,:        '::::'    :,\n"
        "          :'         ':::'    ':\n"
        "         ,:           ':''     :.\n"
        "        .:'             '.     ',.\n"
        "       ,:'               ''     '.\n"
        "       .:'               .',    ':\n"
        "      .:'               .'.,     :\n"
        "      .:                .,''     :\n"
        "      ::                .,''    ,:\n"
        "      ::              .,'','   .:'\n"
        "    .,::'.           .,','     ::::.\n"
        "  .:'     ',.       ,:,       ,WWWWW,\n"
        "  :'        :       :W:'     :WWWWWWW,          .,.\n"
        "  :         ',      WWW      WWWWWWWWW          '::,\n"
        "  '.         ',     WWW     :WWWWWWWWW            '::,\n"
        "   '.         :     WWW     :WWWWWWWW'             :::\n"
        "    '.       ,:     WWW     :WWWWWWW'             .:::\n"
        "     '.     .W:     WWW     :WWWWWW'           .,:::'\n"
        "      '.   :WW:     WWW     :WWWWW'      .,,:::::''\n"
        "     .,'   ''::     :W:     :WWWWW.  .,::::''\n"
        "  ,'        ''','',',','','''WWWWW::::''\n"
        "   ':,,,,,,,':  :  : : :  :  :WWWW'''"
        "\n"
        "\n"
        "   ,';,               ,';,\n"
        " ,' , :;             ; ,,.;\n"
        " | |:; :;           ; ;:|.|\n"
        " | |::; ';,,,,,,,,,'  ;:|.|    ,,,;;;;;;;;,,,\n"
        " ; |''  ___      ___   ';.;,,''             ''';,,,\n"
        " ',:   /   \\    /   \\    .;.                      '';,\n"
        " ;    /    |    |    \\     ;,                        ';,\n"
        ";    |    /|    |\\    |    :|                          ';,\n"
        "|    |    \\|    |/    |    :|     ,,,,,,,               ';,\n"
        "|     \\____| __ |____/     :;  ,''                        ;,\n"
        ";           /  \\          :; ,'                           :;\n"
        " ',        `----'        :; |'                            :|\n"
        "   ',,  `----------'  ..;',|'                             :|\n"
        "  ,'  ',,,,,,,,,,,;;;;''  |'                              :;\n"
        ",'  ,,,,                  |,                              :;\n"
        "| ,'   :;, ,,''''''''''   '|.   ...........                ';,\n"
        ";       :;|               ,,';;;''''''                      ';,\n"
        " ',,,,,;;;|.............,'                          ....      ;,\n"
        "           ''''''''''''|        .............;;;;;;;''''',    ':;\n"
        "                       |;;;;;;;;'''''''''''''             ;    :|\n"
        "                                                      ,,,'     :;\n"
        "                                          ,,,,,,,,,,''       .;'\n"
        "                                         |              .;;;;'\n"
        "                                         ';;;;;;;;;;;;;;'"
        "\n"
        "\n"
        "                    .............                .\"\"\".             .\"\"\".    \n"
        "            ...\"\"\"\"\"             \"\"\"\"\"...       $   . \".         .\" .   $    \n"
        "        ..\"\"        .   .   .   .   .    ..    $   $$$. \". ... .\" .$$$   $    \n"
        "      .\"    . \" . \" . \" . \" . \" . \" . \" .  \"\" .\"  $$$\"\"\"  \"   \"  \"\"\"$$$  \".   \n"
        "    .\"      . \" . \" . \" . \" . \" . \" . \" .     $  \"                    \"   $   \n"
        "   .\"   . \" . \" . \"           \"   \" . \" . \"  .\"      ...          ...     \".  \n"
        "  .\"    . \" . \"    ..\"\"\"\"\"\"\"\"\"...     \" . \"  $     .$\"              \"$.    $  \n"
        " .\"     . \" . \" .\"\"     .   .    \"\"..   . \" $ \".      .\"\"$     .\"\"$      .\" $ \n"
        ".\"    \" . \" .       . \" . \" . \" .    $    \" $ \"      \"  $$    \"  $$       \" $ \n"
        "$     \" . \" . \" . \" . \" . \" . \" . \"   $     $             $$.$$             $ \n"
        "$     \" . \" . \" . \" . \" . \" . \" . \" .  $  \" $  \" .        $$$$$        . \"  $ \n"
        "$     \" . \" . \" . \" . \" . \" . \" . \" .  $    $      \"  ..   \"$\"   ..  \"      $ \n"
        "\".    \" . \" . \" . \" . \" . \" . \" . \"   .\"  \"  $  . . . $  . .\". .  $ . . .  $  \n"
        " $    \" . \" . \" . \" . \" . \" . \" . \"  .\"   \"            \"..\"   \"..\"       \n"
        "  $     . \" . \" . \" . \" . \" . \"   ..\"   . \" . \"..    \"             \"    ..\"   \n"
        "  \".      \" . \" . \" . \" . \" .  .\"\"    \" . \" .    \"\"\"$...         ...$\"\"\"      \n"
        "   \". \"..     \" . \" . \" . \" .  \"........  \"    .....  .\"\"\".....\"\"\"            \n"
        "     \". .\"$\".....                       $...\"$\"$\".\"   $\".$\"... `\":....        \n"
        "       \"\"..\"    $\"$\"$\"$\"\"\"$........$\"$\"$\"  .\".\".\"  ...\"\"      .\"\".    `\"\".    \n"
        "           \"\"\".$.$.\" .\"  .\".\".\"    .\".\".\" $.$.$\"\"\"\".......  \". \". $ \". \". $   \n"
        "                  \"\"\".$.$.$.$.....$.$.\"\"\"\"               \"\"..$..$.\"..$..$.\""
        "\n"
        "\n";

#endif //DEV_CATS_DEVCATS_CATS_H
